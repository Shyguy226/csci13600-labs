#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

using std::string;

string test_ascii (string input){
  string ans = "Input: " + input + "\n\n";
  std::stringstream s;
  s << ans;
  string nextChar = "";
  for(int i = 0; i < input.length(); i++){
    nextChar = input[i];
    s << nextChar << " ";
    s << (int)input[i];
    s << "\n";
  }
  return s.str();
}

char shiftChar(char c, int rshift){
  if (!isalpha(c))
    return c;
  int newer = 0;
  if ((int)c > 64 && (int)c < 91){
    newer = (int)c + rshift;
    if (newer > 90)
      newer -= 26;
    char ans = newer;
    return ans;
  }
  if ((int)c > 96 && (int)c < 123){
    newer = (int)c + rshift;
    if(newer > 122)
      newer -= 26;
    char ans = newer;
    return ans;
  }
}

string caesar(string statement, int rshift){
  string ans = "";
  for (int i = 0; i < statement.length(); i++){
    ans += shiftChar(statement[i], rshift);
  }
  return ans;
}

string encryptVigenere(string plaintext, string keyword){
  int weird = 0;
  int shifts[keyword.length()];
  for (int i = 0; i < keyword.length(); i++){
    shifts[i] = ((int)keyword[i] - 97);
  }
  string ans = "";
  for (int i = 0; i < plaintext.length(); i++){
    ans += shiftChar(plaintext[i], shifts[(i-weird)%keyword.length()]);
    if(!isalpha(plaintext[i]))
      weird++;
  }
  return ans;
}

string encryptCaesar(string plaintext, int rshift){

}

char aShiftChar(char c, int rshift){
  if (!isalpha(c))
    return c;
  int newer = 0;
  if ((int)c > 64 && (int)c < 91){
    newer = (int)c - rshift;
    if (newer < 65)
      newer += 26;
    char ans = newer;
    return ans;
  }
  if ((int)c > 96 && (int)c < 123){
    newer = (int)c - rshift;
    if(newer < 97)
      newer += 26;
    char ans = newer;
    return ans;
  }
}

string decryptCaesar(string ciphertext, int rshift){
  string ans = "";
  for (int i = 0; i < ciphertext.length(); i++){
    ans += aShiftChar(ciphertext[i], rshift);
  }
  return ans;
}

string decryptVigenere(string ciphertext, string keyword){
  int weird = 0;
  int shifts[keyword.length()];
  for (int i = 0; i < keyword.length(); i++){
    shifts[i] = ((int)keyword[i] - 97);
  }
  string ans = "";
  for (int i = 0; i < ciphertext.length(); i++){
    ans += aShiftChar(ciphertext[i], shifts[(i-weird)%keyword.length()]);
    if(!isalpha(ciphertext[i]))
      weird++;
  }
  return ans;
}
