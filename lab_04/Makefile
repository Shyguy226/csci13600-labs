main: main.o funcs.o
	g++ -std=c++11 -o main main.o funcs.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
funcs.o: funcs.cpp
	g++ -std=c++11 -c funcs.cpp
tests: tests.o funcs.o
	g++ -std=c++11 -o tests tests.o funcs.o
tests.o: tests.cpp 
	g++ -std=c++11 -c tests.cpp
clean:
	rm -f isDivisibleBy.o isPrime.o nextPrime.o countPrimes.o isTwinPrime.o nextTwinPrime.o largestTwinPrime.o
help:
	@cat README.org
