
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "movie.h"
#include "clothing.h"
#include "book.h"
#include "datastore.h"
/** 
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 */
class Data: public DataStore {
 public:
  ~Data() { }

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
  void dump(std::ostream& ofile) = 0;

  void keywordMap(& map<string, set<Product*>> kmap);

protected:
std::vector<Product*> items;
std::map<User, std::queue<Product*>> users;
std::map<string, set<Product*>> kmap

};

