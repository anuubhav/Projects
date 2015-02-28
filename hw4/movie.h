#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std;

class Movie : public Product{

  public:
  Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
  std::set<std::string> keywords() const;
  string displayString() const;
  void dump(std::ostream& os) const;
  

  protected:
  string genre;
  string rating;
  std::set<std::string> keywords_;
  std::string info;

};
