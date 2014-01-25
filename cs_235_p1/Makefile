# CC the compiler
CC=g++
# CFLAGS options passed to compiler
CFLAGS=-c -Wall

all: notavirus

notavirus: Main.o student.o grades.o
	$(CC) Main.o student.o grades.o -o notavirus

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

student.o: student.cpp
	$(CC) $(CFLAGS) student.cpp

grades.o: grades.cpp
	$(CC) $(CFLAGS) grades.cpp

clean:
	rm -rf *.o notavirus

test: notavirus
	./notavirus in10a.txt in10b.txt in10c.txt out10.txt
