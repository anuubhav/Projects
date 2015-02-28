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
	   	string temp = *it;
	   	string temp_lower = convToLower(temp);
	    keywords_.insert(temp_lower);

		}
	
	
    keywords_.insert(ISBN_number);

    

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
