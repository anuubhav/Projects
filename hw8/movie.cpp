#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const string genre, const string rating):

Product(category, name, price, qty)
 {


 	
  genre_ = genre;
  rating_ = rating;


 set<string>::iterator it;
string lower_genre = convToLower(genre);
   keywords_.insert(lower_genre);

    
	set<string> name_set = parseStringToWords(name);
    for (it = name_set.begin(); it!=name_set.end(); ++it)
	   	{	
	   	string temp = *it;
	   	string temp_lower = convToLower(temp);
	    keywords_.insert(temp_lower);
		}
}


set<string> Movie::keywords() const
{




 	

	
  
	
    return keywords_;



}

 string Movie::displayString() const
 {
 	std::stringstream info;
 	info << name_ << "\n";
 	info << "Genre: " << genre_ << " " << "Rating: " << rating_ << "\n";
 	info << price_ << " " << qty_ << " left" << "\n";

 	string info_string = info.str();
 	return info_string;

 }


 
 void Movie::dump(std::ostream& os) const
{
 os <<  category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;


	
}
