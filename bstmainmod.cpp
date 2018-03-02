#include <iostream>
#include <ctime>
#include "bst.h"
using namespace std;

int main()
{
	printTitle();
	node* root = NULL;
	char i = 'g'; //simply initializing the char to something here

	while (i != 'x')
	{
		cout << "> ";
		cin >> i;

		switch(i) {
			case 'x' :
				i = 'x';
				break;
			case 'a' :
				int j;
				cout << "  Enter an integer to insert: ";
				cin >> j;
				insertBST(root, j);
				break;
			case 'b' :
				int k;
				cout << "  Enter an integer to delete: ";
				cin >> k;
				deleteBST(root, k);
				break;
			case 'c' :
				cout << "  Here is your current tree: ";
				printBST(root);
				cout << endl;
				break;
			case 'd' :
				int f1;
				int f2;
				findLargest(root);
				findSmallest(root);
				f1 = findLargest(root);
				f2 = findSmallest(root);
				cout << "  Largest value: " << f1 << "\n  Smallest value: " << f2 << endl;
				break;
			case 'e' :
				int m;
				cout << "  Search for integer: ";
				cin >> m;
				searchBST(root, m);
				break;
			case 'f':
				srand(time(NULL));
				for (int n=0; n<15; n++)
				{
					int k = rand() % 100 + 1;
					quickFill(root, k);
				}
				cout << "  Success!\n";
				break;
			default:
				cout << "  Invalid input, try again!\n";
				break;
		}
	}
	return 0;
}
