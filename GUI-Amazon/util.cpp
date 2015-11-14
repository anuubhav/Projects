#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src) 
{
  std::transform(src.begin(), src.end(), src.begin(), ::tolower);
  return src;
}

/** Complete the code to convert a string containing a rawWord 
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWord) 
{
//set of all words
set<string>words;


//start of new word
unsigned int start =0;

//go through words and separate into other words
	for (unsigned int i=0; i< rawWord.size(); i++)
	{
		

		if (i == rawWord.size() -1)
			{

	
				words.insert(rawWord.substr(start));


			}

		else if (rawWord[i] == ' ' || ispunct(rawWord[i]))
		{
			
			
				if (rawWord.substr(start,i-start).size()  >=2)
				{
				words.insert(rawWord.substr(start, i-start));
				}
				
		
		
			start = i+1;
		}

	}

//final set
return words;



}
