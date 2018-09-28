#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

std::string reverse_order (std::string file_name);

int main (){
	std::cout << reverse_order("Current_Reservoir_Levels.tsv") << std::endl;
	return 0;
}

std::string reverse_order(std::string file_name){
  std::string date1, date2;
	std::cin >> date1;
	std::cin >> date2;
	double values[365];
	std::string dates[365];
	int counter = 0;
	bool zone = false;
	double garb1, garb2, garb3, west;
	std::string open;
	std::ifstream fin(file_name);
	std::string junk;
	getline(fin, junk);
	if (fin.fail()){
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
	while (fin >> open >> garb1 >> garb2 >> garb3 >> west){
	  if (open==date1){
	    zone = true;
	  }
	  if (zone){
	    values[counter] = west;
		dates[counter] = open;
		counter++;
	  }
	  if (open == date2){
	    zone = false;
	    fin.close();
	  }
	  fin.ignore(INT_MAX, '\n');
	}
	for (int i = counter-1; i >= 0; i--){
	  std::cout << dates[i] + " ";
	  std::cout << values[i];
	  std::cout << "ft\n";
	}
}

