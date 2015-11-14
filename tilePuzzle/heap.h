#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, typename Comparator >
class Heap
{
 public:
  /// Constructs an m-ary heap for any m >= 2
  Heap(int m, Comparator c);

  /// Destructor as needed
  ~Heap();

  /// Adds an item
  void push(const T& item);

  /// returns the element at the top of the heap 
  ///  max (if max-heap) or min (if min-heap)
  T const & top() const;

  /// Removes the top element
  void pop();

  /// returns true if the heap is empty
  bool empty() const;

  ///makes an array into a heap
  void heapify(int index);

  //pushes into the right spot
  void trickleUp(int index);

  void printVector();

 private:
  /// Add whatever helper functions and data members you need below
 	std::vector<T> heap_;
 	Comparator comp;
 	int m; //for the m-ary tree



};

// Add implementation of member functions here
template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap() 
{}


template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c)
{
	this->m = m;
	//this->comp = c;
	comp=c;
}




template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item)
{


	heap_.push_back(item);
	trickleUp(heap_.size()-1);


}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
T const & Heap<T,Comparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::logic_error("can't top an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heap_.front();


}

template <typename T, typename Comparator>
void Heap<T,Comparator>::heapify(int index) 
{

	if ((heap_.size()> m*index+1))
	{

		int newChild = m * index + 1; //leftmost child
		for (int i=2; i<= m; i++)
		{
			if (m*index + i < heap_.size())
			{
				int rChild = m*index + i;
				if (comp(heap_[rChild], heap_[newChild]))
				{
					newChild = rChild;

				}
			}
		}

		if (comp(heap_[newChild],heap_[index]))
		{
			std::swap(heap_[index], heap_[newChild]);
			heapify(newChild);

		}

	}
}


template <typename T, typename Comparator>
void Heap<T,Comparator>::trickleUp(int index) 
{

	int parent = (index-1) / m;
	while (parent >= 0 && comp(heap_[index],heap_[parent]))
	{
		std::swap(heap_[parent], heap_[index]);
		index = parent;
		parent = (index-1) / m;

	}

}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
void Heap<T,Comparator>::pop()
{
  if(empty()){
    throw std::logic_error("can't pop an empty heap");
  }



  heap_[0] = heap_.back();
  heap_.pop_back();
  heapify(0);

/*
  std::cout << "after pop:";
	printVector();
	std::cout << std::endl;
*/
}

template <typename T, typename Comparator>
bool Heap<T,Comparator>::empty() const
{

	return (heap_.size() ==0);

}

template <typename T, typename Comparator>
void Heap<T,Comparator>::printVector()
{

	for (int i=0; i< heap_.size(); i++)
	{
		std::cout << heap_[i] << " ";

	}

}


#endif

