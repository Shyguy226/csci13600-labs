#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcs.h"

TEST_CASE("Profile Names"){
  CHECK(Profile {"marco", "Marco"}.getUsername()=="marco");
  CHECK(Profile {"Aerial Ace", "Liam"}.getUsername()=="Aerial Ace");
  CHECK(Profile {"Aerial Ace", "Liam"}.getFullName()=="Liam");
}
TEST_CASE("Adding Users to Network"){
  CHECK(Network{}.addUser("Iskander", "Alexander")==true);
  CHECK(Network{}.addUser("Avery", "Benny")==true);
}
