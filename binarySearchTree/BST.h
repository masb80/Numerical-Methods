class BST
{
	private:
		struct Node
		{
			int key;
			Node * left, *right;			
		};
		Node * root;
		void addLeafPrivate(int key, Node * ptr);
		void printInOrderPrivate(Node *Ptr);
	public:
		BST();
		Node * createLeaf(int key);
		void addLeaf(int key);
		void printInOrder();
};
