#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const string genre, const string rating):

Product(category_, name_, price_, qty_),		
  genre(genre),
  rating(rating)

{

string lower_genre = convToLower(genre);
   keywords_.insert(lower_genre);


}


set<string> Movie::keywords() const
{




 	

	
  
	
    return keywords_;



}

 string Movie::displayString() const
 {
 	std::stringstream info;
 	info << name_ << " " << category_ << "\n";
 	info << "Genre: " << genre << " " << "Rating: " << rating << "\n";
 	info << price_ << " " << qty_ << " left" << "\n";

 	string info_string = info.str();
 	return info_string;

 }


 
 void Movie::dump(std::ostream& os) const
{
 os <<  category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre << "\n" << rating << endl;


	
}
