#include<iostream>
#include"BST.cxx"

using namespace std;

int main()
{
	int arr[5] = {4,2,56,3,6};
	BST bst;

	for(int i = 0; i < 5; i++)
	{
		bst.addLeaf(arr[i]);
	}
	
	bst.printInOrder();

	cout << "compilation successful" << endl;
	return 0;
}

