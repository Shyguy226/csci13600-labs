#include <iostream>
#include "funcs.h"

using std::endl;
using std::cout;
using std::string;


int main (){
  cout << test_ascii("101 Dalmations!")  << endl;
  cout << "Enter plaintext\t: Way to Go!\nEnter shift\t: 5\nCiphertext\t: " << caesar("Way to Go!", 5) << "\n" << endl;
  cout << "Enter plaintext\t: Hello, World!\nEnter keyword\t: cake\nCiphertext\t: " << encryptVigenere("Hello, World!", "cake") << "\n" << endl;
  cout << "= Caesar =\nEnter shift\t: 5\nCiphertext\t: Bfd yt Lt!\nDecrypted\t: " << decryptCaesar("Bfd yt Lt!", 5) << "\n" << endl;
  cout << "= Vigenere =\nEnter keyword\t: cake\nCiphertext\t: Jevpq, Wyvnd!\nDecrypted\t: " << decryptVigenere("Jevpq, Wyvnd!", "cake") << endl;
  cout << decryptCaesar("Xqsikpc ewv 3 bquma!", 8) << endl;
}
