# CC the compiler
CC=g++
# CFLAGS options passed to compiler
CFLAGS=-c -Wall -g

all: lab2

lab2: Main.o
	$(CC) Main.o -o lab2

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

clean:
	rm -rf *.o lab1

complexity:
	pmccabe -v *.h *.cpp
	
memory: lab1
	valgrind --leak-check=full ./lab2
