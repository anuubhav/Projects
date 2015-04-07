#include "llistint.h"
#include "setint.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{

	SetInt set;
	set.insert(5);
	set.insert(3);
	set.insert(2);
	set.insert(1);

	SetInt set2;
	set2.insert(3);
	set2.insert(7);
	set2.insert(9);
	set2.insert(1);


	SetInt set3;
	SetInt set4;
	SetInt set5;
	SetInt set6;

	SetInt set7;
	

	set3 = set.setUnion(set2);
	if (!set3.empty() && set3.size() == 6)
	{

		cout << "Test passed! Set Union works." << endl;

 
	}
	else
	{

		cout << "Test failed! Set Union does not work" << endl;

	}

	set5 = set | set2;
	{

		if (!set5.empty() && set5.size() == 6)
		{
			cout << "Test passed! | works as an operator" << endl;
		}

		else
		{

			cout << "Test failed! | does not work as an operator" << endl;

		}

	}


	set4 = set.setIntersection(set2);
	if (!set4.empty() && set4.size() == 2)
	{


		cout << "Test passed! Set intersection works." << endl;


	}

	else
	{
		cout << "Test failed! set intersection does not work" << endl;
	}

	set6 = set & set2;
	if (!set6.empty() && set6.size() == 2)
	{


		cout << "Test passed! & works as an operator." << endl;


	}

	else
	{
		cout << "Test failed! & does not work as an operator" << endl;
	}



	cout << "This is where i lost all the points" << endl;
	cout << set7.empty();
}