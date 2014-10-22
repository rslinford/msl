# CC the compiler
CC=g++
# CFLAGS options passed to compiler
CFLAGS=-c -Wall -g

EXE=dont_run_me

all: clean complexity memory

test:
	./Run_Test_Driver.sh

dont_run_me:
	$(CC) -o$(EXE) Student_Code/*.cpp ignoreme.a

clean:
	rm -rf $(EXE)

complexity: dont_run_me
	pmccabe -v Student_Code/*.h Student_Code/*.cpp
	
memory: dont_run_me
	valgrind --leak-check=full ./$(EXE)

compile:
	$(CC) -oExMan.o Student_Code/*.cpp

