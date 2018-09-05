/*
Author: Andrew Giannico
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2C
This program takes in a number from the user and then, if the number is between 0 and 100, prints the number squared.
*/
#include <iostream>

using namespace std;

int main{
  int i = 0;
  int v = 0;
  boolean flag = true;
  int myData[10];
  for (int i = 0; i < 10; i++){
    myData[i]=1;
    }
  do{
    for (int i = 0; i < 10; i++){
      cout << myData[i];
      }
    cout << "\n\nInputIndex: " << endl;
    cin >> i;
    cout << Input Value: " << endl;
    cin >> v;
    if (i < 10 && i > -1){
      myData[i] = v;
      }
    else {
      cout << "\nIndex out of range. Exit." << endl;
      flag = false;
      }
    } while (flag == true);
  return 0;
}
