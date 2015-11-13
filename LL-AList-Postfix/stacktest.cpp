#include <iostream>
#include "stackdbl.h"
#include "llistdbl.h"
using namespace std;

int main()
{
	StackDbl* stack = new StackDbl;
	stack->push(1);
	stack->push(2);
	/*stack->push(3);
	stack->push(4);
	stack->push(5);
	stack->push(6); */

	if (stack->empty() == true)
	{ 
		cout << "FAILURE: Your stack is still empty. " << endl;
	}
	else 
	{
		cout << "SUCCESS: You have added an item to your stack" << endl;
	}

	if (stack->top() == 2)
	{
		cout << "SUCCESS: You can access the element at the top of your stack" << endl;
	}
	else
	{
		cout << "FAILURE: You cannot access the top element" << endl;
	}

	stack->pop();

	if (stack->top() == 1)
	{
		cout << "SUCCESS: You can pop from the top of your stack" << endl;
	}
	else
	{
		cout << "FAILURE: You cannot pop the top element" << endl;
	} 
	


}