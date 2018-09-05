/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mr. Zamanksy
Assignment: Lab1A
This program will receive two numbers and print the smaller of the two.
*/
#include <iostream>
using namespace std;

int main() {
cout << "Enter the first number: " << endl;
int first = 0;
cin >> first;
cout << "Enter the second number: " << endl;
int second = 0;
cin >> second;
if (first > second){
  cout << "The smaller of the two is " << second << endl;
}
else {
  cout << "The smaller of the two is " << first << endl;
}
return 0;
}
