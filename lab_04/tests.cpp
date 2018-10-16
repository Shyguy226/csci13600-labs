#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

TEST_CASE("Divisible By"){
  CHECK(isDivisibleBy(30, 6)==true);
  CHECK(isDivisibleBy(45, 4)==false);
}
TEST_CASE("Is it Prime?"){
  CHECK(isPrime(7)==true);
  CHECK(isPrime(8)==false);
}
TEST_CASE("Next Prime?"){
  CHECK(nextPrime(8)==11);
  CHECK(nextPrime(11)==13);
}
TEST_CASE("Count Primes"){
  CHECK(countPrimes(4, 14)==4);
  CHECK(countPrimes(8, 9)==0);
}
TEST_CASE("Is it a twin prime?"){
  CHECK(isTwinPrime(5)==true);
  CHECK(isTwinPrime(37)==false);
}
TEST_CASE("Next Twin Prime?"){
  CHECK(nextTwinPrime(7)==11);
  CHECK(nextTwinPrime(14)==17);
}
TEST_CASE("Largest Twin Prime"){
  CHECK(largestTwinPrime(4, 15)==13);
  CHECK(largestTwinPrime(8, 9)==-1);
}
