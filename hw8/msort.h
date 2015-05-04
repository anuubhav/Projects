#ifndef MSORT_H
#define MSORT_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T, class Comparator>
void mergeSort (vector<T>& myArray, Comparator comp)
{
  vector<T> other(myArray);
 
  if (myArray.size() != 1) 
    {
      msort(myArray, 0, myArray.size(), comp);
    }
   
  
}


//helper function
template<class T, class Comparator>
void msort(vector<T>& myArray, int start, int end, Comparator comp)
{
  //base case
	if (start >= end-1) return;
  //if (end-start== 1) return;

 
	//recursive calls
	int mid = (start+end)/2;
	msort(myArray, start, mid, comp);
	msort(myArray, mid, end, comp);
	//merge
	merge(myArray, start, mid, mid, end, comp);

}

template<class T, class Comparator>
void merge(vector<T>& myArray, int s1, int e1, int s2, int e2, Comparator comp)
{



  int start = s1;  vector<T> temp;
 while (s1 < e1 && s2 < e2)
   {
     
      if(comp(myArray[s1], myArray[s2])) 
      {
      
         temp.push_back(myArray[s1++]);  
         
      }
      else
      {
       
         temp.push_back(myArray[s2++]);
      }
      
   }

   while (s1 < e1)
   {
      temp.push_back(myArray[s1++]);  
   }
   
   while (s2 < e2){
      temp.push_back(myArray[s2++]);
   }

for (int i=0; i< temp.size(); i++)
{
  int a = start + i;
  
  myArray[a] = temp[i];


}

}

#endif