#include<iostream>
#include"BST.h"

using namespace std;

	BST::BST()
	{
		root = NULL;
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
				root = createLeaf(key);
			}
		else if(key < Ptr->key)
			{
				 if(Ptr->left != NULL)
				 {
				 	 addLeafPrivate(key, Ptr->left);
				 }
				 else
				 {
				 	Ptr->left = createLeaf(key);
				 }
			}
		else if(key > Ptr->key)
			{
				if(Ptr->right != NULL)
				{
					addLeafPrivate(key, Ptr->right);
				}
				else
				{
					Ptr->right = createLeaf(key);
				}
			}
		else
			{
				cout << "The given key  " << key << "has already been added" << endl;
			}

	}

void BST::printInOrder()
{
	printInOrderPrivate(root);	
}
void BST::printInOrderPrivate(Node * Ptr)
{
	if(root != NULL)
	{
		if(Ptr->left != NULL)
		{
			printInOrderPrivate(Ptr->left);
		}
			cout << Ptr->left << endl;
		if(Ptr->right != NULL)
		{
			printInOrderPrivate(Ptr->right);

		}
		//cout << Ptr->right << endl;
	}
	else
	{
		cout << "The tree is empty" << endl;
	}

}

