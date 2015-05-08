Note: I did the Login (20%), Hash Table(20%), Splay Tree(50%), and Thesaurus(20%).

I did not do recommendations at all.


Hash Table - done in the files hashtable.h and hashtable.cpp. The hash table has been implemented in my derived data store class, data.cpp. The Hash Table object is called users. 

Splay Tree- done in the file splay.h. 

Thesaurus - done in the derived data store, data.cpp. The thesaurus function, getSynonyms(), takes in a file which will be thesaurus.txt.


Usage:
./hw8 dbSmall3.txt 1 thesaurus.txt

Note: the 1 specifies hash table usage. I was intending to do other bells and whistles that required command line arguments, but decided against it last minute.

Note: The format of the thesaurus should be as follows:
keyword1 synonym1 synonym2 synonym3
keyword2 synonym1 synonym2 synonym3
keyword3 synonym1 synonym2 synonym3

The keywords should be words that are in the names of products in the database used.
