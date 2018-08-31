/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mr. Zamanksy
Assignment: Lab1B
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
cout << "Enter the third number: " << endl;
int third = 0;
cin >> third;
if(first > second && second > third){
  cout << "The smaller of the three is " << third << endl;
}
else if(first > second && second < third){
  cout << "The smaller of the three is " << second << endl;
}
else if (first < second && second > third{
  cout << "The smaller of the three is " << first << endl;
}
else if (first > third){
  cout << "The smaller of the three is " << third << endl;
}
else {
  cout << "The smaller of the three is " << first << endl;
}
return 0;
}
