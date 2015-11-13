#include <iostream>
#include "stackdbl.h"
#include "llistdbl.h"

using namespace std;


  StackDbl::StackDbl()
  {


  }
  StackDbl::~StackDbl()
  {


  }
  /**
   * Returns true if the stack is empty, false otherwise
   */
  bool StackDbl:: empty() const
  {

   return list_.empty();
  }

  /**
   * Pushes a new value, val, onto the top of the stack
   */
  void StackDbl::push(const double& val)
  {

       list_.insert(list_.size(), val);
       
  }

  /**
   * Returns the top value on the stack
   */
  const double & StackDbl::top() const
  {

      return list_.get(list_.size()-1);
  }

  /**
   * Removes the top element on the stack
   */
  void StackDbl::pop()
  {
    list_.remove(list_.size()-1);
  
    
  }


  
