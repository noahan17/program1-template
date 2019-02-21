CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: program1
	
lab3: lab3.o Star.o
	g++ $(CFLAGS) lab3.o Star.o -o lab3
lab3.o: lab3.cpp Star.cpp Star.h
	g++ $(CFLAGS) -c lab3.cpp -o lab3.o
Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o
Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
program1: program1.o Vector.o Planet.o
	g++ $(CFLAGS) program1.o Vector.o Planet.o -o program1
program.o: program1.cpp Vector.cpp Vector.h 
	g++ $(CFLAGS) -c program1.cpp -o program.o
Vector: Vector.o Planet.o
	g++ $(CFLAGS) Vector.o Planet.o -o Vector
Vector.o: Vector.cpp Planet.cpp Vector.h
	g++ $(CFLAGS) -c Vector.cpp -o Vector.o

	

run: all
	program1
clean:
	rm -rf program1
	
	

