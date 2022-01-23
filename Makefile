#recipes
CC = g++
CFLAGS = -std=c++11 #-Wall

#targets
main: main.o
	$(CC) $(CFLAGS) -o $@ $^

tests: tests.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp MyVector.h MyVector.cxx
	$(CC) $(CFLAGS) -c $<

tests.o: tests.cpp doctest.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *o *out main tests
