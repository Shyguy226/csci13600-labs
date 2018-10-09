#include <iostream>
#include "funcs.h"

int main (){
  std::cout << find_storage("02/06/2016", "Current_Reservoir_Levels.tsv") << "\n" << std::endl;
  std::cout << minmax("Current_Reservoir_Levels.tsv") << "\n" << std::endl;
  std::cout << compare("04/15/2016", "04/19/2016", "Current_Reservoir_Levels.tsv") << "\n" << std::endl;
  std::cout << reverse_order("06/07/2016", "06/12/2016", "Current_Reservoir_Levels.tsv") << std::endl;
}
