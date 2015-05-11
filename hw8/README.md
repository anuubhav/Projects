Note: I did the Login (20%), Hash Table(20%), Splay Tree(50%), and Thesaurus(20%).

I did not do recommendations at all.


Hash Table - done in the files hashtable.h and hashtable.cpp. The hash table has been implemented in my derived data store class, data.cpp. The Hash Table object is called users. The hash table can be tested with any function done on users. This includes functions such as inserting a user, viewing a user's cart, etc.


Splay Tree- done in the file splay.h. The splay tree is a replacement for the previous map that mapped keywords to products. The splay tree can be tested by looking up keywords that are in the product's title. The actual splay tree object is created in data.cpp, as Splay <string, set<Product*> > kmap. Every entry in the splay tree, kmap, is between a keyword and all the products that it maps to. All the splay tree operations are found in Data::search().

Thesaurus - done in the derived data store, data.cpp. The thesaurus function, getSynonyms(), takes in a file which will be thesaurus.txt. 


Usage:
./hw8 dbSmall3.txt 1 thesaurus.txt

Note: the 1 specifies hash table usage. I was intending to do other bells and whistles that required command line arguments, but decided against it last minute.

Note: The format of the thesaurus should be as follows:

keyword1 synonym1 synonym2 synonym3

keyword2 synonym1 synonym2 synonym3

keyword3 synonym1 synonym2 synonym3

The keywords should be words that are in the names of products in the database used. There should be no empty lines between each set of keyword+synonyms, even though github makes it appear so. They should just be on separate lines.
