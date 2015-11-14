## LL/ AList/ Stack Data Structure Implementation in C++

Linked Lists Implementation
To compile: 
g++ -g -Wall testAddToEmptyList.cpp llistdbl.cpp -o testAddToEmptyList

To run:
./testAddToEmptyList

 
Array List Implementation
To compile: 
g++ -g -Wall -c alistint.cpp -o alistint.o
g++ -g -Wall alisttest.cpp alistint.o -o alisttest


To run:
./alisttest


Post Fix Calculator using self-made stack
To compile:
g++ -g -Wall postfix.cpp stackdbl.cpp llistdbl.cpp -o postfix

To run
./postfix postfix.in postfix.out
