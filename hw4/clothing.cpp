#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const string size, const string brand):

Product(category_, name_, price_, qty_),		
  size(size),
  brand(brand)

{

 set<string>::iterator it;

   	set<string> brand_words = parseStringToWords(brand);
	   	for (it = brand_words.begin(); it!=brand_words.end(); ++it)
	   	{	

	    string temp = *it;
	   	string temp_lower = convToLower(temp);
	    keywords_.insert(temp_lower);


		}  


}


set<string> Clothing::keywords() const
{


    return keywords_;



}

 string Clothing::displayString() const
 {

	std::stringstream info;
 	info << name_ << "\n";
 	info << "Brand: " << brand << " " << "Size: " << size << "\n";
 	info << price_ << " " << qty_ << " left" << "\n";

 	string info_string = info.str();
 	return info_string;

 }


 void Clothing::dump(std:: ostream& os) const
{

	 os <<  category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size << "\n" << brand << endl;

}
