#include <iostream>
#include <vector>
#include "bst.h"


using namespace std;

/* -----------------------------------------------------
 * Regular Splay Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class Splay: public BinarySearchTree<KeyType, ValueType> {
 
 public:
void insert(const std::pair<const KeyType, ValueType> & newNode ) 
{	
	//NULL parent will be changed
	Node <KeyType, ValueType> * node = new Node<KeyType, ValueType>(newNode.first, newNode.second, NULL);

	//if there is no root
	if (this->root == NULL)
	{
		this->root = node;

	}

	else
	{
		splayFunction(insertInTree(node, this->root, NULL));

	}

}

Node<KeyType, ValueType> * find (const KeyType&  k)
{
return internalFind(k);

}

protected:
  /**
   * Helper function to find a node with given key, k and 
   * return a pointer to it or NULL if no item with that key
   * exists
   */


  Node<KeyType, ValueType>* internalFind(const KeyType& k) 
  {
    Node<KeyType, ValueType> *curr = this->root;
    Node<KeyType, ValueType> *prev = curr;

    while (curr) {
      if (curr->getKey() == k) {
     splayFunction(curr);
     this->root = curr;
	return curr;
      }
       else if (k < curr->getKey()) {
    prev = curr;
	curr = curr->getLeft();
      } else {
    prev = curr;
	curr = curr->getRight();
      }
    }


    //splay after
    if (prev != NULL)
    	{
    		splayFunction(prev);
			this->root = prev;
    	}
    return NULL;


  }
  
 
  



 Node <KeyType, ValueType>* insertInTree(Node<KeyType, ValueType>* nodeToInsert, Node<KeyType, ValueType>* current, Node<KeyType, ValueType>* parent)
  {

  	 if (current == NULL)
	{
		//Node<KeyType, ValueType>* temp = new Node<KeyType, ValueType>;
		nodeToInsert->setParent(parent);
		if (nodeToInsert->getKey() < parent->getKey())
		{
			parent->setLeft(nodeToInsert);

		}

		else
		{
			parent->setRight(nodeToInsert);

		}
		return nodeToInsert;
	} 

  // go left
     if(current->getKey() < nodeToInsert->getKey())
        {
        	current->setRight(insertInTree(nodeToInsert, current->getRight(), current)); 
    		return nodeToInsert;
    	}
     
       // go right
    else if (nodeToInsert->getKey() < current->getKey())
    	{	
    		current->setLeft(insertInTree(nodeToInsert, current->getLeft(), current)); 
    		return nodeToInsert;
    	}

     else
    {
    	nodeToInsert->setParent(current->getParent());
    	nodeToInsert->setLeft(current->getLeft());
    	nodeToInsert->setRight(current->getRight());
    	delete current;
    	return nodeToInsert;

    }
    
  }

  
void RotateRight(Node <KeyType, ValueType> * pivot )
  {
			Node<KeyType, ValueType>* parent = pivot->getParent();
			Node<KeyType, ValueType>* grandParent = pivot->getParent()->getParent();

			parent->setLeft(pivot->getRight());
			if (pivot->	getRight())
			{
				pivot->getRight()->setParent(pivot->getParent());

			}


			if (grandParent != NULL)
			{
				if (amILeft(parent))
				{
					grandParent->setLeft(pivot);

				}

				else
				{
					grandParent->setRight(pivot);
				}

			}
			pivot->setParent(grandParent);
			parent->setParent(pivot);
			pivot->setRight(parent);

	}

  
 void RotateLeft(Node <KeyType, ValueType> * pivot )
  {
  	Node<KeyType, ValueType>* parent = pivot->getParent();
	Node<KeyType, ValueType>* grandParent = pivot->getParent()->getParent();

			parent->setRight(pivot->getLeft());
			if (pivot->	getLeft())
			{
				pivot->getLeft()->setParent(pivot->getParent());

			}


			if (grandParent != NULL)
			{
				if (amILeft(parent))
				{
					grandParent->setLeft(pivot);

				}

				else
				{
					grandParent->setRight(pivot);
				}

			}
			pivot->setParent(grandParent);
			parent->setParent(pivot);
			pivot->setLeft(parent);
  }


bool amILeft(Node<KeyType, ValueType>* node)
{
	if (node->getKey() < node->getParent()->getKey())
		{
			return true;
		}
	return false;

}

void splayFunction(Node <KeyType, ValueType>* node)
{

	if (node ->getParent() != NULL)
	{
		//zig case
		if (node->getParent() ->getParent() == NULL)
		{

			if (amILeft(node))
			{
				RotateRight(node);
			}
			else
			{

				RotateLeft(node);
			}

		}
		else
		{
			//zig zig
			if (amILeft(node) && amILeft(node->getParent()))
			{
				RotateRight(node->getParent());
				RotateRight(node);
			}

			//zig zig
			else if (!amILeft(node) && !amILeft(node->getParent()))
			{
				RotateLeft(node->getParent());
				RotateLeft(node);

			}

			//zig zag
			else if (amILeft(node) && !amILeft(node->getParent()))
			{
				RotateRight(node);
				RotateLeft(node);
			}

			//zig zag
			else 
			{
				RotateLeft(node);
				RotateRight(node);

			}

			splayFunction(node);
		}


		this->root = node;





	}




}


};