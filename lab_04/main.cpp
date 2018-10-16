#include <iostream>
#include "funcs.h"

int main (){
	std::cout << isDivisibleBy(100, 25) << "\n" << std::endl;
	std::cout << isPrime(13) << "\n" << std::endl;
	std::cout << nextPrime(14) << "\n" << std::endl;
	std::cout << countPrimes(7, 19) << "\n" << std::endl;
	std::cout << isTwinPrime(7) << "\n" << std::endl;
	std::cout << nextTwinPrime(10) << "\n" << std::endl;
	std::cout << largestTwinPrime(4, 18) << "\n" << std::endl;
}
