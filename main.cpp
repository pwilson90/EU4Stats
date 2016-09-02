#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <regex>

using namespace std;

//Is the stack empty
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

  stack<char> balance;
  regex tagFileNameRegex("(...)\\=\\{$");
  smatch match;

  gameFile.open(saveFile);
  if(gameFile.is_open()){
    while(getline(gameFile,line)){
      if(regex_match(line, match, tagFileNameRegex)){
        if(tagFile.is_open() == false){
          tagFileName = "countries/" + match[1].str() + ".txt";
          tagFile.open(tagFileName);
          cout << "Tag Name: " << tagFileName << endl;
        }
      }
      if(tagFile.is_open()){
        tagFile << line << endl;
      }
      updateBalance(line, balance);

      //Ends a tagFile when true
      if(isBalanced(balance) == true){
        cout << "Parenthesis are balanced.\n";
        tagFile.close();
      }
    }
  }
  gameFile.close();
}

int main(int argc, char *argv[]){

  string saveFile = "earlyTest.eu4";
  makeTagFiles(saveFile);

  return 0;
}
