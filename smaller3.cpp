/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mr. Zamanksy
Assignment: Lab1B

This program accepts three numbers and prints the smallest of the three.
*/
#include <iostream>
using namespace std;

int main() {
cout << “Enter the first number: “ << endl;
int first = 0;
cin >> first;
cout << “Enter the second number: “ << endl;
int second = 0;
cin >> second;
cout << “Enter the third number: “ << endl;
int third = 0;
if(first>second){
  if(second<third){
    cout << "The smaller of the three is " << second << endl;
    }
  else {
    cout << "The smaller of the three is " << third << endl;
    }
  }
else {
  if(first>third){
    cout << "The smaller of the three is " << third << endl;
    }
  else{
    cout << "The smaller of the three is " << first << endl;
    }
  }
return 0;
}
