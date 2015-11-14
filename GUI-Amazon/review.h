#ifndef REVIEW_H
#define REVIEW_H
#include <string>
#include <sstream>

/**
 * Models a review for the product identified by prodName
 */
struct Review
{
  Review() :  prodName(), rating(), date(), reviewText()
  { }
  Review(std::string& prod, 
	 int& rate, 
	 std::string& d, 
	 std::string& review_text) :
    prodName(prod), 
    rating(rate), 
    date(d), 
    reviewText(review_text)
  { }

  void dump(std::ostream& ofile){

    ofile << prodName << "\n" << rating << " " << date << " " << reviewText << "\n";

  }

  std::string getInfo()
  {
  std::stringstream ss;
  ss << rating;
  std::string rating_string = ss.str();
    std::string info = prodName + "\n" + rating_string + " " + date + " " + reviewText + "\n";
    return info;

  }

  std::string getDate()
  {
    return date;


  }
  
  std::string prodName;
  int rating;
  std::string date;
  std::string reviewText;
};

#endif
