#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const string authors_name, const string ISBN):

Product(category_, name_, price_, qty_),		
  authors_name(authors_name),
  ISBN_number(ISBN)

{


    set<string>::iterator it;

   	set<string> author_words = parseStringToWords(authors_name);
	   	for (it = author_words.begin(); it!=author_words.end(); ++it)
	   	{	

	    keywords_.insert(*it);

		}
	
	
    keywords_.insert(ISBN_number);


     info = authors_name + ISBN_number;


}

/*

const set<string> Book::keywords()
{


   
 

    //return keywords_;



}

 const string Book::displayString()
 {

 	string info = authors_name + ISBN_number;
 	return info;

 }
 */

 void Book::dump()
{

	dump();
	cout << authors_name << endl;
	cout << ISBN_number << endl;
}
