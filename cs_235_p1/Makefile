# CC the compiler
CC=g++
# CFLAGS options passed to compiler
CFLAGS=-c -Wall -g

all: lab1

lab1: Main.o student.o grades.o
	$(CC) Main.o student.o grades.o -o lab1

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

student.o: student.cpp
	$(CC) $(CFLAGS) student.cpp

grades.o: grades.cpp
	$(CC) $(CFLAGS) grades.cpp

clean:
	rm -rf *.o lab1

test: lab1
	./lab1 in10a.txt in10b.txt in10c.txt out10.txt
	./lab1 in11a.txt in11b.txt in11c.txt out11.txt
	./lab1 in12a.txt in12b.txt in12c.txt out12.txt
	./lab1 in15a.txt in15b.txt in15c.txt out15.txt
	./lab1 in16a.txt in16b.txt in16c.txt out16.txt

verify: verify10 verify11 verify12 verify15 verify16

verify10: test
	diff -u Freshout10.txt out10.txt
	
verify11: test
	diff -u Freshout11.txt out11.txt
	
verify12: test
	diff -u Freshout12.txt out12.txt
	
verify15: test
	diff -u Freshout15.txt out15.txt

verify16: test
	diff -u Freshout16.txt out16.txt

complexity:
	pmccabe -v *.h *.cpp
	
memory: lab1
	valgrind --leak-check=full ./lab1 in10a.txt in10b.txt in10c.txt out10.txt
	valgrind --leak-check=full ./lab1 in11a.txt in11b.txt in11c.txt out11.txt
	valgrind --leak-check=full ./lab1 in12a.txt in12b.txt in12c.txt out12.txt
	valgrind --leak-check=full ./lab1 in15a.txt in15b.txt in15c.txt out15.txt
	valgrind --leak-check=full ./lab1 in16a.txt in16b.txt in16c.txt out16.txt
