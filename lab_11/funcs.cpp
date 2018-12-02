#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <locale>

using std::string;

void printRange(int left, int right){
  if(left > right)
    std::cout << std::endl;
  else{
    std::cout << left << " ";
    printRange(left+1, right);
  }
  return;
}

int sumRange(int left, int right){
  if(left > right){
    return 0;
  }
  else{
    return left + sumRange(left+1, right);
  }
  return 0;
}

int sumArrayInRange(int *arr, int left, int right){
  if(left > right){
    return 0;
  }
  else{
    return arr[left] + sumArrayInRange(arr, left+1, right);
  }
  return 0;
}

int sumArray(int *arr, int size){
  int ans = 0;
  ans = sumArrayInRange(arr, 0, size-1);
  return ans;
}

bool alphanum (char c){
  if(isalnum(c))
    return true;
  else
    return false;
}

bool isAlphanumeric(string s){
  if(s.length()==1){
    if(alphanum(s[0]))
      return true;
  }
  if(alphanum(s[0]))
    return isAlphanumeric(s.substr(1));
  else
    return false;
}

bool nestedParens(string s){
  if(s.length()==0){
    return true;
  }
  if(s[0]=='(' && s[s.length()-1]==')'){
    return nestedParens(s.substr(1,s.length()-2));
  }
  else
    return false;
}


