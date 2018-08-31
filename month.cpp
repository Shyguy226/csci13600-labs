/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mr. Zamanksy
Assignment: Lab1D
*/
#include <iostream>
using namespace std;

int main() {
cout << "Enter year: " << endl;
int year = 0;
cin >> year;
cout << "Enter month: " << endl;
int month = 0;
cin >> month;
if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
  cout << "31 days" << endl;
  }
else if (month==4 || month==6 || month==9 || month==11){
  cout << "30 days" << endl;
  }
else {
  if (year%4==0){
    if (year%100==0 && year%400!=0){
      cout << "28 days" << endl;
      }
    else {
      cout << "29 days" << endl;
      }
    }
  else {
    cout << "28 days" << endl;
    }
  }
  return 0;
}
