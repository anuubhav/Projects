#ifndef REVIEW_H
#define REVIEW_H
#include <string>
#include <sstream>

/**
 * Models a review for the product identified by prodName
 */
struct Review
{
  Review() :  prodName(), rating(), username(), date(), reviewText()
  { }

  Review(std::string& prod, 
	 int& rate, 
   std::string& u,
	 std::string& d, 
	 std::string& review_text) :
    prodName(prod), 
    rating(rate), 
    username(u),
    date(d), 
    reviewText(review_text)
  { }

  void dump(std::ostream& ofile){

    ofile << prodName << "\n" << rating << " " << username << " " << date << " " << reviewText << "\n";

  }

  std::string getInfo()
  {
  std::stringstream ss;
  ss << rating;
  std::string rating_string = ss.str();
    std::string info = prodName + "\n" + rating_string + " " + username + " " + date + " " + reviewText + "\n";
    return info;

  }

  std::string getDate()
  {
    return date;


  }
  std::string prodName;
  int rating;
  std::string username;
  std::string date;
  std::string reviewText;
};

#endif
