#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <fstream>
#include <climits>
#include <locale>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::cin;

string removeLeadingSpaces(string line){ //this is actually stripping the spaces
  string ans = "";
  bool flag = true;
  for (int i = 0; i < line.length(); i++){
    if (!isspace(line[i])&&flag){
      ans = line.substr(i);
      flag = false;
    }
  }
  return ans;
}

int countChar(string line, char c){ //this is simply used for countin {'s or }'s
  int ans = 0;
  for (int i = 0; i < line.length(); i++){
    if (line[i]==c)
      ans++;
  }
  return ans;
}

string unindent (string text){
  string ans="";
  string line = "";
  int backN = 0;
  int place = 0; //this and backN keep track of where \n's are
  int counter = 0;
  int open = 0;
  int close = 0;
  bool flag = true;
  for (int i = 0; i < text.length(); i++){
    if(text[i] == '\n'){
      place = i;
      if (countChar(text.substr(backN+1, place-(backN+1)), '}') == 1)
	close++;
      for (int j = 0; j < open-close; j++)
	ans += "\t";
      ans += removeLeadingSpaces(text.substr(backN+1, place-(backN+1))) + "\n";
      open += countChar(text.substr(backN+1, place-(backN+1)), '{');
      backN = place;
    }
  }
  ans += removeLeadingSpaces(text.substr(backN+1));
  return ans;
} 
