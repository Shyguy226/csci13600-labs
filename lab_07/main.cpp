#include <iostream>
#include "funcs.h"

using std::endl;
using std::cout;
using std::string;
using std::cin;


int main (){
  string bad = "";
  cin >> bad;
  cout << unindent("                      int main(){\n           // Hi, I'm a program!\nint x = 1;\n    for(int i = 0; i < 10; i++) {\ncout << i;\n           cout << endl;\n }\n     }") << endl;
  return 0;
}
