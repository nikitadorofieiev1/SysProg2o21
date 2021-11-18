all: launcher
launcher: main.o
	g++ main.o -o launcher
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -rf *.o launcher
	