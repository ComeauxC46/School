//Binary Tree Node
#include <iostream>
#include <fstream>
using namespace std;

class BTreeNode
{
	//Private Members
	BTreeNode* parent;
	BTreeNode* left_child;
	BTreeNode* right_child;
	int key;
	int SearchCost;
	friend class BSTree;
public:
	//Constructor With Default Arguments
	BTreeNode(BTreeNode* parent = NULL , BTreeNode* left_child = NULL,BTreeNode* right_child = NULL, int key = 0, int SearchCost = 0)
			: parent(parent), left_child(left_child), right_child(right_child), key(key), SearchCost(SearchCost){}
	//Gain access to private members
	int getKey() {return key;}
	int getCost() {return SearchCost;}
	BTreeNode* getParent() {return parent;}
	BTreeNode* getLeft() {return left_child;}
	BTreeNode* getRight() {return right_child;}	
	//Check If Node is External
	bool isExternal() {return this->left_child == NULL && this->right_child == NULL;}
};

class BSTree
{
	//Private Members
	int size;
	BTreeNode* root;
	void freeNode(BTreeNode* node);
public:
	//Constructor
	BSTree() :size(0), root(NULL){}
	//Destructor
	~BSTree(){freeNode(root);}
	//Access Functions
	int getSize() {return size;}
	BTreeNode* getRoot() {return root;}
	int getHeight() {return (root == NULL) ? 0 : this->height(root);}//get height of tree
	int height(BTreeNode* t);//find the height of a tree
	bool isEmpty () {return size == 0;}
	void initilize_root(int Key);//Insert first Node Into Tree as root
	void insert_node(int Key, BTreeNode* root);//Insert Node into Tree(MUST PASS ADRESS TO ROOT)
	BTreeNode* remove(int Key, BTreeNode* tmp);	//Remove Node with Key From Tree
	BTreeNode* find_min();	//Find the Least Element in Right Subtree
	BTreeNode* remove_Min(BTreeNode* t);
	
	//Average Cost
	double TotalSC = 0;
	double aveSC();
	
	//Print Functions
	void print_by_level();
	void print_with_braces(BTreeNode* node);
		
	//Tree Traversals
	void postOrder(BTreeNode* node, ostream& out);
	void inOrder(BTreeNode* node, ostream& out);
	void preOrder(BTreeNode* node, ostream& out);
	
};

ostream& operator<<(ostream& out, BSTree& tree);
