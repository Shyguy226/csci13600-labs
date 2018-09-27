#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

std::string minmax(std::string file_name);

int main (){
	std::cout << minmax("Current_Reservoir_Levels.tsv") << std::endl;
	return 0;
}

std::string minmax(std::string file_name){
	double min = 100;
	double max = 0;
	double eastSt;
	std::string date;
	std::ifstream fin(file_name);
	if (fin.fail()){
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
	std::string junk;
	getline(fin, junk);
	while (fin >> date >> eastSt){
		if (eastSt > max){
			max = eastSt;
		}
		if (eastSt < min){
			min = eastSt;
		}
		fin.ignore(INT_MAX, '\n');
	}
	std::cout << "minimum storage in East basin: " << min << " billion gallons\nMAXimum storage in East basin: " << max << " billion gallons" << std::endl;
}
