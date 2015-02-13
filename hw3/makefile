all: bin/copytest pgindex

 

bin/llistint.o: llistint.cpp llistint.h
	g++ -g -Wall -c llistint.cpp -o bin/llistint.o

bin/copytest: LLtest.cpp bin/llistint.o
	g++ -g -Wall LLtest.cpp llistint.o -o copytest

pgindex: pgindex.cpp
	g++ -g -Wall pgindex.cpp setint.cpp bin/llistint.o -o pgindex

.PHONY: clean
clean:
	rm -rf bin

bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp
