#include "heap.h"
#include <iostream>
#include <functional>

using namespace std;

int main()
{

/*
 Heap<int, less<int> >* h1 = new Heap<int, less<int> >(2, less<int>());
h1->push(0);
h1->push(2123);
h1->push(16);
h1->push(42);
h1->push(1);
h1->push(3);
h1->push(55);
h1->push(2);
h1->push(2116);




for (int i=0; i<9; i++)
{

	cout << i << " number is: " << h1->top() << endl;
	h1->pop();

}

*/

 Heap<int, greater<int> >* h2 = new Heap<int, greater<int> >(5, greater<int>());
h2->push(3);
h2->push(2);
h2->push(3);
h2->push(4);
h2->push(6);
h2->push(1);
h2->push(7);

	cout << "MAX HEAP" << endl;
for (int i=0; i< 7; i++)
{


	cout << i << " number is: " << h2->top() << endl;
	h2->pop();
}




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
}
 
}