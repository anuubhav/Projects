#include "llistdbl.h"
#include <cstdlib>

LListDbl::LListDbl()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListDbl::~LListDbl()
{
  clear();
}

bool LListDbl::empty() const
{
  return size_ == 0;
}

int LListDbl::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListDbl::insert(int loc, const double& val)
{
  //cases of inserting/removing HEAD/TAIL
  //declarations
  //if loc bad RETURN

  if (loc < 0 || loc > size_)
    {return;
    }


  Item* insertion = new Item();
  insertion->val = val;

  if (loc == 0 && size_==0 )
  {
    head_ = insertion;
    
    head_->prev = insertion;
    head_->next = insertion;
    tail_ = insertion;
    
    tail_->next = insertion;
    tail_->prev = insertion;

  }
  
  else if (loc==0 && size_!=0 )
  {
    head_->prev = insertion;
    insertion->next = head_;
    insertion->prev = NULL;
    head_ = insertion;

  }

  else if (loc >0 && loc < size_)
  {

    Item* current = getNodeAt(loc);
    Item* temporary = current->prev;
    current->prev = insertion;
    insertion->next = current;
    temporary->next = insertion;
    insertion->prev = temporary;

    
  }

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
void LListDbl::remove(int loc)
{

  //size is 1 set to null
  //if loc is 0
  //if loc is size -1
 if (loc >= size_ || loc < 0) 
    {return;}

else if (loc == 0 && size_ ==1)
  {
    head_ = NULL;
    tail_ = NULL;
    delete head_;
    delete tail_;

  }
 else if (loc == 0)
    {
    Item* current = head_;
    head_ = head_->next;
    head_->prev = NULL;
    delete current;
    }

 else if (loc == size_-1)
  {
    Item* current = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete current;
  }

  
  else 
    { 
  Item* current = getNodeAt(loc);
  Item* previous = current->prev;
  previous->next = current->next;
  delete current;
 
    }

size_--;
}

void LListDbl::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

double& LListDbl::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

double const & LListDbl::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListDbl::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
{
  Item *temp = head_;
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
