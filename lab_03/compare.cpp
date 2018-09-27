#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

std::string compare (std::string date1, std::string date2, std::string file_name);

int main (){
	std::string date1, date2;
	std::cin >> date1;
	std::cin >> date2;
	std::cout << compare(date1, date2, "Current_Reservoir_Levels.tsv") << std::endl;
	return 0;
}

std::string compare(std::string date, std::string date2, std::string file_name){
	bool zone = false;
	std::string ans;
	double garb1, garb2, east, west;
	std::string open;
	std::ifstream fin(file_name);
	std::string junk;
	getline(fin, junk);
	if (fin.fail()){
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
	while (fin >> open >> garb1 >> east >> garb2 >> west){
	  if (open==date){
	    zone = true;
	  }
	  if (zone){
	    ans += open + " ";
	    if (east > west){
	      ans += "East\n";
	    }
	    else if (west > east){
	      ans += "West\n";
	    }
	    else {
	      ans += "Equal\n";
	    }
	  }
	  if (open == date2){
	    zone = false;
	    fin.close();
	  }
	  fin.ignore(INT_MAX, '\n');
	}
	return ans;
}
