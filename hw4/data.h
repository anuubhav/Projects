
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
  void addProduct(Product* p) = 0;
 
  /**
   * Adds a user to the data store
   */
  void addUser(User* u) = 0;

  /**
   * Performs a search of products whose keywords match the given "terms"
   *  type 0 = AND search (intersection of results for each term) while
   *  type 1 = OR search (union of results for each term)
   */
  std::vector<Product*> search(std::vector<std::string>& terms, int type) = 0;

  /**
   * Reproduce the database file from the current Products and User values
   */
  void dump(std::ostream& ofile) = 0;


};

