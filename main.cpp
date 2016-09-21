#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <regex>
#include "Country.h"

using namespace std;

void countryUpdate(string tag, int arrPlacement);

//Make a namespace for everything until Countries initializers
//EU4 only supports 32 players per game.
string playerArray[32];
int playerArrayCounter = 0;

//stores country objects.
Country countriesArray[500];
int countriesArrayCounter = 0;

//Unit Arrays, store unit types
string landUnitArray[264] = {"adal_guerilla_warfare", "adal_gunpowder_warfare", "african_clubmen", "african_hill_warfare", "african_spearmen", "african_western_franchise_warfare", "afsharid_reformed_infrantry", "algonkin_tomahawk_charge", "american_western_franchise_warfare", "anglofrench_line", "apache_guerilla", "asian_arquebusier", "asian_mass_infrantry", "asian_musketeer", "austrian_grenzer", "austrian_jaeger", "austrian_tercio", "austrian_white_coat", "aztec_gunpowdwer_warfare", "aztec_hill_warfare", "aztex_tribal_warfare", "bantu_gunpowder_warfare", "bantu_plains_warfare", "bantu_tribal_warfare", "bardiche_infantry", "bhonsle_infrantry", "british_redcoat", "british_square", "chinese_footsoldier", "chinese_longspear", "creek_arquebusier", "durrani_rifled_musketeer", "dutch_maruician", "east_asian_spearmen", "eastern_carabinier", "eastern_medieval_infantry", "eastern_militia", "ethiopian_guerilla_warfare", "ethiopian_gunpowder_warfare", "ethiopian_mountain_warfare", "french_bluecoat", "french_impulse", "gaelic_free_shooter", "gaelic_galloglaigh", "gaelic_mercenary", "germanized_pike", "halberd_infantry", "han_banner", "huron_arquebusier", "inca_mountain_warfare", "incan_axemen", "incan_guerilla_warfare", "incan_slingshots", "indian_arquebusier", "indian_footsoldier", "indian_rifle", "irish_charge", "iroquis_rifle_scout", "iroquois_rifle_scout", "italian_condotta", "japanese_archer", "japanese_footsoldier", "maharathan_guerilla_warfare", "mali_tribal_warfare", "mamluk_archer", "mamluk_duel", "maya_forest_warfare", "maya_guerilla_warfare", "maya_gunpwoder_warfare", "maya_tribal_warfare", "mesoamerican_spearmen", "mexican_guerilla_warfare", "mixed_order_infantry", "mongol_bow", "muscovite_musketeer", "muscovite_soldaty", "muslim_mass_infantry", "napoleonic_square", "native_clubmen", "native_indian_archers", "native_indian_mountain_warfare", "native_indian_tribal_warfare", "niger_kongolese_forest_warfare", "niger_kongolese_guerilla_warfare", "niger_kongolese_gunpowder_warfare", "niger_kongolese_tribal_warfare", "ottoman_azab", "ottoman_janissary", "ottomon_new_model", "ottomon_nizami_cedid", "ottomon_reformed_janissary", "ottomon_sekban", "ottomon_yaya", "persian_footsoldier", "persian_rifle", "persian_shamshir", "peruvian_guerilla_warfare", "polish_musketeer", "polish_tercio", "prussian_drill", "prussian_frederickian", "pueblo_ambush", "rajput_musketeers", "reformed_asian_musketeer", "reformed_mughal_musketeer", "reformed_steppe_rifles", "reformed_westernized_incan", "russian_green_coat", "russian_mass", "russian_pretrine", "saxon_infantry", "scottish_highlander", "sikh_hit_and_run", "songhai_tribal_warfare", "south_american_arqebusier", "south_american_forest_warfare", "south_american_gunpowder_warfare", "south_american_reformed_gunpowder_warfare", "south_american_spearmen", "south_american_warfare", "south_indian_musketeer", "spanish_tercio", "steppe_footmen", "steppe_infantry", "steppe_musketeers", "steppe_raiders", "steppe_rifles", "swedish_caroline", "swedish_gustavian", "swiss_landsknechten", "tipu_sultan_rocket", "tofongshis_musketeer", "western_longbow", "western_medieval_infantry", "western_men_at_arms", "westernized_adal", "westernized_aztec", "westernized_bantu", "westernized_ethiopian", "westernized_incan", "westernized_mayan", "westernized_niger_kongolese", "westernized_south_american", "westernized_zapotec", "zapotec_gunpowder_warfare", "zapotec_plains_warfare", "zapotec_tribal_warfare", "zulu_chest_and_horns", "african_abyssinian_cavalry", "african_abyssinian_light_cavalry", "african_cuirassier", "african_dragoon", "african_hussar", "african_mandelaku", "african_mossi_horsemen", "african_somali_cavalry", "african_swarm", "african_tuareg_cavalry", "afsharid_reformed", "ali_bey_reformed_infrantry", "asian_charge_cavalry", "austrian_hussar", "bhonsle_cavalry", "british_hussar", "central_american_dragoon", "central_american_horsemen", "central_american_hussar", "central_american_rifle_cavalry", "central_american_swarm", "chevauchee", "chinese_dragoon", "chinese_steppe", "commanche_swarm", "druzhina_cavalry", "durrani_dragoon", "durrani_swivel", "east_mongolian_steppe", "eastern_bow", "eastern_knights", "eastern_skimisher", "eastern_uhlan", "french_carabinier", "french_caracolle", "french_cuirassier", "french_dragoon", "hungarian_hussar", "indian_archers", "indian_elephant", "indian_shock_cavalry", "japanese_samurai", "maharathan_cavalry", "mamluk_cavalry_charge", "mamluk_musket_charge", "manchu_banner", "mongol_bow", "mongol_mansabdar", "mongol_steppe", "mongol_swarm", "mughal_musketeer", "muscovite_caracolle", "muscovite_cossack", "muslim_cavalry_archers", "muslim_dragoon", "napoleonic_lancers", "native_indian_horsemen", "north_american_dragoon", "north_american_horsemen", "north_american_hussar", "north_american_rifle_cavalry", "north_american_swarm", "open_order_cavalry", "ottomon_lancer", "ottomon_musellem", "ottomon_reformed_spahi", "ottomon_spahi", "ottomon_timariot", "ottomon_toprakli_dragoon", "ottomon_toprakli_hit_and_run", "persian_cavalry_charge", "polish_hussar", "polish_winged_hussar", "prussian_uhlan", "qizilbash_cavalry", "rajput_hill_fighters", "reformed_asian_cavalry", "reformed_manchu_rifle", "reformed_mughal_mansabdar", "russian_cossack", "russian_cuirassier", "russian_lancer", "shaybani", "shwarze_reiter", "sikh_rifle", "sioux_dragoon", "slavic_stradioti", "south_american_dragoon", "south_american_horsemen", "south_american_hussar", "south_american_rifle_cavalry", "south_american_swarm", "steppe_cavalry", "steppe_lancers", "steppe_mounted_raiders", "steppe_riders", "steppe_uhlans", "swedish_arme_blanche", "swedish_gallop", "tartar_cossack", "topchis_artillery", "western_medieval_knights", "zaporoghian_coassack", "chambered_demi_cannon", "coehorn_mortar", "culverin", "flying_battery", "houfnice", "large_cast_bronze_mortar", "large_cast_iron_bombard", "leather_cannon", "pedrero", "royal_mortar", "small_cast_iron_bombard", "swivel_cannon"};
string navalUnitArray[25] = {"carrack", "early_carrack", "galleon", "threedecker", "twodecker", "wargalleon", "barque", "caravel", "early_frigate", "frigate", "great_frigate", "heavy_frigate", "archipelago_frigate", "chebeck", "galiot", "galleass", "galley", "merchantman", "war_galley", "brig", "cog", "eastindiaman", "flute", "trabakul"};

