#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
 
 //copy constructor
  LListInt test(*list);
  // Check if the test is still empty.
  if (!test.empty()) {
    cout << "SUCCESS: Copy constructor works for test 1" << endl;
  } else {
    cout << "FAIL: Copy constructor does not work for test 1." << endl;
  }

  // Check if the value is correct.
  if (test.get(0) == 3) {
    cout << "SUCCESS: Copy constructor works for test 2" << endl;
  } else {
    cout << "FAIL: Copy constructor does not work for test 2" << list->get(0);
    cout << " is instead." << endl;
  }

  //assignment operator
 
  LListInt second = *list;
    if (!second.empty()) {
    cout << "SUCCESS: Assignment operator works for test 1" << endl;
  } else {
    cout << "FAIL: Assignment operator does not work for test 1." << endl;
  }

  // Check if the value is correct.
  if (second.get(0) == 3) {
    cout << "SUCCESS: Assignment operator works for test 2" << endl;
  } else {
    cout << "FAIL: Assignment operator does not work for test 2" << list->get(0);
    cout << " is instead." << endl;
  } 

  // Clean up memory.
  delete list;

}