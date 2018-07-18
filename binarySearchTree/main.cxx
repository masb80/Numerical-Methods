#include<iostream>
#include"BST.cxx"

using namespace std;

int main()
{
	int arr[] = {4,2,56,3,6,5,6,34,35,78,12,13,15,17,23,45,56,78,90,100};
	BST bst;
	bst.printInOrder();
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		bst.addLeaf(arr[i]); // creating leaf with the given aray
	}	
	bst.printInOrder();
	cout << "\ncompilation successful" << endl;
	return 0;
}

