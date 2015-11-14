#include "heap.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
srand(time(NULL));

 Heap<int, less<int> >* h2 = new Heap<int, less<int> >(4, less<int>());
for (int i=0; i < 100; i++)
{
	int j= rand() % 1000;
	h2->push(j);


}


	cout << "MIN HEAP" << endl;
for (int i=0; i< 100; i++)
{


	cout << i << " number is: " << h2->top() << endl;
	h2->pop();
}


/*

 Heap<int, less<int> >* h3 = new Heap<int, less<int> >(5, less<int>());
h3->push(3);
h3->push(2);
h3->push(4);
h3->push(3);
h3->push(6);
h3->push(1);
h3->push(7);

cout << "MIN HEAP" << endl;
for (int j=0; j< 7; j++)
{


	cout << j << " number is: " << h3->top() << endl;
	h3->pop();
}*/
 
}