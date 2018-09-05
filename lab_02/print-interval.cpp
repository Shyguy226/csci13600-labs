/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2B
This program takes in a number from the user representing the upper limit an another representing the lower limit, then it prints all 
numbers between the two.
*/
#include <iostream>

using namespace std;

int main {
  cout << "Please enter L: " << endl;
  int l = 0;
  cin >> l;
  cout << "Please enter U: " << endl;
  int u = 0;
  cin >> u;
  cout << "/n" << endl;
  for (int i = l; i < u; i++){
    cout << i << " ";
    }
  return 0;
}
