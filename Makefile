#recipes
CC = g++
CFLAGS = -std=c++11 #-Wall

#targets
main: main.o
	$(CC) $(CFLAGS) -o $@ $^

tests: tests.o funcs.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp funcs.h funcs.cxx
	$(CC) $(CFLAGS) -c $<

tests.o: tests.cpp doctest.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f *o *out main tests
