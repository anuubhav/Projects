#include "hashtable.h"
#include <iostream>

using namespace std;

#define A 54059 
#define B 76963 
#define C 86969 

/**
Hash function for the CS104 hash table.

@param s c-string to hash
@return unsigned int value hashed from the input
*/
int HashTable::hash_str(string passwordInput)
{
	long long password = 0;
	unsigned int digitHolder[4];
	long long iterator =1;

	for (int i=passwordInput.size()-1; i >=0; i--)
	{	
		long long temp = passwordInput[i];
		long long tempLong = temp* iterator;
		password += tempLong;
		iterator *= 128;

	}

	//array of values
	for (int i=0; i< 4; i++)
	{
		digitHolder[3-i] = password % 65521;
		password = password / 65521;
	}

	int finalPassword = (45912 * digitHolder[0] + 35511 * digitHolder[1] + 65169 * digitHolder[2] + 4625 * digitHolder[3]) % 65521;
	return finalPassword;

   
}

/**
Creates a hash table of the given input size. Creates the array and vectors used for the hash table.

@param size The size of the hash table.
*/
HashTable::HashTable(int size) {
	this->size = size;
	data = new vector<pair<string, User* > >*[size];

	for(int i = 0; i < size; i++) {
		data[i] = new vector<pair<string, User*> >;
	}
}

/**
Deletes the vectors and array used for the hash table.
*/
HashTable::~HashTable() {
	for(int i = 0; i < size; i++) {
		delete data[i];
	}
	delete [] data;
}

/**
Puts a string into the hash table

Insert should do nothing if the name already exists in the hash table.

@param: the string to be inserted
@return: void
*/
void HashTable::insert(std::string name, User* user) {
	unsigned hash = hash_str(name);
	hash = hash % size;


	pair<string, User*> pairToInsert;
	pairToInsert = make_pair(name, user);


	// do the rest here!
	if (find(name) == NULL)
	{
		data[hash]->push_back(pairToInsert);

	}
}

/**

Finds if a string exists in the hash table
@param: the string to be inserted
@return: bool, true if the string exists in the hashtable, false if it doesn't
*/
User* HashTable::find(std::string name) {
	// do the rest here!
	unsigned hash = hash_str(name);
	hash = hash % size;
	for (unsigned int i=0; i < data[hash]->size(); i++)
	{
		if (data[hash]->at(i).first == name)
		{
			return data[hash]->at(i).second;
		}
	}
	return NULL;
}

/**

Remove should do nothing if the name does not exist in the hash table.
@param: takes in a string to be removed from the hash table
@return: void
*/

/*
void HashTable::remove(std::string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	// do the rest here!
	if (find(name) == true)
	{
		for (unsigned int i=0; i< data[hash]->size(); i++)
		
		{
			if (data[hash]->at(i) == name)
			{
				data[hash]->erase(data[hash]->begin()+i);

			}

		}
	}
}
*/