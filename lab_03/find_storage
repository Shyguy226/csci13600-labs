#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

double find_storage(std::string date, std::string file_name);

int main (){
	std::string date;
	std::cin >> date;
	std::cout << find_storage(date, "Current_Reservoir_Levels.tsv") << std::endl;
	return 0;
}

double find_storage(std::string date, std::string file_name) {
  	std::ifstream fin(file_name);
	std::string junk;
	getline(fin, junk);
	if (fin.fail()){
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
	std::string date2;
	double storage;
	while(fin >> date2){
		if (date==date2){
			fin >> storage;
			fin.close();
		}
		fin.ignore(INT_MAX, '\n');
	}
	return storage;
}
