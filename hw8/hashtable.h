#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include "user.h"

/**
Hash Table for CS104 hw 8. Only stores pairs of string/user.
*/
class HashTable {
public:
	HashTable(int);
	~HashTable();

	int hash_str(std::string passwordInput);
	void insert(std::string, User*);
	User* find(std::string);
	//void remove(std::string);


private:
	std::vector<std::pair<std::string, User*> >** data;
	int size;
};

#endif