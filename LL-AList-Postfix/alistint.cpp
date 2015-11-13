#include "alistint.h"
#include <cstdlib>

using namespace std;

AListInt::AListInt()
{
size_ = 0;
capacity = 10;
data = new int[capacity];


}

AListInt::AListInt(int cap)
{



}

AListInt::~AListInt()
{

	delete [] data;

}

int AListInt::size() const
{
return size_;

}

bool AListInt::empty() const
{
	//if the array list is empty
if (size_ ==0)
	{		
		return true;

	}

else
	{
		return false;
	}

}

  /**
   * Inserts val so it appears at index, pos
   */
void AListInt::insert (int pos, const int& val)
{


	//creating the head
	if (pos ==0 && size_ == 0)
	{

		data[0] = val;
		size_++;

	}

	else if (size_ < capacity && pos > 0)
	{	

	//freeing up space to put an int in
	for (int a = size_; a >= pos; a--)
		{
			data[a] = data[a-1];		
		}
	
	data[pos-1] = val;
	size_++;


	}
	//if the position is >= the size
	else if (pos >= size_ && size_ == capacity)
	{
		this->resize();

	//freeing up space to put an int in
	for (int a = size_; a >= pos; a--)
		{
			data[a] = data[a-1];		
		}
	
	data[pos-1] = val;
	size_++;

	}




}

/**
* Removes the value at index, pos
*/
void AListInt::remove (int pos)
{


 //move items to the left to get rid of gaps
 if (pos > 0 && pos <= size_)
	{

	for (int a = pos,  b = a-1; a < size_; a++, b++)

		{
			data[b] = data[a];
		}
	size_--;
	}

}
/**
* Overwrites the old value at index, pos, with val
*/
void AListInt::set (int position, const int& val)
{

data[position-1] = val;


}
/**
* Returns the value at index, pos
*/
int& AListInt::get (int position) 
{

return data[position-1];

}
/**
* Returns the value at index, pos
*/
int const & AListInt::get (int position) const
{

return data[position-1];

}
//if the new item to insert is greater than what the array list can accomodate
void AListInt::resize()
{	

	if (size_ >= capacity)
	{
		//temporary array to hold items
		int*  temp_data = data;
		data = new int[2*capacity];
		for(int i=0; i< capacity; i++)
		{
			data[i] = temp_data[i];
		}
		delete[] temp_data;
		capacity *=2;
	}

}