int landUnitArraySize = 264;
int navalUnitArraySize = 25;

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
void makeTagFiles(ifstream& gameFile, string line, stack<char>& balance){
  string tagFileName;
  ofstream tagFile;

  regex tagFileNameRegex("^\\s*([A-Za-z0-9]{3})=\\{$");
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

void updatePlayerArray(ifstream& gameFile, string line, stack<char>& balance){
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

  //Stack to keep paranthesis balanced
  stack<char> balance;

  gameFile.open(saveFile);
  if(gameFile.is_open()){
    while(getline(gameFile,line)){
      trim_inplace(line);
      //Update bracket stack
      updateBalance(line, balance);

      //Gets players for the game
      if (line.compare(playerNations) == 0){
        updatePlayerArray(gameFile, line, balance);
      }
      //Is "country" block being entered
      else if(line.compare(tagBlockStart) == 0){
        makeTagFiles(gameFile, line, balance);
      }
    }
  }
  gameFile.close();
}

void updateCountryTech(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
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

void updateCountryIncome(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
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

void updateCountryScoreRank(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
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

void updateCountryRegiment(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
  string armyType;
  bool foundType = false;

  regex unitType("\\s*type=\"(.*)\"");
  regex unitStrength("\\s*strength=([0|1]\\.[0-9]{3})");
  smatch match;

  if(tagFile.is_open()){
    while(balance.size() > 2 && getline(tagFile, line)){
      if(regex_match(line, match, unitType)){
        for(int i = 0; i < landUnitArraySize; i++){

          //Infantry is 0-147
          //Calvary is 148-251
          //Artillery 252-263, as of patch 1.17.x
          if(match[1].str().compare(landUnitArray[i]) == 0 && i < 148){
            armyType = "infantry";
            foundType = true;
            break;
          } else if(match[1].str().compare(landUnitArray[i]) == 0 && i >= 148 && i < 252){
            armyType = "cavalry";
            foundType = true;
            break;
          } else if(match[1].str().compare(landUnitArray[i]) && i > 252){
            armyType= "artillery";
            foundType = true;
            break;
          }
        }
      } else if(regex_match(line, match, unitStrength) && foundType == true){
        countriesArray[arrPlacement].armyCounter(armyType, stod(match[1].str()));
      }

      updateBalance(line, balance);
    }
  }
}

void updateCountryArmy(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
  string regiment = "regiment={";

  if(tagFile.is_open()){
    while(balance.size() > 1 && getline(tagFile, line)){
      trim_inplace(line);
      updateBalance(line, balance);
      if(line.compare(regiment) == 0){
        updateCountryRegiment(tagFile, line, arrPlacement, balance);
      }
    }
  }
}

void updateCountrySubject(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance){
  regex tag("\"([A-Z]{3})\"");
  smatch match;

  if(tagFile.is_open()){
    while(balance.size() > 1 && getline(tagFile, line)){
      trim_inplace(line);
      updateBalance(line, balance);
      if(regex_match(line, match, tag)){
        countriesArray[arrPlacement].addSubject(match[1].str());
        countryUpdate(match[1].str(), countriesArrayCounter);
        countriesArrayCounter++;
      }
    }
  }
}

void updateCountrySubjectValues(int arrPlacement){
  double infantry = 0;
  double cavalry = 0;
  double artillery = 0;
  int bigShip = 0;
  int lightShip = 0;
  int galley = 0;
  int transport = 0;

  //Subject for loop, i = subject value
  for(int i = 0; i < countriesArray[arrPlacement].getSubjectArrayCount(); i ++){
    //Country for loop, j = country value. Looking for the subject's object
    for(int j = 0; j < countriesArrayCounter; j ++){
      if(countriesArray[j].getName().compare(countriesArray[arrPlacement].getSubjectName(i)) == 0){
        infantry += countriesArray[j].getInfantry();
        cavalry += countriesArray[j].getCavalry();
        artillery += countriesArray[j].getArtillery();
        bigShip += countriesArray[j].getBigShip();
        lightShip += countriesArray[j].getLightShip();
        galley += countriesArray[j].getGalley();
        transport += countriesArray[j].getTransport();
        break;
      }
    }
  }

  countriesArray[arrPlacement].setSubjectArmy(infantry, "infantry");
  countriesArray[arrPlacement].setSubjectArmy(cavalry, "cavalry");
  countriesArray[arrPlacement].setSubjectArmy(artillery, "artillery");
  countriesArray[arrPlacement].setSubjectNavy(bigShip, "bigShip");
  countriesArray[arrPlacement].setSubjectNavy(lightShip, "lightShip");
  countriesArray[arrPlacement].setSubjectNavy(galley, "galley");
  countriesArray[arrPlacement].setSubjectNavy(transport, "transport");
}

void updateCountryDevelopment(ifstream& tagFile, int dev, int arrPlacement, stack<char>& balance){
  countriesArray[arrPlacement].setDevelopment(dev);
}

//Country initializers
//Input tag must be a .txt
void countryUpdate(string tag, int arrPlacement){
  string file = "Countries/" + tag + ".txt";
  string line;
  ifstream tagFile;

  string::size_type sz;
  string technology = "technology={";
  string ledgerIncome = "ledger={";
  string scoreRank = "score_rating={";
  string army = "army={";
  string subject = "subjects={";

  regex development ("\\s*raw_development=([0-9]+)\\.[0-9]{3}");
  regex maxManpower ("\\s*max_manpower=([0-9]+\\.[0-9]{3})");
  regex maxSailor ("\\s*max_sailors=([0-9]+\\.[0-9]{3})");
  regex score ("\\s*score=([0-9]+\\.[0-9]{3})");
  smatch match;

  //Stack to keep paranthesis balanced
  stack<char> balance;

  countriesArray[arrPlacement].setName(tag.substr(0,3));
  //countriesArrayCounter++;

  tagFile.open(file);
  if(tagFile.is_open()){
    while(getline(tagFile, line)){

      trim_inplace(line);

      //this updateBalance will catch any matching statements bracket
      //Do not add the bracket within the secondary function also
      updateBalance(line, balance);

      if(line.compare(technology) == 0){
        updateCountryTech(tagFile, line, arrPlacement, balance);
      } else if(regex_match(line, match, development)){
        updateCountryDevelopment(tagFile, stoi(match[1].str()), arrPlacement, balance);
      } else if(regex_match(line, match, maxManpower)){
        countriesArray[arrPlacement].setMaxManpower(stod(match[1].str()));
      } else if(regex_match(line, match, maxSailor)){
        countriesArray[arrPlacement].setMaxSailor(stod(match[1].str()));
      } else if(line.compare(ledgerIncome) == 0){
        updateCountryIncome(tagFile, line, arrPlacement, balance);
      } else if(regex_match(line, match, score)){
        countriesArray[arrPlacement].setScoreTotal(stod(match[1].str()));
      } else if(line.compare(scoreRank) == 0){
        updateCountryScoreRank(tagFile, line, arrPlacement, balance);
      } else if(line.compare(army) == 0){
        updateCountryArmy(tagFile, line, arrPlacement, balance);
      } else if(line.compare(subject) == 0){
        //Updates a tag's subject array and creates the subjects object.
        updateCountrySubject(tagFile, line, arrPlacement, balance);
        updateCountrySubjectValues(arrPlacement);
      }
    }
  }
  //cout << endl;
  tagFile.close();
}

void fillCountryData(){
  countriesArrayCounter = playerArrayCounter;
  for(int i = 0; i < playerArrayCounter; i++){
    countryUpdate(playerArray[i], i);
  }
}

void printCountry(int i, ofstream& output){
  if(output.is_open()){
    output << "Name: " << countriesArray[i].getName() << endl;
    output << "Adm Tech: " << countriesArray[i].getAdminTech() << endl;
    output << "Dip Tech: " << countriesArray[i].getDiploTech() << endl;
    output << "Mil Tech: " << countriesArray[i].getMilTech() << endl;
    output << "Tech Total: " << countriesArray[i].techTotal() << endl;
    output << "Development: " << countriesArray[i].getDevelopment() << endl;
    output << "Max Manpower: " << countriesArray[i].getMaxManpower() << endl;
    output << "Max Sailor: " << countriesArray[i].getMaxSailor() << endl;
    output << "Taxation Income: " << countriesArray[i].getTax() << endl;
    output << "Production Income: " << countriesArray[i].getProduction() << endl;
    output << "Trade Income: " << countriesArray[i].getTrade() << endl;
    output << "Gold Income: " << countriesArray[i].getGold() << endl;
    output << "Tariff Income: " << countriesArray[i].getTariff() << endl;
    output << "Vassal Income: " << countriesArray[i].getVassalIncome() << endl;
    output << "Harbor Fees Income: " << countriesArray[i].getHarborFees() << endl;
    output << "Subsidies Income: " << countriesArray[i].getSubsidies() << endl;
    output << "War Reparations Income: " << countriesArray[i].getWarReparation() << endl;
    output << "Spoils of War Income: " << countriesArray[i].getSpoilsOfWar() << endl;
    output << "Condottieri Income: " << countriesArray[i].getCondottieriIncome() << endl;
    output << "Total Income: " << countriesArray[i].incomeTotal() << endl;
    output << "Administration Rating: " << countriesArray[i].getAdminRating() << endl;
    output << "Diplomatic Rating: " << countriesArray[i].getDiploRating() << endl;
    output << "Military Rating: " << countriesArray[i].getMilRating() << endl;
    output << "Infantry Amount: " << countriesArray[i].getInfantry() << endl;
    output << "Cavalry Amount: " << countriesArray[i].getCavalry() << endl;
    output << "Artillery Amount: " << countriesArray[i].getArtillery() << endl;
    output << "Army Strength Total: " << countriesArray[i].armyStrengthTotal() << endl;
    output << countriesArray[i].getName() << " subjects: " << endl;
    countriesArray[i].printSubjects(output);
    output << "Subject Infantry: " << countriesArray[i].getSubjectArmy("infantry") << endl;
    output << "Subject Cavalry: " << countriesArray[i].getSubjectArmy("cavalry") << endl;
    output << "Subject Artillery: " << countriesArray[i].getSubjectArmy("artillery") << endl;
    output << "Subject Army Total: " << countriesArray[i].getSubjectArmyTotal() << endl;
    output << "Subject Big Ships: " << countriesArray[i].getSubjectNavy("bigShip") << endl;
    output << "Subject Light Ships: " << countriesArray[i].getSubjectNavy("lightShip") << endl;
    output << "Subject Galleys: " << countriesArray[i].getSubjectNavy("galley") << endl;
    output << "Subject Transports: " << countriesArray[i].getSubjectNavy("transport") << endl;
    output << "Subject Navy Total: " << countriesArray[i].getSubjectNavalTotal() << endl;
    output << endl;
  }
}

//Prints out all country object information
void printCountries(){
  ofstream output;
  output.open("TestData/output.txt");
  if(output.is_open()){
    for(int i = 0; i < countriesArrayCounter; i ++){
      printCountry(i, output);
    }
  }
}

//for Testing, prints out Array of players
void printPlayers(){
  for(int i = 0; i < playerArrayCounter; i++){
    cout << "Player " << i << " is " << playerArray[i] << endl;
  }
}

int main(int argc, char *argv[]){

  string saveFile = "TestData/testFile.eu4";
  parseGameFile(saveFile);

  //For testing, Prints out arrays
  fillCountryData();
  cout << endl;
  printCountries();
  cout << endl;
  //printPlayers();

  return 0;
}
