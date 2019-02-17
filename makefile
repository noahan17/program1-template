CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: lab3
	
lab3: lab3.o Star.o
	g++ $(CFLAGS) lab3.o Star.o -o lab3
lab3.o: lab3.cpp Star.cpp Star.h
	g++ $(CFLAGS) -c lab3.cpp -o lab3.o
Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o
Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
run: all
	lab2
clean:
	rm -rf lab2
	
	

