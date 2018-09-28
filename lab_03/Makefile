Main: main.o
	g++ -o main east-storage.o minmax.o compare.o reverse-order.o
main.o: east-storage.cpp minmax.cpp compare.cpp reverse-order.cpp
	g++ -c east-storage.cpp minmax.cpp compare.cpp reverse-order.cpp
clean:
	rm -f east-storage.o minmax.o compare.o reverse-order.o
help:
	@cat README.org
