#ifndef FUNCS_H
#include <string>
using namespace std;
//using std::string;

class Profile {
private:
  string username;
  string displayname;
public:
  Profile(string usrn, string dspn);
  Profile();
  string getUsername();
  string getFullName();
  void setDisplayName(string dspn);
};

class Network {
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
};
/*
string getUsername();
string getFullname();
void setDisplayName(string dspn);
int findID(string usrn);
bool Network(string usrn, string dspn);
bool Network(string usrn1, string usrn2);
void printDot();
*/
#endif
