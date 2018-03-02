#ifndef BST_H
#define BST_H

struct node
{
	int data;

	struct node* left;
	struct node* right;
};

void printTitle();
void quickFill(node*& root, int input);
void insertBST(node*& root, int input);
bool deleteBST(node*& root, int input);
void printBST(node* root);
int findLargest(node* root);
int findSmallest(node* root);
node* searchBST(node* root, int input);


#endif
