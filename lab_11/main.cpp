#include <iostream>
#include "funcs.h"

using std::endl;
using std::cout;
using std::string;



int main (){
  printRange(-2,10);
  std::cout << sumRange(-2,10) << std::endl;
  int size = 10;
  int *arr = new int [size];
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
  int sum1 = sumArray(arr, size);
  std::cout << "Sum is " << sum1 << std::endl;
  int sum2 = sumArray(arr, 5);
  std::cout << "Sum is " << sum2 << std::endl;
  std::cout << "ABC123 is alphanumeric: " << isAlphanumeric("ABC123") << std::endl;
  std::cout << "ejgfjweh..-- is not alphanumeric: " << isAlphanumeric("ejgfjweh..--") << std::endl;
  std::cout << "(()) is a nested parentheses statement: " <<  nestedParens("(())") << std::endl;
  std::cout << "(((())) is not a nested parentheses statement: " << nestedParens("(((()))") << std::endl;
  return 0;
}
