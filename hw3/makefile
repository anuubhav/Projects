all: bin/copytest bin/pgindex

 

bin/llistint.o: llistint.h llistint.cpp 
	g++ -g -Wall -c llistint.cpp -o bin/llistint.o

bin/copytest: bin/.dirstamp LLtest.cpp bin/llistint.o
	g++ -g -Wall LLtest.cpp bin/llistint.o -o bin/copytest

bin/pgindex: bin/.dirstamp pgindex.cpp setint.cpp bin/llistint.o
	g++ -g -Wall pgindex.cpp setint.cpp bin/llistint.o -o bin/pgindex

.PHONY: clean
clean:
	rm -rf bin

bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp
