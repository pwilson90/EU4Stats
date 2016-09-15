#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <regex>
#include "Country.h"

using namespace std;

//Make a namespace for everything until Countries initializers
//EU4 only supports 32 players per game.
string playerArray[32];
int playerArrayCounter = 0;

//stores country objects.
Country countriesArray[500];
int countriesArrayCounter = 0;

stack<char> balance;

//These functions are taken from cplusplus.com
std::string& trim_right_inplace(std::string& s, const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.erase( s.find_last_not_of( delimiters ) + 1 );
}

std::string& trim_left_inplace(std::string& s, const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.erase( 0, s.find_first_not_of( delimiters ) );
}

std::string& trim_inplace(std::string& s, const std::string& delimiters = " \f\n\r\t\v" )
{
  return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}

//Updates stack to track text blocks
void updateBalance(string line, stack<char>& balance){
  int i = 0;
  while(i != line.length()){
    //Find a front brace and put it on the stack
    if(line[i] == '{' || line[i] == '('){
      balance.push(line[i]);
    }
    //Match end brace with proper front brace
    //If properly matched remove the front brace from the stack
    else if(line[i] == '}' || line[i] == ')'){
      if(balance.top() == '{' && line[i] == '}' || balance.top() == '(' && line[i] == ')'){
        balance.pop();
      } else {
        break;
      }
    }
    else {} //Not a bracket
    i++;
  }
}

//Inside Country block.
//Parse into Tag files
void makeTagFiles(ifstream& gameFile, string line){
  string tagFileName;
  ofstream tagFile;

  regex tagFileNameRegex("^\\s*([A-Za-z]{3})=\\{$");
  smatch match;

  if(gameFile.is_open()){
    while(!balance.empty() && getline(gameFile,line)){
      //Already writing to a tag file?
      if(tagFile.is_open()){
        tagFile << line << endl;
      }
      //Is a new tag starting?
      else if(regex_match(line, match, tagFileNameRegex)){
        //Check that no file is currently being worked on and
        //the country code block is being read
        if(tagFile.is_open() == false){
          tagFileName = "Countries/" + match[1].str() + ".txt";
          tagFile.open(tagFileName);
          tagFile << line << endl;
          //cout << "Tag Name: " << tagFileName << endl;
        }
      }

      //Update bracket stack
      updateBalance(line, balance);

      //Ends a tagFile when true
      //Stack size 1 = not in a tag file and in country block
      if(balance.size() == 1){
        tagFile.close();
      } else if(balance.empty()){
        break;
      }
    }
  }
}

void updatePlayerArray(ifstream& gameFile, string line){
  regex tagName("^\\s*\"([A-Za-z]{3})\"$");
  smatch match;

  while(!balance.empty() && getline(gameFile,line)){
    //Technically can overflow array but
    //shouldn't with current game specifications.
    if(regex_match(line, match, tagName)){
      playerArray[playerArrayCounter] = match[1].str();
      playerArrayCounter++;
    }

    updateBalance(line, balance);
  }
}

void parseGameFile(string saveFile){
  string line;
  ifstream gameFile;

  //Move into String folder later.
  string playerNations = "players_countries={";
  string tagBlockStart = "countries={";

  gameFile.open(saveFile);
  if(gameFile.is_open()){
    while(getline(gameFile,line)){
      //Update bracket stack
      updateBalance(line, balance);

      //Gets players for the game
      if (line.compare(playerNations) == 0){
        updatePlayerArray(gameFile, line);
      }
      //Is "country" block being entered
      else if(line.compare(tagBlockStart) == 0){
        makeTagFiles(gameFile, line);
      }
    }
  }
  gameFile.close();
}

void updateCountryTech(ifstream& tagFile, string line, int arrPlacement){
  regex techLevels("\\s*(adm|mil|dip)_tech=([1-9]+)");
  smatch match;

  if(tagFile.is_open()){
    while(balance.size() > 1 && getline(tagFile, line)){
      if(regex_match(line, match, techLevels)){
        if(match[1].str().compare("adm") == 0){
          countriesArray[arrPlacement].setAdminTech(stoi(match[2].str()));
        } else if(match[1].str().compare("dip") == 0){
          countriesArray[arrPlacement].setDiploTech(stoi(match[2].str()));
        } else if(match[1].str().compare("mil") == 0){
          countriesArray[arrPlacement].setMilTech(stoi(match[2].str()));
        }
      }

      updateBalance(line, balance);
    }
  }
}

void updateCountryIncome(ifstream& tagFile,string line,int arrPlacement){
  double incomeArray[16];

  string yearlyIncome = "income={";
  string lastMonthIncome = "lastmonthincometable={";
  regex incomeValue("([0-9]+\\.[0-9]{3})");
  smatch match;

  if(tagFile.is_open()){
    while(balance.size() > 1 && getline(tagFile, line)){
      trim_inplace(line);
      if(line.compare(lastMonthIncome) == 0){

        //push the income={ bracket onto the stack}
        updateBalance(line, balance);

        //pulls the income lists
        getline(tagFile, line);

        for(int i = 0; i < 16; i++){
          regex_search(line, match, incomeValue);
          incomeArray[i] = stod(match[1].str());
          line = match.suffix().str();
        }

        countriesArray[arrPlacement].setTax(incomeArray[0]);
        countriesArray[arrPlacement].setProduction(incomeArray[1]);
        countriesArray[arrPlacement].setTrade(incomeArray[2]);
        countriesArray[arrPlacement].setGold(incomeArray[3]);
        countriesArray[arrPlacement].setTariff(incomeArray[4]);
        countriesArray[arrPlacement].setVassalIncome(incomeArray[5]);
        countriesArray[arrPlacement].setHarborFees(incomeArray[6]);
        countriesArray[arrPlacement].setSubsidies(incomeArray[7]);
        countriesArray[arrPlacement].setWarReparation(incomeArray[8]);
        countriesArray[arrPlacement].setSpoilsOfWar(incomeArray[9]);
        countriesArray[arrPlacement].setCondottieriIncome(incomeArray[10]);
      }

      updateBalance(line, balance);
    }
  }
}

void updateCountryScoreRank(ifstream& tagFile,string line,int arrPlacement){
  double scoreRatingArray[3];

  regex scoreValue("([0-9]+\\.[0-9]{3})");
  smatch match;

  if(tagFile.is_open()){
    //pulls the score list
    getline(tagFile, line);

    for(int i = 0; i < 3; i++){
      regex_search(line, match, scoreValue);
      scoreRatingArray[i] = stod(match[1].str());
      line = match.suffix().str();
    }

    countriesArray[arrPlacement].setAdminRating(scoreRatingArray[0]);
    countriesArray[arrPlacement].setDiploRating(scoreRatingArray[1]);
    countriesArray[arrPlacement].setMilRating(scoreRatingArray[2]);
  }
}

