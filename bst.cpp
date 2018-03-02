#include "bst.h"
#include <iostream>
#include <ctime>
using namespace std;

void printTitle()
{
	cout << "888888b.       .d8888b.    88888888888 \n";
	cout << "888   88b     d88P  Y88b       888     \n";
	cout << "888  .88P     Y88b.            888     \n";
	cout << "8888888K.       Y888b.         888     \n";
	cout << "888   Y88b         Y88b.       888     \n";
	cout << "888    888           888       888     \n";
	cout << "888   d88P    Y88b  d88P       888     \n";
	cout << "8888888P        Y8888P         888     \n";
	cout << "\n";

	cout << "Which function would you like to execute? (Enter choice)\n";
	cout << "a) Insert a node\n";
	cout << "b) Delete a node\n";
	cout << "c) Print the integers in ascending order\n";
	cout << "d) Display the largest and smallest values\n";
	cout << "e) Return the node pointer for the node that has input integer as an attribute\n";
	cout << "f) Quickly fill the the tree with 15 random values\n";
	cout << "x) Quit\n";
}

void quickFill(node*& root, int input)
{
	if(root == NULL)
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = input;
	}
	else if	(root->data > input)
	{
	quickFill(root->left, input);
	}
	else
	{
	quickFill(root->right, input);
	}
}

void printBST(node* root)
{
	if(root == NULL)
		return;
	else
	{
		printBST(root->left);
		cout << root->data << " ";
		printBST(root->right);
	}
}

void insertBST(node*& root, int input)
{
	if(root == NULL)
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = input;
	}
	else if	(root->data > input)
	{
	insertBST(root->left, input);
	}
	else
	{
	insertBST(root->right, input);
	}
}


bool deleteBST(node*& root, int d)
{
    if(root == NULL)
    {
		cout << "  The value is not in the tree\n";
		return false;
	}

    else if(d < root->data) // Go left
        return deleteBST(root->left, d);
    else if(d > root->data) // Go right
        return deleteBST(root->right, d);

    else if(root->data == d) //found node to delete
    {
        // No children, just delete memory
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return true;
        }
        else if(root->right == NULL) // left child must exist
        {
            node* dltPtr = root;
            root = root->left;
            delete dltPtr;
			return true;
        }
        else if(root->left == NULL) // right child must exist
        {
            node* dltPtr = root;
            root = root->right;
            delete dltPtr;
			return true;
        }
        else // we must have two children
        {
            // Find the largest child in the left subtree
            node* dltPtr = root->left; // now in the left subtree
            while(dltPtr->right != NULL)
            {
                dltPtr = dltPtr->right;
            }
            root->data = dltPtr->data;
            // might have a left child, so call recursive dlt
            return deleteBST(root->left, dltPtr->data);
        }
    }
	return true;
}


int findLargest(node* root)
{
	if(root->right == NULL)
	{
		return root->data;
	}
	return findLargest(root->right);
}

int findSmallest(node* root)
{
	if (root->left == NULL)
	{
    	return root->data;
  	}
  return findSmallest(root->left);
}

node* searchBST(node* root, int input)
{
	if(root == NULL) // entered val is not in tree
	{
		cout << "  The value is not in the tree\n";
		return root;
	}
	else if(input == root->data)
	{
		cout << "  " << root << endl;
		return root;
	}
	else
	{
		if(input < root->data)
		return	searchBST(root->left, input);
		else if(input > root->data)
		return	searchBST(root->right, input);
	}
}
