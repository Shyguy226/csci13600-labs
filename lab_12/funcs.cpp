#include "funcs.h"

#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <locale>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

/*class Profile {
private:
  string username;
  string displayname;
public:
  Profile(string usrn, string dspn);
  Profile();
  string getUsername();
  string getFullName();
  void setDisplayName(string dspn);
  };*/

string Profile::getUsername(){
  return username;
}

string Profile::getFullName(){
  return displayname;
}

void Profile::setDisplayName(string dspn){
  displayname = dspn;
  return;
}

Profile::Profile(string usrn, string dspn){
  username = usrn;
  displayname = dspn;
}

Profile::Profile(){
  username = "";
  displayname = "";
}

/*class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles [MAX_USERS];
  int findID (string usrn);
  bool following[MAX_USERS][MAX_USERS];
public:
  Network();
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1, string usrn2);
  void printDot();
  };*/

int Network::findID(string usrn){
  for (int i = 0; i < MAX_USERS; i++){
    if(profiles[i].getUsername()==usrn)
      return i;
  }
  return -1;
}

Network::Network(){
  numUsers = 0;
  for (int i = 0; i < MAX_USERS; i++){
    for (int j = 0; j < MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

bool Network::addUser(string usrn, string dspn){
  if(numUsers == 20)
    return false;
  for (int i = 0; i < numUsers; i++){
    if(profiles[i].getUsername()==usrn)
      return false;
  }
  for (int i = 0; i < usrn.length(); i++){
    if(!isalnum(usrn[i]))
      return false;
  }
  Profile insert (usrn, dspn);
  if(usrn.length()>0){
    profiles[numUsers]=insert;
  }
  numUsers++;
  return true;
}

bool Network::follow(string usrn1, string usrn2){
  following[findID(usrn1)][findID(usrn2)]=true;
  return true;
}

void Network::printDot(){
  string ans = "digraph {\n  ";
  for (int i = 0; i < numUsers; i++){
    ans+="\"@";
    ans+=profiles[i].getUsername();
    ans+="\"\n  ";
  }
  for(int i = 0; i < MAX_USERS; i++){
    for (int j = 0; j < MAX_USERS; j++){
      if(following[i][j]){
	ans+="\n  \"@";
	ans+=profiles[i].getUsername();
	ans+="\" -> \"@";
	ans+=profiles[j].getUsername();
	ans+="\"";
      }
    }
  }
  ans += "\n}\n";
  cout << ans;
  return;
}
