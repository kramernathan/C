#include "sq.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "\n===Stack===\n";
	
	node* head = NULL;
	push(head, "Better"); // Inserts in empty list
	printList(head);
	push(head, "We're");
	printList(head);	
	push(head, "Technically");
	printList(head);
	push(head, "DSU:");
	printList(head); 	 // prints "DSU: Technically We're Better"
	
	pop(head); 
	printList(head);
	pop(head); 
	printList(head);
	pop(head); 
	printList(head);
	pop(head); 		 // pops off final item
	printList(head); // will be empty at this point
	
	
	cout << "===Queue===\n";
	enqueue(head, "Better"); 
	printList(head);
	enqueue(head, "We're"); 
	printList(head);
	enqueue(head, "Technically"); 
	printList(head);
	enqueue(head, "DSU:"); 
	printList(head);  // prints "DSU: Technically We're Better"
	
	dequeue(head); 
	printList(head);
	dequeue(head);  
	printList(head);
	dequeue(head);
	printList(head);
	dequeue(head);	 // removes final item
	printList(head); // will be empty
	
	return 0;
}