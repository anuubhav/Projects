#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "review.h"
#include "user.h"
#include "data.h"
#include "util.h"
#include <queue> 
#include <map>
#include <list>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
/** 
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 */
 Data::Data(char* input) :
    items(),
    userbase(),
    carts(),
    kmap()
 {


    if (input[0] == '1')
    {
      users = new HashTable(283);

    }

  


 }
  Data::~Data() { 

for (unsigned int i=0; i< items.size(); i++)
{

    delete items[i];

}

std::set<User*>::iterator s;

for (s = userbase.begin(); s != userbase.end(); ++s)
{

    delete *s;

}

  }

  /**
   * Adds a product to the data store
   */
  void Data::addProduct(Product* p)
  {
    items.push_back(p);
    set<string> key_holder = p->keywords();

    //map<string, set<Product*> >::iterator finder;


    for (set<string>::iterator it=key_holder.begin(); it!=key_holder.end(); ++it)
    {

     // finder = kmap.find(*it);
      
      if (kmap.find(*it) == NULL)
      //if (finder == kmap.end())
      {


        //products that match the keyword
        set<Product*> matching_products;
        matching_products.insert(p);
        kmap.insert(make_pair(*it, matching_products));

      }

      else
      {
    
        kmap.find(*it)->getItem().second.insert(p);


      }

    }

  }
 
  /**
   * Adds a user to the data store
   */
  void Data::addUser(User* u)
  {
    vector<Product*> cart;
    userbase.insert(u);
    carts.insert(make_pair(u->getName(), cart));

    users->insert(u->getName(), u);



  }

  /**
   * Performs a search of products whose keywords match the given "terms"
   *  type 0 = AND search (intersection of results for each term) while
   *  type 1 = OR search (union of results for each term)
   */


  std::vector<Product*> Data::search(std::vector<std::string>& terms, int type)
  {

    //final results in vector form
    vector<Product*> results;
    
    //the results in set form
    set<Product*> s_results;

    //to go through the map in general
    set<string>::iterator it;
    

    //to go through the map and find keywords
    map<string,set<Product*> >::iterator it_map;


    //to help transform set to vector
    set<Product*>::iterator it_set;

    //set to hold searched keywords 
    set<string> k_set;

    set<Product*>::iterator itTwo;
    map<string, set<Product*> >::iterator smapIt;


    if (type ==0)
    {
        for (unsigned int i=0; i < terms.size(); i++)
        {

            if (i==0)
            {
                smapIt = smap.find(terms[i]);

                if (smapIt != smap.end() && kmap.find(terms[i]) != NULL)
                {
                   s_results = kmap.find(terms[i])->getValue();
                   
                   for (itTwo = smapIt->second.begin(); itTwo != smapIt->second.end(); ++itTwo)
                   {
                    s_results.insert(*itTwo);

                   }

                }
                else if (smapIt != smap.end())
                {
                  s_results = smapIt->second;  
      

                }
                
                else
                {
              
                if (kmap.find(terms[i]) != NULL)
                  {
                    s_results = kmap.find(terms[i])->getValue();
                  }
                }
               
               
            }

                //past the first search term
                else 
            {
            
                set<Product*> temp;
                  smapIt = smap.find(terms[i]);

                  if (smapIt != smap.end() && kmap.find(terms[i]) != NULL)
                {
                   temp = kmap.find(terms[i])->getValue();
                  
                   for (itTwo = smapIt->second.begin(); itTwo != smapIt->second.end(); ++itTwo)
                   {
                    temp.insert(*itTwo);

                   }

                }
                else if (smapIt != smap.end())
                {
                 temp = smapIt->second;  
                }
                
                else
                {
                  if (kmap.find(terms[i]) != NULL)
                  {
                temp = kmap.find(terms[i])->getValue();
              }
                }
                s_results = setIntersection(s_results, temp);
              
            }
        }

    
         
        

    }
    

      else if (type ==1)
    {


    for (unsigned int i=0; i < terms.size(); i++)
        {

            if (i==0)
            {
                smapIt = smap.find(terms[i]);

                if (smapIt != smap.end() && kmap.find(terms[i]) != NULL)
                {
                   s_results = kmap.find(terms[i])->getValue();
                  
                   for (itTwo = smapIt->second.begin(); itTwo != smapIt->second.end(); ++itTwo)
                   {
                    s_results.insert(*itTwo);

                   }

                }

                else if (smapIt != smap.end())
                {
                  s_results = smapIt->second;  
         
                }
                
                else
                {
             
            if (kmap.find(terms[i]) != NULL)
                  {s_results = kmap.find(terms[i])->getValue();
                  }
                }
            }

            else 
            {
                set<Product*> temp;
                  smapIt = smap.find(terms[i]);
                
                if (smapIt != smap.end() && kmap.find(terms[i]) != NULL)
                {
                   temp = kmap.find(terms[i])->getValue();
                  
                   for (itTwo = smapIt->second.begin(); itTwo != smapIt->second.end(); ++itTwo)
                   {
                    temp.insert(*itTwo);

                   }

                }

                if (smapIt != smap.end())
                {
                   temp = smapIt->second;  
                }
                
                else
                {
                  if (kmap.find(terms[i]) != NULL)
                  {
                 temp = kmap.find(terms[i])->getValue();
               }
                }
                s_results = setUnion(s_results,  temp);
              
            }
        }

    }
             
    //make the results set into a vector
    for (it_set = s_results.begin(); it_set!= s_results.end(); ++it_set)
    {


        results.push_back(*it_set);


    }
     return results;

  }

  /**
   * Reproduce the database file from the current Products and User values
   */
  void Data::dump(std::ostream& ofile)
  {
        ofile << "<products>" << "\n";
        for (unsigned int i=0; i< items.size(); i++)
        {

            items[i]->dump(ofile);

        }
        ofile << "</products>" << "\n";
        ofile << "<users" << "\n";


       set<User*>::iterator it;
       for (it = userbase.begin(); it!= userbase.end(); ++it)
       {

        (*it)->dump(ofile);

       }

       ofile << "</users>" << "\n";
       ofile << "<reviews>" << "\n";

       for (unsigned int i=0; i<items.size(); i++)
       {

       vector<Review*> v_reviews = items[i]->getReviews();
         for (unsigned int j=0; j< v_reviews.size(); j++)
         {
          v_reviews[j]->dump(ofile);

         }

       } 
        ofile << "</reviews>" << "\n";
}
      
    

  void Data::addToCart(string username, Product* item)
{
        carts.find(username)->second.push_back(item);

   

    


}

