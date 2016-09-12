//BinarySearchTree.cpp
#include "BinarySearchTree.h"
#include <queue>
using namespace std;

/*-------------------------------------
Free Node
---------------------------------------*/
void BSTree::freeNode(BTreeNode* node)
{
	if(node != NULL)
	{
		freeNode(node->left_child);
		freeNode(node->right_child);
		delete node;
	}
}

/*-------------------------------------
Initilize the root
---------------------------------------*/
void BSTree::initilize_root(int Key)
{
	this->root = new BTreeNode(NULL,NULL,NULL, Key, 1);
	this->size++;
}

/*-------------------------------------
Insert node into tree
---------------------------------------*/
void BSTree:: insert_node(int Key, BTreeNode* root)
{
	int compare = root->SearchCost; //hold the number of comparisons at each insert
	BTreeNode* parent = root; // Create a pointer to the parent node
	if(Key < root->key && root->left_child == NULL)
	{	
		root->left_child = new BTreeNode (parent, NULL, NULL, Key, compare+1);
		this->size++;
	}
	else if (Key > root->key && root->right_child == NULL)
	{
		root->right_child = new BTreeNode (parent, NULL, NULL, Key, compare+1);
		this->size++;
		
	}
	else if(Key < root->getKey())
	{
		this->insert_node(Key, root->left_child);
		
	}
	else if(Key > root->getKey())
	{
		this->insert_node(Key, root->right_child);
	}
	else
		return;
}

/*-------------------------------------
Remove node from tree
---------------------------------------*/
BTreeNode* BSTree::remove(int Key, BTreeNode* tmp)
{
	if(tmp == NULL);
	
	//Only one node
	if(this->size == 1 && this->root->key == Key)
	{
		this->root = NULL;
		tmp = NULL;
		this->size--;
	}
	
	//Find the correct node
	else if(Key < tmp->key) 
		tmp->left_child = remove(Key, tmp->left_child);
	else if (Key > tmp->key) 
		tmp->right_child = remove(Key, tmp->right_child);
	
	//Remove correct node
	else if (tmp->left_child != NULL && tmp->right_child != NULL)
	{
		tmp->key = find_min()->key;
		tmp->right_child = remove_Min(tmp->right_child);
	}
	
	//For linear BSTree's (move every node up one spot)
	else if ((tmp->left_child == NULL && tmp->right_child != NULL))
	{
		BTreeNode* node = tmp;
		while(node->right_child!=NULL)
		{
			node->key = node->right_child->key;
			node = node->right_child;
		}
		this->size--;
		node->parent->right_child = NULL; // delete the last node
	}
	
	//Remove correct node
	else
	{
		BTreeNode* node = tmp;
		tmp = (tmp->left_child != NULL) ? tmp->left_child : tmp->right_child;
		this->size--;
		delete node;
	}
	return tmp;
}

/*-------------------------------------
Find the minimum root in right subtree (used in remove function)
---------------------------------------*/
BTreeNode* BSTree::find_min()
{
	BTreeNode* tmp = this->root->right_child;
	BTreeNode* last = tmp;
	while (tmp != NULL)
	{
		last = tmp;//keeps track of the node so when the loop terminates it will not return null
		tmp = tmp->left_child;// controls the loop
	}
	return last;
}

/*-------------------------------------
Remove the minimum node(used in remove function)
---------------------------------------*/
BTreeNode* BSTree::remove_Min(BTreeNode* t)
{
	if(t == NULL);
	if(t->left_child != NULL)
		t->left_child = remove_Min(t->left_child);
	else if(t->right_child != NULL)
		t->right_child = remove_Min(t->right_child);
	else
	{
		BTreeNode* node = t;
		t = t->right_child;
		this->size--;
		delete node;
	}
	return t;
}

 /*-------------------------------------
Print tree by levels
---------------------------------------*/
void BSTree::print_by_level()
{
	if(this->isEmpty()) 
		return;
	
	int level = 1;
	int next_level = 0;
	int height = -1;
	
	queue<BTreeNode*> tQueue;
	
	tQueue.push(this->root);
	
	while(!tQueue.empty())
	{
		BTreeNode* tmp = tQueue.front();
		
		tQueue.pop();
		level--;
		if(tmp != NULL)
		{
			cout <<tmp->key <<" ";
			tQueue.push(tmp->left_child);
			tQueue.push(tmp->right_child);
			next_level += 2;
		}
		else if (height != this->getHeight())
			cout << "X ";
		if(level == 0)
		{
			cout <<endl;
			level = next_level;
			next_level = 0;
			height++;
		}
	}
}

/*----------------------------------------------------------
Get the height of the tree (used in print by level function)
------------------------------------------------------------*/
int BSTree::height(BTreeNode* t)
 {
	 if(t == NULL)
		return -1;
	else
	{
		int LeftHeight = height(t->left_child);
		int RightHeight = height(t->right_child);
		return (LeftHeight > RightHeight) ? 1+LeftHeight : 1+RightHeight;
	}
}

/*-------------------------------------
Print tree using postorder traversal
---------------------------------------*/
void BSTree::postOrder(BTreeNode* node, ostream& out)
{
	if(node == NULL)
		return;

		postOrder(node->left_child, out);
		postOrder(node->right_child, out);
		this->TotalSC += node->SearchCost;
		out <<node->key <<"[" <<node->SearchCost <<"] ";
}

/*-------------------------------------
Print tree using inorder traversal
---------------------------------------*/	
void BSTree::inOrder(BTreeNode* node, ostream& out)
{
	if(node == NULL)
		return;
	
		inOrder(node->left_child, out);
		out <<node->key <<"[" <<node->SearchCost <<"] ";
		inOrder(node->right_child, out);
}

/*-------------------------------------
Print tree using preodrder traversal
---------------------------------------*/
void BSTree::preOrder(BTreeNode* node, ostream& out)
{
	if(node == NULL)
		return;
	
		out <<node->key <<"[" <<node->SearchCost <<"] ";
		preOrder(node->left_child, out);
		preOrder(node->right_child, out);
}	

/*------------------------------------------------
Print tree with nodes formatted as key[searchcost]
--------------------------------------------------*/
void BSTree::print_with_braces(BTreeNode* node)
{
		if(node == NULL) 
		return;
	
	queue<BTreeNode*> tQueue;
	
	tQueue.push(node);
	
	while(!tQueue.empty())
	{
		BTreeNode* tmp = tQueue.front();
		
		tQueue.pop();
		if(tmp != NULL)
		{
			cout <<tmp->getKey() <<"[" <<tmp->getCost() <<"]" <<endl;
			tQueue.push(tmp->getLeft());
			tQueue.push(tmp->getRight());
		}

	}
}

/*--------------------------------------------------
Calculate and return the average search cost of tree
----------------------------------------------------*/	
double BSTree::aveSC()
{
	if (this->size == 0) return 0;
	else return this->TotalSC/this->size;
}

/*--------------------------------------------------
Output operator--- Key = # SearchCost = # formatting
----------------------------------------------------*/
ostream& operator<<(ostream& out, BSTree& tree)
{
	if(tree.isEmpty()) 
		return out;
	
	queue<BTreeNode*> tQueue;
	
	tQueue.push(tree.getRoot());
	
	while(!tQueue.empty())
	{
		BTreeNode* tmp = tQueue.front();
		
		tQueue.pop();
		if(tmp != NULL)
		{
			out <<"Key = " <<tmp->getKey() <<" SearchCost = " <<tmp->getCost() <<"\n";
			tQueue.push(tmp->getLeft());
			tQueue.push(tmp->getRight());
		}

	}
	return out;
}
	

	