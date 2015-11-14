#include <vector>
#include <string>
#include <iostream>
#include "msort.h"

using namespace std;


struct AlphaStrComp {
    bool operator()(const string& lhs, const string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs < rhs; 
    }
  };

struct LengthStrComp {
    bool operator()(const string& lhs, const string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs.size() < rhs.size(); 
    }
  };


  int main()
  {

    string s1 = "aa";
    string s2 = "ggggg";
    string s3 = "ddd";
    string s4 = "bbbbbbbb";
    vector<string> test;
    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);

    AlphaStrComp comp1;
    LengthStrComp comp2;

    mergeSort(test, comp2);
    for (unsigned int i=0; i<test.size(); i++)
    {
      cout << test[i] << " " << endl;

    } 


    return 0;
  }