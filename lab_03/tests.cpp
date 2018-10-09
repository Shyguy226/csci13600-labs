#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

TEST_CASE("Find East Storage"){
  CHECK(find_storage("01/06/2016", "Current_Reservoir_Levels.tsv")==72.11);
  CHECK(find_storage("03/17/2016", "Current_Reservoir_Levels.tsv")==73.35);
}
TEST_CASE("Mininum Maximum"){
  CHECK(minmax("Current_Reservoir_Levels.tsv")=="minimum storage in East basin: 49.34 billion gallons\nMAXimum storage in East basin: 81 billion gallons");
}
TEST_CASE("Comparisons"){
  CHECK(compare("01/30/2016", "02/02/2016", "Current_Reservoir_Levels.tsv")=="01/30/2016 East\n01/31/2016 East\n02/01/2016 East\n02/02/2016 East\n");
 }
TEST_CASE("Reverse"){
  CHECK(reverse_order("03/06/2016", "03/10/2016", "Current_Reservoir_Levels.tsv")=="03/10/2016 585.78ft\n03/09/2016 586.01ft\n03/08/2016 586.31ft\n03/07/2016 586.59ft\n03/06/2016 586.87ft\n");
}
