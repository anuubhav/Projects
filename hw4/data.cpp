#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "data.h"
#include "util.h"
#include <queue> 
#include <map>

using namespace std;
/** 
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 */
  Data::~Data() { 

  }

  /**
   * Adds a product to the data store
   */
  void Data::addProduct(Product* p)
  {
    items.push_back(p);

    set<string> key_holder = p->keywords();
    map<string, set<Product*> >::iterator finder;


    for (set<string>::iterator it=key_holder.begin(); it!=key_holder.end(); ++it)
    {

      finder = kmap.find(*it);
      if (finder == kmap.end())
      {

        kmap.insert(make_pair(*it, p ));




      }

      else
      {

        //kmap[*finder].insert(p);


      }

    }

  }
 
  /**
   * Adds a user to the data store
   */
  void Data::addUser(User* u)
  {

    users.insert(make_pair(u, queue<Product*> cart));


  }

  /**
   * Performs a search of products whose keywords match the given "terms"
   *  type 0 = AND search (intersection of results for each term) while
   *  type 1 = OR search (union of results for each term)
   */


  std::vector<Product*> Data::search(std::vector<std::string>& terms, int type)
  {
    if (type ==0)
    {

    vector<Product*> results;
    set<string> comparison; 

    map<string,set<Product*> >::iterator it;
    set<Product*>::iterator it_set;

    for (it = kmap.begin(); it != kmap.end(); ++it)
    {
      //comparison = it->second.keywords();
      
      
          for (it_set = it->second.begin(); it_set!= it->second.end(); ++it_set)
             { 
              Product * pointer = *it_set;
              comparison = pointer->keywords();      
              if (setIntersection(terms, comparison) == terms)
              {

                results.push_back(pointer);

              }


             }
        
            


      




    }

     

    }

    else if (type ==1)
    {



    }

     return results;

  }

  /**
   * Reproduce the database file from the current Products and User values
   */
  void Data::dump(std::ostream& ofile)
  {





  


  }