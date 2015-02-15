all: bin/copytest bin/settest bin/pgindex 

 

bin/llistint.o: llistint.h llistint.cpp LLtest.cpp
	g++ -g -Wall -c llistint.cpp -o bin/llistint.o


bin/setint.o: setint.h setint.cpp 
	g++ -g -Wall -c setint.cpp -o bin/setint.o


bin/copytest: bin/.dirstamp LLtest.cpp bin/llistint.o
	g++ -g -Wall LLtest.cpp bin/llistint.o -o bin/copytest

bin/settest: bin/.dirstamp settest.cpp bin/setint.o
	g++ -g -Wall settest.cpp bin/llistint.o bin/setint.o -o bin/settest

bin/pgindex: bin/.dirstamp pgindex.cpp setint.cpp bin/llistint.o
	g++ -g -Wall pgindex.cpp setint.cpp bin/llistint.o -o bin/pgindex

.PHONY: clean
clean:
	rm -rf bin

bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp
