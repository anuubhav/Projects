#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include "setint.h"
#include <stdio.h>
#include <string.h>

using namespace std;
void hyphen(string fullstring, int position, map<string, SetInt*> &mymap, int page);
void helper(string temp_one, string temp_two, int page, map<string, SetInt*> &mymap);
void index(string temp, int page, map<string, SetInt*> &mymap);



void hyphen(string fullstring, int position, map<string, SetInt*> &mymap, int page)
{

	fullstring.erase(position,1);
	int beginning = 0;
	int ending = position;
	string temp_one = fullstring.substr(beginning,ending);
	beginning = position;
	string temp_two = fullstring.substr(beginning);	

	index(temp_one, page, mymap);
	index(temp_two, page, mymap);
}




void index(string temp, int page, map<string, SetInt*> &mymap)
{


			//hyphen position
			int position =0;
			//checking if the word has started from front
			//bool front_letter = false;
			//checking if word has started from back
			//bool back_letter = false;

			//make temp lowercase
			for (unsigned int i=0; i< temp.size(); i++)
			{

				temp[i] = tolower(temp[i]);


			}

			//getting rid of puncutation at beginning
			while (ispunct(temp[0]))
			{

				temp= temp.substr(1,temp.size()-1);



			}


			//getting rid of puncutation at end
			while (ispunct(temp[temp.size()-1]))
			{

				temp = temp.substr(0,temp.size()-1);


			}


			//check for puncutation in the string
			for (unsigned int i=0; i<temp.size(); i++)
			{
			
				if (ispunct(temp[i])) 
				{
					if (temp[i] != '-')
					{ 
						temp.clear();
						
					}
				}

			} 
			//if temp has a hyphen
			for (unsigned int i=0; i< temp.size(); i++)
				{

					if (temp[i] == '-')
					{
						position = i;
						

					}

			//if there is a hyphen
			
			for (unsigned int i=0; i< temp.size(); i++)
			{
				if (temp[i] == '-')
				{
					position = i;
					hyphen(temp, position, mymap, page);
				}

			}		

				}
				


			//checking that the word  is >=2 characters
			if (temp.size() >=2 && position == 0)
			{
				//if temp is not already in the map
				map<string,SetInt*>::iterator it_two = mymap.find(temp);
				if (it_two == mymap.end())
					{
						SetInt* set = new SetInt();
						set->insert(page);
						mymap.insert(make_pair(temp, set));
					}

				
				//if temp is in the map, change value
				else
					{

					(it_two->second)->insert(page);	

					}
			}
		
		 		

	

}

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


	while (!in_file.eof())
	{
		// string that will hold all the words
		string holder = "";
		// temporary string to hold current wrod
		stringstream str;
		string temp;
		getline(in_file, holder);
		//put holder into stringstream
		str << holder;

		while (!str.eof())
		{
			str >> temp;
	
			if (temp == "<pagebreak>")
			{
				page++;
				continue;
			}
			
			index(temp, page, mymap);
		
		}
		
	}

	for (int i=3; i<argc; i++)
	{
		for (unsigned int j=0; j< strlen(argv[i]); j++)
				{

					argv[i][j] = tolower(argv[i][j]);


				}
	}

	 for (int i=3; i<argc; i++)
	{

		map<string, SetInt*>::iterator it = mymap.find(argv[i]);

		if (it == mymap.end()) 
		{
			out_file << "None" << endl;

		}
	

		else 
		{ 

			out_file << *((it->second)->first());
			for (int i =0; i < it->second->size()-1; i++)
				{

				out_file << " " << *((it->second)->next());

					
				}
				out_file << endl;
		}
		
	} 



	//DEALLOCATE ALL MEMORY
	map<string, SetInt*>::iterator it_delete;
	for (it_delete = mymap.begin(); it_delete != mymap.end(); ++it_delete)
	{

		delete it_delete->second;

	}

} 
	







