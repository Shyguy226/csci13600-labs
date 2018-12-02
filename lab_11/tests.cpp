#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

/*int size = 10;
int arr = new int [size];
arr[0] = 12;
arr[1] = 17;
arr[2] = -5;
arr[3] = 3;
arr[4] = 7;
arr[5] = -15;
arr[6] = 27;
arr[7] = 5;
arr[8] = 13;
arr[9] = -21;
*/

TEST_CASE("Sum of all numbers in range"){
  CHECK(sumRange(-2, 6)==18);
  CHECK(sumRange(9, 12)==42);
}
/*TEST_CASE("Sum of elements in array"){
  CHECK(sumArray(arr, size)==43);
  CHECK(sumArray(arr, 5)==34);
}
*/
TEST_CASE("Is it alphanumeric"){
  CHECK(isAlphanumeric("ABc123")==true);
  CHECK(isAlphanumeric("--aa--")==false);
}
TEST_CASE("Nested Parentheses?"){
  CHECK(nestedParens("((()))")==true);
  CHECK(nestedParens("(()")==false);
}
