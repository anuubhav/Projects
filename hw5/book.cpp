#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const string author, const string ISBN):

Product(category, name, price, qty)
 

{

 authors_name = author;
  ISBN_number = ISBN;


set<string>::iterator it;

   	set<string> author_words = parseStringToWords(authors_name);
	   	for (it = author_words.begin(); it!=author_words.end(); ++it)
	   	{	
	   	string temp = *it;
	   	string temp_lower = convToLower(temp);
	    keywords_.insert(temp_lower);

		}
	
	
    keywords_.insert(ISBN_number);

    set<string> name_set = parseStringToWords(name);
    for (it = name_set.begin(); it!=name_set.end(); ++it)
	   	{	
	   	string temp = *it;
	   	string temp_lower = convToLower(temp);
	    keywords_.insert(temp_lower);
		}
    

}



set<string> Book::keywords() const
{


return keywords_;

}

 string Book::displayString() const
 {

	std::stringstream info;
 	info << name_ << "\n";
 	info << "Author: " << authors_name << " " << "ISBN: " << ISBN_number << "\n";
 	info << price_ << " " << qty_ << " left" << "\n";

 	string info_string = info.str();
 	return info_string;

 }
 

 void Book::dump(std::ostream& os) const
{

	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_number << "\n" << authors_name << endl;
}
