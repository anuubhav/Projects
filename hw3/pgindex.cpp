#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include "setint.h"

using namespace std;
int main(int argc, char* argv[])
{
//IOSTREAM stuff
ifstream in_file;
ofstream out_file;
in_file.open(argv[1]);
out_file.open(argv[2]);



map<string,SetInt*> mymap;
//page number that word is found on
int page = 1;
// string that will hold all the words
string holder = "";
// temporary string to hold current wrod
stringstream str;
string temp;
SetInt* set = new SetInt();
	while (getline(in_file, holder))
	{
		//put holder into stringstream
		str.str(holder);

		while (str >>  temp)
		{
			if (temp == "<pagebreak>")
			{
				page++;

			}
			
			else 
			
			{
				//make temp lowercase
				//transform(temp.begin(), temp.end(), temp.begin(), tolower);
				//getting rid of punctuation
				for (unsigned int i=0; i<temp.size(); i++)
				{

					if (ispunct(temp[i]))
					{

						temp.erase(i--, 1);
					}

				}
				//checking that the word  is >=2 characters
				if (temp.size() >=2 )
				{
					if (mymap.find(temp) !=  mymap.end())
					{
					set->insert(page);
					mymap.insert(make_pair(temp, set));
					}

					else
					{

					mymap[temp]->insert(page);	

					}

				}
			}
			
		}

	}


	
	for (map<string, SetInt*>::iterator it = mymap.begin(); it!= mymap.end(); ++it)
	{
	cout << it->first << " : " << "{";
		for (int j=0; j< it->second->size(); j++)  
		{
		cout << it->second->first() << ",";
		while (it->second->next()) { cout << it->second->next();}
		}

		
 		cout << endl;
	} 






}
