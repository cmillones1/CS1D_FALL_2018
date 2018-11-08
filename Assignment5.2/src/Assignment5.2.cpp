/*************************************************************************
 * AUTHORS	     : Chris Millones
 * STUDENT IDS   : 361396
 * Assignment #4 : Binary Trees
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 5:00 - 7:20PM
 * DUE DATE    	 : 10/1/2018
 ************************************************************************/

/*************************************************************************
 * Binary Trees
 * _______________________________________________________________________
 * Implement a binary search tree using an array, vector or linked list.
 * store the following elements:
 * 13, 888, 444, 18, 44, 88, 12, 25, 59, 28, 24, 49, 7, 109, 55, 118, 89, 33, 19
 *
 * Perform the in-order, post-order, pre-order, breadth-first traversals
 *
 * in addition to the traversals, print out the binary search tree by
 * level.
 ************************************************************************/
#include "header.h"
#include "BST.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones\n";
	cout << setw(10) << "ASSIGNMENT #4:  Binary Trees \n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 5:00 - 7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      10/1/2018\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Implement a binary search tree using an array, vector or linked list.\n"
			"store the following elements:\n"
			"\n13, 888, 444, 18, 44, 88, 12, 25, 59, 28, 24, 49, 7, 109, 55, 118, 89, 33, 19 \n\n"
			"Perform the in-order, post-order, pre-order, breadth-first traversals\n"
			"in addition to the traversals, print out the binary search tree by level.\n\n";
}

const void BINARYTREE()
{
	cout << "x : indicates no child/ empty node\n";
	cout << "Root: 13\n\n";

	cout << "Parent: 13\n";
	cout << "Left Child: 12\n";
	cout << "Right Child: 888\n\n";

	cout << "Parent: 12\n";
	cout << "Left Child: 7\n";
	cout << "Right Child: x\n\n";

	cout << "Parent: 888\n";
	cout << "Left Child: 444\n";
	cout << "Right Child: x\n\n";

	cout << "Parent: 444\n";
	cout << "Left Child: 18\n";
	cout << "Right Child: x\n\n";

	cout << "Parent: 18\n";
	cout << "Left Child: x\n";
	cout << "Right Child: 44\n\n";

	cout << "Parent: 44\n";
	cout << "Left Child: 25\n";
	cout << "Right Child: 88\n\n";

	cout << "Parent: 25\n";
	cout << "Left Child: 24\n";
	cout << "Right Child: 28\n\n";

	cout << "Parent 88\n";
	cout << "Left Child: 59\n";
	cout << "Right Child: 109\n\n";

	cout << "Parent 24\n";
	cout << "Left Child: 19\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 28\n";
	cout << "Left Child: x\n";
	cout << "Right Child: 33\n\n";

	cout << "Parent 59\n";
	cout << "Left Child: 49\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 109\n";
	cout << "Left Child: 89\n";
	cout << "Right Child: 118\n\n";

	cout << "Parent 19\n";
	cout << "Left Child: x\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 33\n";
	cout << "Left Child: x\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 49\n";
	cout << "Left Child: x\n";
	cout << "Right Child: 55\n\n";

	cout << "Parent 89\n";
	cout << "Left Child: x\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 118\n";
	cout << "Left Child: x\n";
	cout << "Right Child: x\n\n";

	cout << "Parent 55\n";
	cout << "Left Child: x\n";
	cout << "Right Child: x\n\n";
}

int main()
{

	PRINTAUTHOR();   //Brief summary abt author
	INSTRUCTIONS();  //Prints the Assignment to be completed
	BINARYTREE();


	BST<int>* tree = new BST<int>;  //Create an Empty Tree.

	int data = 0; 						//Will be used to store data. type int.

	ifstream inFile;				//Create an Ifstream variable

	inFile.open("data.txt");


	/*
	 * Loop Will run until the file is empty.
	 * Will store the data into "data" then store that
	 * data into a root of a tree. and keep on filling the tree
	 * until the file is out of data
	 */
	while(!inFile.eof())
	{
		inFile >> data;	// Store integer data into variable
		tree->root = tree->Insert(tree->root,data); // Store data to tree
	}


	//Prints the original binary tree with levels.
	cout << "\n\t~BinarySearchTree~\n";
	tree->PrintByLevel(tree->getRoot());

	//prints the traversal of the binary tree( IN-ORDER)
	cout << "\n\t~In-Order Traversals~\n";
	tree->In_Order(tree->getRoot());

	//prints the traversal of the binary tree( POST-ORDER)
	cout << "\n\t~Post-Order Traversals~\n";
	tree->Post_Order(tree->getRoot());

	//prints the traversal of the binary tree( PRE-ORDER)
	cout << "\n\t~Pre-Order Traversals~\n";
	tree->Pre_Order(tree->getRoot());

	//prints the traversal of the binary tree( BREADTH-ORDER)
	cout << "\n\t~Breadth-First~\n";
	tree->Breadth_Order(tree->getRoot());


	return 0;
}
