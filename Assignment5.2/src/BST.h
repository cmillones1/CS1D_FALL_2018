/*************************************************************************
 * AUTHORS	     : Chris Millones
 * STUDENT IDS   : 361396
 * Assignment #4 : Binary Trees
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : 2/22/2017
 ************************************************************************/



#ifndef BST_H_
#define BST_H_
#include "header.h"

template <class E>
struct BSTNode
{
	E data;
	BSTNode<E> *left;
	BSTNode<E> *right;
};

/*
 * CLASS BINARY SEARCH TREE
 *
 */
template <class E>
class BST
{
	public:
		BST();
		~BST();

		BSTNode<E>* GetNewNode(int data);// Creates a new node & returns it

		//Inserts a Node to the tree.
		BSTNode<E>* Insert(BSTNode<E>* root, int data);

		//Deletes a specified Node from the tree and returns the sub tree
		BSTNode<E>* Delete(BSTNode<E>* root, int data);

		//Finds the last leaf of the tree
		BSTNode<E>* FindMinimal(BSTNode<E> *root);

		// Searches to find a data in the tree
		bool Search(BSTNode<E>* root, int data);


		void Pre_Order(BSTNode<E>* root); // Returns Pre-order traversal
		void In_Order(BSTNode<E>* root); // Returns in-order traversal
		void Post_Order(BSTNode<E>* root); // Returns post-order traversal
		void Breadth_Order(BSTNode<E>* root); // Returns BReadth-order traversal

		int Depth(BSTNode<E>* root); // Returns the Depth of the tree.


		void PrintByLevel(BSTNode<E>* root); // Prints the tree by level.

		BSTNode<E>* getRoot();


	public:
		BSTNode<E> *root;
};

template<class E>
BST<E>::BST()
{
    root = NULL;
}

template<class E>
BST<E> ::~BST()
{
    root = NULL;
}

template <class E>
BSTNode<E>* BST<E>::getRoot()
{
	return root;
}

template <class E>
BSTNode<E>* BST<E>::GetNewNode(int data)
{
    BSTNode<E>* temp = new BSTNode<E>;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

template <class E>
BSTNode<E>* BST<E>::Insert(BSTNode<E>* root, int data)
{
	if(Search(root,data))
	{
		return root;
	}
	if(root == NULL)
	{
		root = GetNewNode(data);
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left,data);
	}
	else
	{
		root->right = Insert(root->right,data);
	}
	return root;
}

template <class E>
bool BST<E>::Search(BSTNode<E>*root, int data)
{
	if(root == NULL)
	{
		return false;
	}
	else if(root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}

template <class E>
BSTNode<E>*  BST<E>::Delete(BSTNode<E>*root, int data)
{
	BSTNode<E>* temp;

	if (root == NULL)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left = Delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else
	{
		// CASE : NO CHILD
		if( root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;

		}
		// CASE : 1 CHILD - EMPTY LEFT
		else if ( root->left == NULL)
		{
			temp = root;
			root = root->right;
			delete temp;
		}
		// CASE : 1 CHILD - EMPTY RIGHT
		else if (root->right == NULL)
		{
			BSTNode<E>* temp = root;
			root = root->left;
			delete temp;

		}
		// CASE : 2 childeren
		else
		{
			temp = FindMinimal(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

template <class E>
BSTNode<E>* BST<E>::FindMinimal(BSTNode<E> *root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

template <class E>
void BST<E>::Pre_Order(BSTNode<E> *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	Pre_Order(root->left);
	Pre_Order(root->right);

}

template <class E>
void BST<E>::In_Order(BSTNode<E>* root)
{
	if (root == NULL)
	{
		return;
	}
	In_Order(root->left);
	cout << root->data << " ";
	In_Order(root->right);
}

template <class E>
void BST<E>::Post_Order(BSTNode<E>* root)
{
	if (root == NULL)
	{
		return;
	}
	Post_Order(root->left);
	Post_Order(root->right);
	cout << root->data << " ";
}

template <class E>
void BST<E>::Breadth_Order(BSTNode<E>* root)
{

	if ( root == NULL)
	{
		return;
	}
	queue <BSTNode<E>*> BreadthOrder;
	BreadthOrder.push(root);
	BSTNode<E>* temp;

	while (!BreadthOrder.empty())
	{
		temp = BreadthOrder.front();
		cout << temp->data << " ";
		if(temp->left != NULL)
		{
			BreadthOrder.push(temp->left);
		}
		if(temp->right != NULL)
		{
			BreadthOrder.push(temp->right);
		}
		BreadthOrder.pop();
	}
}

template <class E>
int BST<E>::Depth(BSTNode<E>* root)
{
	int leftDepth;
	int rightDepth;

	if(root == NULL)
	{
		return 0;
	}
	else
	{
		leftDepth = Depth(root->left);
		rightDepth = Depth(root->right);

		if(leftDepth > rightDepth)
		{
			return leftDepth+1;
		}
		else
		{
			return rightDepth+1;
		}
	}
}


template <class E>
void BST<E>::PrintByLevel(BSTNode<E>* root)
{
	if(root == NULL)
	{
		return ;
	}
	queue <BSTNode<E>*> treeOrder;
	int levelCount = 1;
	int currentCount = 0;
	int currentLevel = 1;
	treeOrder.push(root);
	BSTNode<E>* temp;
	while(!treeOrder.empty())
	{
		cout << "Level " << currentLevel << ": ";
		while(levelCount > 0)
		{
			temp = treeOrder.front();
			cout << "  " << temp->data << " ";

			if(temp->left != NULL )
			{
				currentCount++;
				treeOrder.push(temp->left);
			}
			if(temp->right != NULL)
			{
				currentCount++;
				treeOrder.push(temp->right);
			}
			levelCount--;
			treeOrder.pop();
		}
		cout << endl;
		currentLevel++;
		levelCount = currentCount;
		currentCount = 0;

	}



}
#endif /* BST_H_ */
