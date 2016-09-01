#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

stack<char> balance;//not being passed right

bool isBalanced(stack<char> balance){
  if(balance.empty() == true){
    return true;
  } else {
    return false;
  }
}

void updateBalance(string line, stack<char>& balance){
  int i = 0;
  while(i != line.length()){
    cout << line[i];
    if(line[i] == '{' || line[i] == '('){
      balance.push(line[i]);
    }
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

int main(int argc, char *argv[]){
  string line;
  ifstream gameFile;
  ofstream tagFile;

  gameFile.open ("earlyTest.txt");
  tagFile.open ("tagFile.txt");
  if(tagFile.is_open()){
    if(gameFile.is_open()){
      while(getline(gameFile,line)){
        tagFile << line << endl;
        cout << line << endl;
        updateBalance(line, balance);
        if(isBalanced(balance) == true){
          cout << "Parenthesis are balanced. End text file here.\n";
        }
      }
    }
  }

  gameFile.close();
  tagFile.close();

  return 0;
}
