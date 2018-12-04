#include <iostream>
#include "funcs.h"
//#include "funcs.cpp"
using std::endl;
using std::cout;
using std::string;
using std::to_string;


int main (){
  Profile p1("marco", "Marco");
  cout << p1.getUsername() << endl;
  cout << p1.getFullName() << endl;

  p1.setDisplayName("Marco Rossi");
  cout << p1.getUsername() << endl;
  cout << p1.getFullName() << endl;

  Profile p2("tarmal", "Tarma Roving");
  cout << p2.getUsername() << endl;
  cout << p2.getFullName() << endl;

  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;
  cout << nw.addUser("luigi", "Luigi") << endl;

  cout << nw.addUser("mario", "Mario2") << endl;
  cout << nw.addUser("mario 2", "Mario2") << endl;
  cout << nw.addUser("mario-2", "Mario2") << endl;

  for (int i = 2; i < 20; i++)
    cout<< nw.addUser("mario" + to_string(i),
    "Mario" + to_string(i)) << endl;
  
  cout << nw.addUser("yoshi", "Yoshi") << "\n" << endl;
     
  Network nw2;
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");

  nw2.follow("mario", "luigi");
  nw2.follow("mario", "yoshi");
  nw2.follow("luigi", "mario");
  nw2.follow("luigi", "yoshi");
  nw2.follow("yoshi", "mario");
  nw2.follow("yoshi", "luigi");

  nw2.addUser("wario", "Wario");

  for (int i = 2; i < 6; i++){
    string usrn = "mario" + to_string(i);
    string dspn = "Mario " + to_string(i);
    nw2.addUser(usrn, dspn);
    nw2.follow(usrn, "mario");
  }
  nw2.follow("mario2", "luigi");

  nw2.printDot();
}
