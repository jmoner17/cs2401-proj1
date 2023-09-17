# Created by: Nasseef Abukamail
# Modified by Joshua Moner for the CheckingAcct project

# Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and object files.
a.out: checking.o transaction.o date.o commented_main.o
	$(CC) $(CFLAGS) _TEST/checking.o _TEST/transaction.o _TEST/date.o _TEST/commented_main.o -o a.out

checking.o: checking.cc checking.h
	$(CC) -c $(CFLAGS) checking.cc -o _TEST/checking.o

transaction.o: transaction.cc transaction.h
	$(CC) -c $(CFLAGS) transaction.cc -o _TEST/transaction.o

date.o: date.cc date.h
	$(CC) -c $(CFLAGS) date.cc -o _TEST/date.o

commented_main.o: commented_main.cc checking.h transaction.h date.h
	$(CC) -c $(CFLAGS) commented_main.cc -o _TEST/commented_main.o

# Running the tests for CheckingAcct
run_tests: checking.h transaction.h date.h checking.o transaction.o date.o
	$(CC) $(CFLAGS) -I. _TEST/TEST_cases.cc _TEST/checking.o _TEST/transaction.o _TEST/date.o -o _TEST/a.out && ./_TEST/a.out
	sh _TEST/run_tests.sh

# Clean target
clean:
	rm -rf _TEST/*.o a.out _TEST/a.out
