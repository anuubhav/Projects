#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Clothing : public Product{

  public:
  Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
  std::set<std::string> keywords() const;
  string displayString() const;
  void dump(std::ostream& os) const;
  

  protected:
  string size_;
  string brand_;
  std::set<std::string> keywords_;
  std::string info;

};
#endif