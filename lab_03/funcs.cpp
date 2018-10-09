#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>
#include <sstream>
#include "funcs.h"

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
		if (date == "12/31/2016"){
		  fin.close();
		}
			fin.ignore(INT_MAX, '\n');
	}
	std::string string1="minimum storage in East basin: ";
	std::string string2=" billion gallons\nMAXimum storage in East basin: ";
	std::string string3=" billion gallons";
	std::stringstream s;
	s << string1 << min << string2 << max << string3;
	  return s.str();
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

std::string reverse_order(std::string date1, std::string date2, std::string file_name){
	std::stringstream p;
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
	  p << dates[i] + " ";
	  p << values[i];
	  p << "ft\n";
	}
	return p.str();
}
