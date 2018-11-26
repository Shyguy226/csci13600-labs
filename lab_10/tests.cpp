#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

TEST_CASE("Basic Functions"){
  CHECK(minutesSinceMidnight({1, 20})==80);
  CHECK(minutesSinceMidnight({11, 45})==705);
  CHECK(minutesUntil({10, 30}, {13, 40})==190);
}
TEST_CASE("Adding Minutes"){
  CHECK(minutesSinceMidnight(addMinutes({8, 10}, 75))==565);
  CHECK(minutesSinceMidnight(addMinutes({15, 20}, 10))==930);
}
/*TEST_CASE("Printing Time Slots"){
  CHECK(printTimeSlot({{"Black Panther", ACTION, 134}, {10, 30}})=="Black Panther ACTION (134 min) [starts at 10:30, ends by 12:44]");
}
*/
/*
TEST_CASE("Scheduling Afterwards"){
  CHECK(scheduleAfter({{"Black Panther", ACTION, 134}, {10, 30}}, {"Back to the Future", COMEDY, 116})=={{"Back to the Future", COMEDY, 116}, {12, 44}});
}
*/
TEST_CASE("Overlapping?"){
  CHECK(timeOverlap({{"Black Panther", ACTION, 134}, {10, 30}}, {{"Back to the Future", COMEDY, 116}, {11,40}})==true);
  CHECK(timeOverlap({{"Black Panther", ACTION, 134}, {10, 30}}, {{"Back to the Future", COMEDY, 116}, {13,40}})==false);
}
