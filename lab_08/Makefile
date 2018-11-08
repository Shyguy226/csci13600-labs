main: main.o funcs.o
	g++ -std=c++11 -o main main.o funcs.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
funcs.o: funcs.cpp
	g++ -std=c++11 -c funcs.cpp
clean:
	rm -f 
help:
	@cat README.org