//Country initializers
//Input tag must be a .txt
void countryUpdate(string tag, int arrPlacement){
  string file = "Countries/" + tag + ".txt";
  string line;
  ifstream tagFile;

  string technology = "technology={";
  string ledgerIncome = "ledger={";
  string scoreRank = "score_rating={";
  regex development ("\\s*raw_development=([0-9]+)\\.[0-9]{3}");
  regex maxManpower ("\\s*max_manpower=([0-9]+\\.[0-9]{3})");
  regex maxSailor ("\\s*max_sailors=([0-9]+\\.[0-9]{3})");
  regex score ("\\s*score=([0-9]+\\.[0-9]{3})");
  smatch match;

  string::size_type sz;

  countriesArray[arrPlacement].setName(tag.substr(0,3));

  tagFile.open(file);
  if(tagFile.is_open()){
    while(getline(tagFile, line)){

      trim_inplace(line);
      updateBalance(line, balance);

      if(line.compare(technology) == 0){
        updateCountryTech(tagFile, line, arrPlacement);
      } else if(regex_match(line, match, development)){
        cout << "Development matched: " << match[1].str() << endl;
        countriesArray[arrPlacement].setDevelopment(stoi(match[1].str()));
      } else if(regex_match(line, match, maxManpower)){
        cout << "Manpower matched: " << match[1].str() << endl;
        countriesArray[arrPlacement].setMaxManpower(stod(match[1].str()));
      } else if(regex_match(line, match, maxSailor)){
        cout << "Sailor matched: " << match[1].str() << endl;
        countriesArray[arrPlacement].setMaxSailor(stod(match[1].str()));
      } else if(line.compare(ledgerIncome) == 0){
        cout << "Income matched: " << match[1].str() << endl;
        updateCountryIncome(tagFile, line, arrPlacement);
      } else if(regex_match(line, match, score)){
        cout << "Score matched: " << match[1].str() << endl;
        countriesArray[arrPlacement].setScoreTotal(stod(match[1].str()));
      } else if(line.compare(scoreRank) == 0){
        cout << "Score Rank matched: " << match[1].str() << endl;
        updateCountryScoreRank(tagFile, line, arrPlacement);
      }
    }
  }
  cout << endl;
  tagFile.close();
}

void fillCountryData(){
  countriesArrayCounter = 2;
  for(int i = 0; i < countriesArrayCounter; i++){
    countryUpdate(playerArray[i], i);
  }
}

//Prints out array of counrties
void printCountries(){
  for(int i = 0; i < countriesArrayCounter; i++){
    cout << "Name: " << countriesArray[i].getName() << endl;
    cout << "Adm Tech: " << countriesArray[i].getAdminTech() << endl;
    cout << "Dip Tech: " << countriesArray[i].getDiploTech() << endl;
    cout << "Mil Tech: " << countriesArray[i].getMilTech() << endl;
    cout << "Tech Total: " << countriesArray[i].techTotal() << endl;
    cout << "Development: " << countriesArray[i].getDevelopment() << endl;
    cout << "Max Manpower: " << countriesArray[i].getMaxManpower() << endl;
    cout << "Max Sailor: " << countriesArray[i].getMaxSailor() << endl;
    cout << "Taxation Income: " << countriesArray[i].getTax() << endl;
    cout << "Production Income: " << countriesArray[i].getProduction() << endl;
    cout << "Trade Income: " << countriesArray[i].getTrade() << endl;
    cout << "Gold Income: " << countriesArray[i].getGold() << endl;
    cout << "Tariff Income: " << countriesArray[i].getTariff() << endl;
    cout << "Vassal Income: " << countriesArray[i].getVassalIncome() << endl;
    cout << "Harbor Fees Income: " << countriesArray[i].getHarborFees() << endl;
    cout << "Subsidies Income: " << countriesArray[i].getSubsidies() << endl;
    cout << "War Reparations Income: " << countriesArray[i].getWarReparation() << endl;
    cout << "Spoils of War Income: " << countriesArray[i].getSpoilsOfWar() << endl;
    cout << "Condottieri Income: " << countriesArray[i].getCondottieriIncome() << endl;
    cout << "Total Income: " << countriesArray[i].incomeTotal() << endl;
    cout << "Administration Rating: " << countriesArray[i].getAdminRating() << endl;
    cout << "Diplomatic Rating: " << countriesArray[i].getDiploRating() << endl;
    cout << "Military Rating: " << countriesArray[i].getMilRating() << endl;
    cout << endl;
  }
}

//for Testing, prints out Array of players
void printPlayers(){
    for(int i = 0; i < playerArrayCounter; i++){
      cout << "Player " << i << " is " << playerArray[i] << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[]){

  string saveFile = "TestData/earlyTestFile.eu4";
  parseGameFile(saveFile);

  //For testing, Prints out arrays
  fillCountryData();
  cout << endl;
  printCountries();
  cout << endl;
  //printPlayers();

  return 0;
}
