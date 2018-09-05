/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2A

This program takes in a number from the user and then, if the number is between 0 and 100, prints the number squared.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main {
  cout << "Please enter an integer: " << endl;
  int num = 0;
  cin >> num;
  boolean flag = true;
  while (flag){
    if (num > 0 && num < 100){
      flag = false;
      }
    else {
      cout << "Please re-enter: " << endl;
      cin >> num;
      }
    }
  cout << "Number squared is " << pow(num, 2) << endl;
  return 0;
}
