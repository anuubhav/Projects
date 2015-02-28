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
//will hold temporary word
string holder;

//go through words and separate into other words
	for (unsigned int i=0; i< rawWord.size(); i++)
	{
		holder.clear();

		if (rawWord[i] == ' ' || ispunct(rawWord[i]))
		{
			holder = rawWord.substr(0,i);
			if (holder.size() >=2)
			{
				words.insert(holder);
				
			}
		//shorten the rest of the string
		rawWord = rawWord.substr(i,rawWord.size()-i);	

		}

	}

//final set
return words;



}
