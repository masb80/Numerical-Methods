#include<iostream>
#include"BST.h"

using namespace std;

	BST::BST()
	{
		root = NULL; // Constructor for making root node empty initially
	}


	BST::Node * BST::createLeaf(int key) // making node
	{
		Node * n = new Node; // allocate mamory for node
		n->key = key; // initialize key
		n->left = NULL; // initialize left as NULL
		n->right = NULL; // initialize right as NULL
		return n;
	}
	void BST::addLeaf(int key)
	{
		addLeafPrivate(key, root);		
	}
	void BST::addLeafPrivate(int key, Node *Ptr)
	{
		if(root == NULL)
			{ 
				root = createLeaf(key); // making leaf by key
				cout << "In root node,  key =  " << key << ",  root =   " << root->key<<  endl;	 
			}
		else if(key < Ptr->key) // given value is less than present root
			{
				 if(Ptr->left != NULL)// child left node is not empty
				 {
				 	 addLeafPrivate(key, Ptr->left); // recursion of chack of root again for left node
				 }
				 else
				 {
				 	Ptr->left = createLeaf(key); // if empty then add and make leaf node with that
				 }
				cout << "In left key,  key =  " << key << ",     Ptr->left->key = " << Ptr->left->key <<  endl;	 
			}
		else if(key > Ptr->key) //  similarly for right node
			{
				if(Ptr->right != NULL)
				{
					addLeafPrivate(key, Ptr->right);
				}
				else
				{
					Ptr->right = createLeaf(key);
				}
				cout << "In rightt key,  key =  " << key << ",  Ptr->right->key =  " << Ptr->right->key <<  endl;	 
			}
		else
			{
				cout << "The given key  " << key << "has already been added" << endl;
			}
	}

void BST::printInOrderPrivate(Node * Ptr)
{
	if(root != NULL) // if root node is not empty
	{
		if(Ptr->left != NULL) // if left node is not empty  : step 1: go left
		{
			printInOrderPrivate(Ptr->left); // recursion like root node
		}
			cout << Ptr->key << "  "; // if empty then print it: step 2
		if(Ptr->right != NULL) // if right node is not empty : step 3: go right
		{
			printInOrderPrivate(Ptr->right); // recursion like root node

		}
	}
	else // if root node is empty then the tree is empty
	{
		cout << "The tree is empty\n" << endl;
	}
}
void BST::printInOrder()
{
	printInOrderPrivate(root);	// making print private for giving root node
}

