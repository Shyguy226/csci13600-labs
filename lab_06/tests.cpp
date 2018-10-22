#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

TEST_CASE("ASCii Codes"){
  CHECK(test_ascii("600 words")=="Input: 600 words\n\n6 54\n0 48\n0 48\n  32\nw 119\no 111\nr 114\nd 100\ns 115\n");
  CHECK(test_ascii("ROM hack")=="Input: ROM hack\n\nR 82\nO 79\nM 77\n  32\nh 104\na 97\nc 99\nk 107\n");
}
TEST_CASE("Caesar Encryption"){
  CHECK(caesar("Pikachu won 3 times!", 8)=="Xqsikpc ewv 3 bquma!");
  CHECK(caesar("I have to poop", 18)=="A zsnw lg hggh");
}
TEST_CASE("Vigenere Encryption"){
  CHECK(encryptVigenere("Don't assassinate Limekiller", "please")=="Szr't swhlwsarpei Laqtvmldig");
  CHECK(encryptVigenere("You'll have a bad time", "sans")=="Qoh'dd hnnw a osv tvew");
}
TEST_CASE("Decryption"){
  CHECK(decryptCaesar("Xqsikpc ewv 3 bquma!", 8)=="Pikachu won 3 times!");
  CHECK(decryptVigenere("Qoh'dd hnnw a osv tvew", "sans")=="You'll have a bad time");
}
