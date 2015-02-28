#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const string size, const string brand):

Product(category_, name_, price_, qty_),		
  size(size),gory, const std::string name, double price, int qty, const string si
  brand(brand)

{

 set<string>::iterator it;gory, const std::string name, double price, int qty, const string si

   	set<string> brand_words = parseStringToWords(brand);
	   	for (it = brand_words.begin(); it!=brand_words.end(); ++it)
	   	{	

	    keywords_.insert(*it);
gory, const std::string name, double price, int qty, const string si
		}  gory, const std::string name, double price, int qty, const string si
	info = size + brand;


}

/*
set<string> Clothing::keywords()
{


    set<string> words;
	 set<string>::iterator it;
>>


   	set<string> brand_words = parseStringToWords(brand);
	   	for (it = brand_words.begin(); it!=brand_words.end(); ++it)
	   	{	
>

	    words.insert(*it);

		}  
	

    return words;



}

 string Clothing::displayString()
 {

 	string info = size + brand;
 	return info;

 }
*/
 void Clothing::dump()
{

	dump();
	cout << size << endl;
	cout << brand << endl;>

}
