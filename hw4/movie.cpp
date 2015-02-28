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


	keywords_.insert(genre);
	info = genre + rating;

}

/*
set<string> Movie::keywords()
{


    set<string> words;

 
   words.insert(genre);

	
  
	
    return words;



}

 string Movie::displayString()
 {

 	string info = genre + rating;
 	return info;

 }

*/
 
 void Movie::dump()
{

	dump();
	cout << genre << endl;
	cout << rating << endl;
}
