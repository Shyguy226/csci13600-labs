/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2D
This program prints the first 60th numbers of the fibonacci sequence.
*/
#include <iostream>

using namespace std;

int main{
  int fib[60];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 60; i++){
    fib[i] = fib[i-2] + fib[i-1];
  }
  for (int i = 0; i < 60; i++){
    cout << fib[i] << endl;
    }
/*
Once the number gets into the billions, it starts becoming incorrect. This is because the data structure of "integer" can only hold so
much room. A proper fix would be to make this an array of a different data structure.
*/
  return 0;
}
