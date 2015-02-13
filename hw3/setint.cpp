#include "setint.h"
//#include "llistint.h"
#include <cstdlib>

using namespace std;
   SetInt::SetInt()
   {

	access = 0;

   }

  /**
   * Destructor
   */
  SetInt::~SetInt()
  {



  }

  /**
   * Returns the current number of items in the list 
   */
  int SetInt::size() const
  {
  		return list_.size();
  }

  /**
   * Returns true if the list is empty, false otherwise
   */
  bool SetInt::empty() const
  {

  	return list_.empty();

  }

  /**
   * Inserts val into the set, do nothing if val already exists
   */
  void SetInt::insert(const int& val)
  {
  	//checking if the number already exists in the set 
  	bool ok = true;
  	int nsize_ = list_.size();
  	for (int i=0; i < nsize_; i++)
  		{

  			if (list_.get(i) == val)
  				{ok = false;}


  		}
  	//if the number isn't already in the set
	if (ok == true)
	{

		list_.push_back(val);

	}

  }

  /**
   * Removes the value at index, pos
   */
  void SetInt::remove(const int& val)
  {
  	//checking if the number exists
	bool ok = false;
	int position = 0;
  	int size_ = list_.size();
  	for (int i=0; i < size_; i++)
  		{

  			if (list_.get(i) == val)
  			position = i;
  			ok = true;
  			break;	


  		}

  	//if the number is in the set
	if (ok == true)
	{

		list_.remove(position);

	}

  }

  /**
   * Returns true if the item is in the set
   */
  bool SetInt::exists(const int& val) const
  {
	bool ok = false;
  	int size_ = list_.size();
  	for (int i=0; i < size_; i++)
  		{

  			if (list_.get(i) == val)
  				{ok = true;}


  		}

  	//the item is in the set
	if (ok == true) return true;

	//the item is not in the set
	else return false;


  }

  /**
   * Return a pointer to the first item
   *  and support future calls to next()
   */
  int const* SetInt::first()
  {
  	//allowing next() to be used
  	access = 1;
  	return &list_.get(0);
  }

  /**
   * Return a pointer to the next item
   *  after the previous call to next
   *  and NULL if you reach the end
   */
  int const* SetInt::next()
  {
  	if (access >0 )
  	{
  		access++;
  		if (access == list_.size()+1) {return NULL;} 
  		else {return &list_.get(access-1);}
  	}

  	else return NULL;

  
  	
  }

  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
  SetInt SetInt::setUnion(const SetInt& other) const
  {

   SetInt a(*this);
   for (int i=0; i<other.size(); i++)
   {
    a.insert(other.list_.get(i));
   }

   return a;
    
  } 

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
   SetInt SetInt::setIntersection(const SetInt& other) const
  {
  SetInt a = SetInt();

    for (int i=0; i < this->size(); i++)
    {
        
        if (this->exists(other.list_.get(i)))
        {
          a.insert(other.list_.get(i));

        }

      

    }

    return a;


  } 

  SetInt SetInt::operator|(const SetInt& other) const
  {

   SetInt a(*this);
   for (int i=0; i<other.size(); i++)
   {
    a.insert(other.list_.get(i));
   }

   return a;

  }
  SetInt SetInt::operator&(const SetInt& other) const
  {

    SetInt a = SetInt();

    for (int i=0; i < this->size(); i++)
    {
        
        if (this->exists(other.list_.get(i)))
        {
          a.insert(other.list_.get(i));

        }

      

    }

    return a;
  }