#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <regex>
#include <StackHelper.cpp>

using namespace std;

//Is the stack empty?
//Signifies end of a block
bool isBalanced(stack<char> balance){
  if(balance.empty() == true){
    return true;
  } else {
    return false;
  }
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

void makeTagFiles(string saveFile){
  string line;
  string tagFileName;
  ifstream gameFile;
  ofstream tagFile;

  string tagBlockStart = "countries={";
  bool countryBlock = false;
  stack<char> balance;
  regex tagFileNameRegex("\\s*(...)\\=\\{");
  smatch match;

  gameFile.open(saveFile);
  if(gameFile.is_open()){
    while(getline(gameFile,line)){
      //Already writing to a tag file?
      if(tagFile.is_open()){
        tagFile << line << endl;
      }
      //Is "country" block being entered
      else if(line.compare(tagBlockStart) == 0){
        countryBlock = true;
      }
      //Is a new tag starting?
      else if(regex_match(line, match, tagFileNameRegex)){
        //Check that no file is currently being worked on and
        //the country code block is being read
        if(countryBlock == true && tagFile.is_open() == false){
          tagFileName = "countries/" + match[1].str() + ".txt";
          tagFile.open(tagFileName);
          tagFile << line << endl;
          cout << "Tag Name: " << tagFileName << endl;
        }
      }

      //Update bracket stack
      updateBalance(line, balance);

      //Ends a tagFile when true
      //Stack size 1 = not in a tag file and in country block
      if(balance.size() == 1){
        tagFile.close();
      }
      else if(isBalanced(balance)){
        if(countryBlock == true){
          countryBlock = false;
        }
      }
    }
  }
  gameFile.close();
}



int main(int argc, char *argv[]){

  string saveFile = "TestData/countries";
  makeTagFiles(saveFile);

  return 0;
}
