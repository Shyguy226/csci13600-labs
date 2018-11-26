#include <iostream>
#include "funcs.h"

using std::endl;
using std::cout;
using std::string;



int main (){
  Time test{10, 30};
  Time test2{13, 40};
  int a = minutesSinceMidnight(test);
  int b = minutesSinceMidnight(test2);
  int z = minutesUntil(test, test2);
  std::cout << "The moments 10:30 and 13:40 are " << a << " and " << b << " minutes after midnight.\nThe interval between them is " << z << " minutes." << std::endl;
  Time next = addMinutes({8, 10}, 75);
  std::cout << next.h << ":" << next.m << std::endl;
  Movie mv1 = {"Black Panther", ACTION, 134};
  TimeSlot testSlot{mv1, test};
  printTimeSlot(testSlot);
  Movie mv3 = {"Over the Garden Wall", COMEDY, 124};
  printTimeSlot({mv3, {16, 14}});
  Movie mv2 = {"Back to the Future", COMEDY, 116};
  printTimeSlot(scheduleAfter(testSlot, mv2));
  TimeSlot testSlot2{mv2, test2};
  std::cout << timeOverlap(testSlot, testSlot2) << std::endl;
}
