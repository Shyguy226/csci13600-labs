/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mr. Zamanksy
Assignment: Lab1C

This program will tell the user if the year they inputted is a leap year.
*/
#include <iostream>
using namespace std;

int main() {
cout << "Please enter a year: " << endl;
int year = 0;
cin >> year;
if (year%4==0){
  if(year%100==0 && year % 400 != 0){
    cout << "Common year" << endl;
    }
  else {
    cout << "Leap year" << endl;
    }
  }
else {
  cout << "Common year" << endl;
  }
}
