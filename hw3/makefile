all: llistdbl copytest

llistdbl:
g++ -g -Wall -c llistdbl.cpp -o llistdbl.o

copytest: LLtest.cpp
g++ -g -Wall LLtest.cpp llistdbl.o -o copytest