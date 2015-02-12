#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;
void CreateIndex(char* input, char* output)
{

map<string,int> mymap;
//page number that word is found on
int page = 1;
// string that will hold all the words
string holder = "";
// temporary string to hold current wrod
stringstream str;
string temp;
while (getline(input, holder))
{
	//put temp into stringstream
	str(holder);
	while (holder << temp)
	{
		if (temp == "<pagebreak>")
		{
			page++;

		}
		//if the word is 2 or more characters
		else 
		
		{
			//make temp lowercase
			temp = tolower(temp);
			//getting rid of punctuation
			for (int i=0; i<temp.size(); i++)
			{

				if (ispunct(temp[i]))
				{

					temp.erase(i--, 1)
				}

			}
			//checking that the word  is >=2 characters
			if (temp.size() >=2 )
			{

				mymap.insert(temp, counter);


			}
}


		
		}

	}


}





}