int Data::getCartSize(string username)
{

  map<string, vector<Product*> >::iterator it;
  it = carts.find(username);
  int answer = it->second.size();
  return answer;
    
}

vector<Product*> Data::getCart(string username)
{

    map<string, vector<Product*> >::iterator it;
    it = carts.find(username);

    return it->second;



}

User* Data::getUser(string username)
{

    set<User*>::iterator it;
    for (it = userbase.begin(); it!= userbase.end(); ++it)
    {

        if ((*it)->getName() == username)
            return (*it);



    }
    return NULL;


}

void Data::deleteFromCart(User* user, Product* product)
{
    if (carts.find(user->getName()) != carts.end())
    {
        std::vector<Product*>::iterator it = find(carts[user->getName()].begin(), carts[user->getName()].end(), product);
       
        if (it != carts[user->getName()].end())
        {
            carts[user->getName()].erase(it);
        }


    }
}

Product* Data::getProduct(Review* r)
{

  for (unsigned int i=0; i< items.size(); i++)
  {

    if (r->prodName == items[i]->getName())
    {

      return items[i];

    }

  }

  return NULL;
}


void Data::addReview(Review* r)
{
  
  string name = r->prodName;

  for (unsigned int i=0; i<items.size(); i++)
  {
    if (items[i]->getName() == name)
    {
      Product* p = items[i];
    p->addReview(r);

    }
  }


}



set<User*> Data::getUsers()
{
  return userbase;
}


Product* Data::getProdObj(string title)
{

  for (unsigned int i=0; i<items.size(); i++)
  {
    if (title == items[i]->getName())
    {
      return items[i];

    }


  }
return NULL;
}


HashTable* Data::getHash()
{

  return users;
}


void Data::getSynonyms(string filename)
{

  string currentLine;
  string keyword;
  string synonym;
  map<string, set<Product*> >::iterator it;
  set<Product*>::iterator itSet;


  ifstream in_file(filename.c_str());
  if (in_file.fail())
  {
    return;

  }


  while (getline(in_file, currentLine))
  {

    stringstream ss(currentLine);
    ss >> keyword;

    //making keyword lowercase
    for (unsigned int i=0; i < keyword.size(); i++)
    {
      keyword[i] = tolower(keyword[i]);

    }

    while (ss >> synonym)
    {
      it = smap.find(synonym);
      //if the synonym is not already in the map
      if (it == smap.end())

      {
      
        smap.insert(make_pair(synonym, kmap.find(keyword)->getValue()));
   

      }

      else
      {

        set<Product*> temp = it->second;

        for (itSet = kmap.find(keyword)->getValue().begin(); itSet != kmap.find(keyword)->getValue().end(); ++itSet)
        {
   
          it->second.insert(*itSet);

        }


      }

    } 
  }

}

