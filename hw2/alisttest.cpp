#include "alistint.h"
#include <iostream>
using namespace std;
int main()
{

AListInt * list = new AListInt();

if (list->empty())
	cout << "SUCCESS: You're the man! You made a list" << endl;
else
	cout << "FAIL: Cmon. Try again. Your list is empty." << endl;

list->insert(1,1);
list->insert(2,2);

if (!list->empty())
{ cout << "SUCCESS: Congratulations! Your list has items added to it." << endl;}
else
{ cout << "FAIL: You need to check your code. Your list didn't items added to it." << endl;}

cout << list->get(1) << " is the value for the first number " << endl;
cout << list->get(2) << " is the second value for the second number ok" << endl;

if (list->size() == 2)
{
  cout << "SUCCESS: You did it! Two items were inserted" << endl;
}

else 
{
cout << "FAIL: Your list does not have 2 items. Check your code." << endl;

}
list->set(1, 8);

cout << list->get(1) << " is your new changed value!" << endl;


list->insert(3,3);
list->remove(1);

if (list->get(1) ==2 ) 
{
 cout << "SUCCESS: You successfully deleted an item" << endl;

} 
else
{
cout << "FAILURE: You did not successfully delete an item" << endl;

}

list->set(2,123123123);


if (list->get(2) == 123123123)
	{
		cout << "SUCCESS: You successfully changed value of an item" << endl;
	}
else 
	{
		cout << "FAILURE: You didn't change the value of an item" << endl;

	}


   list->insert(4,4.0);
  list->insert(5,5.0); 
    list->insert(6,6.0);
  list->insert(7,7.0); 
    list->insert(8,8.0);
  list->insert(9,9.0);
  list->insert(10,10.0);

  list->insert(11,11.0);

  if (list->get(11) == 11.0)
  {
  	cout << "SUCCESS: You can add past the list" << endl;

  } 
  else
  {
  	cout << "FAILURE: Your list does not resize" << endl;
  } 

  //delete list;

}