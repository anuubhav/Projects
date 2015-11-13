#ifndef DATA_H
#define DATA_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include "product.h"
#include "user.h"
#include "movie.h"
#include "clothing.h"
#include "book.h"
#include "datastore.h"
#include "util.h"


/** 
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 */
class Data: public DataStore {
 public:
   Data();
  ~Data();

  /**
   * Adds a product to the data store
   */
  void addProduct(Product* p);
 
  /**
   * Adds a user to the data store
   */
  void addUser(User* u);

  /**
   * Performs a search of products whose keywords match the given "terms"
   *  type 0 = AND search (intersection of results for each term) while
   *  type 1 = OR search (union of results for each term)
   */
  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  /**
   * Reproduce the database file from the current Products and User values
   */
  void dump(std::ostream& ofile);

  void keywordMap(map<string, set<Product*> >& kmap);

  void addToCart(string username, Product* item);

  void viewCart(string username);

  vector<Product*> getCart(string username);

  User* getUser(string username);

  void deleteFromCart(User* user, Product* product);
protected:
std::vector<Product*> items;
std::set<User*> userbase;
std::map<string, vector<Product*> > carts;
std::map<string, set<Product*> > kmap;

};
#endif
