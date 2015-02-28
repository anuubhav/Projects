#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Book : public Product{

  public:
  Book(const std::string category, const std::string name, double price, int qty, const std::string authors_name, const std::string ISBN);
  std::set<std::string> keywords() const {return keywords_;}
  std::string displayString() const {return info;}
  void dump();
  

  protected:
  string authors_name;
  string ISBN_number;	
  std::set<std::string> keywords_;
  std::string info;

};
