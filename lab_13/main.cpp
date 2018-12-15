#include <iostream>
#include <vector>
#include <string>

using std::string;

using std::cout;
using std::endl;
using std::vector;

template <class Type>
class MyVector{
public:
  vector<Type> vect;
  MyVector(Type a, Type b, Type c){
    data[0]=a;
    data[1]=b;
    data[2]=c;
    vect.assign(data, data+3);
  }
  void printem(){
    for (int i = 0; i < data.length(); i++){
      std::cout << data[i] << " ";
    }
    std::cout << "\n";
  }
  Type &get(int i){
    return data[i];
  }
  Type &operator[] (int i){
    return data[i];
  }
  
  void insertAtLoc(Type ins, int place, vector<Type> &vect){
    vect.push_back (ins);
    Type temp = vect[place];
    Type temp2;
    vect[place]=ins;
    for(int i = place+1; i < vect.size(); i++){
      temp2=vect[i];
      vect[i]=temp;
      temp = temp2;
    }
    return;
  }

  void insertAtEnd(Type ins, vector<Type> &vect){
    vect.push_back(ins);
    return;
  }

  void deleteFromLoc (int place, vector<Type> &vect){
    Type temp = vect[vect.size()-1];
    Type temp2;
    for (int i = vect.size()-1; i > place; i--){
      temp2=vect[i-1];
      vect[i-1]=temp;
      temp = temp2;
    }
    vect.pop_back();
    return;
  }
  
  void printData (vector<Type> vect){
    for (int i = 0; i < vect.size(); i++){
      cout << vect[i] << "\t";
    }
    cout << endl;
    return;
  }
private:
  Type data[3];
  //int SIZE = data.size();
  int CAP;
};

int main()
{
  cout << "Start by putting 1776, 7, and 4 in:" << endl;
  MyVector<int> first (1776, 7, 4);
  first.printData(first.vect);
  first.insertAtLoc(50, 1, first.vect);
  cout << "Insert the number 50 at index 1:" << endl;
  first.printData(first.vect);
  first.deleteFromLoc (1, first.vect);
  cout << "Remove index 1:" << endl;
  first.printData(first.vect);
  cout << "Add the number 20 to the end:" << endl;
  first.insertAtEnd(20, first.vect);
  first.printData(first.vect);
  MyVector<string> second ("ryuji", "joker", "Noir");
  cout << "And now with strings:" << endl;
  second.printData(second.vect);
  second.insertAtLoc("panther", 0, second.vect);
  cout << "Insert \"panther\" to index 0:" << endl;
  second.printData(second.vect);
  second.deleteFromLoc(2, second.vect);
  cout << "Delete index 2 from the set:" << endl;
  second.printData(second.vect);
  cout << "Add Lavenza to the end" << endl;
  second.insertAtEnd("Lavenza", second.vect);
  second.printData(second.vect);
}
