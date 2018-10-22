#pragma once

using std::string;

string test_ascii (string input);
char shiftChar(char c, int rshift);
string caesar(string statement, int rshift);
string encryptVigenere(string plaintext, string keyword);
string encryptCaesar(string plaintext, int rshift);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);
