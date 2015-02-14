#include <iostream>
#include "llistint.h"
#include <cstdlib>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ ==0;
}
int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  //cases of inserting/removing HEAD/TAIL
  //declarations
  
   //if loc bad RETURN
   if (loc < 0 || loc > size_)
    {
      return;
    }

  //creating the new item to store the new data value
  Item* insertion = new Item();
  insertion->val = val;

  //if the linkedlist is empty
   if (loc == 0 && size_==0 )
  {
    head_ = insertion;
   
    head_->prev = NULL;
    head_->next = NULL;
    tail_ = head_;
     std::cout << "HERE?" << std::endl;
   // tail_->next = NULL;
  //  tail_->prev = insertion;

  }
  
  //creating a head in an already established LL
  else if (loc==0 && size_!=0 )
  {
    head_->prev = insertion; 
    insertion->next = head_;
    insertion->prev = NULL;
    head_ = insertion;

  }

  //creating a standard node
  else if (loc >0 && loc < size_)
  {

    Item* current = getNodeAt(loc);
    Item* temporary = current->prev;
    current->prev = insertion;
    insertion->next = current;
    temporary->next = insertion;
    insertion->prev = temporary;

    
  }
  //creating the tail
  else if (loc == size_)
  {
    tail_->next = insertion;
    insertion->prev = tail_;
    insertion->next = NULL;
    tail_ = insertion;


  }
  
  size_ ++;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{

  //size is 1 set to null
  //if loc is 0
  //if loc is size -1
 if (loc >= size_ || loc < 0) 
    {
      return;
    }

//deleting the whole list
else if (loc == 0 && size_ ==1)
  {
    Item* head_pointer = head_;

    head_ = NULL;
    tail_ = NULL;
    delete head_pointer;
    
    //delete getnodeAt(0);

  }
  //deleting the head
 else if (loc == 0)
    {
    Item* current = head_;
    head_ = current->next;
    head_->prev = NULL;
    delete current;
    }
 //deleting the tail
 else if (loc == size_-1)
  {
    Item* current = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete current;
  }

  //standard deletion
  else 
    { 
  Item* current = getNodeAt(loc);
  Item* previous = current->prev;
  previous->next = current->next;
  delete current;
  
 
    }

size_--;
}

//set a value
void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

//get a value
int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}
//get a value
int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    remove(0);
  }
  tail_ = NULL;
  size_ = 0;
}


void LListInt::push_back(const int& val)
{

  insert(size_,val);
  


}

/**
* Copy constructor
*/
LListInt::LListInt(const LListInt& other)
{

Item* iterator = other.head_;

 
  while (iterator != NULL)
    {
     
      push_back(iterator->val);
      iterator = iterator->next;
    }  

}


/**
* Assignment Operator - already have existing list
*/
LListInt& LListInt::operator=(const LListInt& other)
{

if (this == &other) {return *this;}


  clear();
  Item* iterator = other.head_;
  while (iterator != NULL)
    {
       std::cout << iterator->val << "  " << std::endl;
      std::cout << other.size() << std::endl;
      push_back(iterator->val);
      iterator = iterator->next;
    }  
  return *this;
  
  
}


LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item*temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
