#include "sq.h"
#include <iostream>
using namespace std;

void push(node*& head, string inp)
{
	node* newNode = new node;
	newNode->word = inp;
	newNode->next = head;
	head = newNode;
}

void pop(node*& head)
{
	node* temp = head;
	head = head->next;
	delete temp;
}

void enqueue(node*& head, string inp)
{
	node* newNode = new node;
	newNode->word = inp;
	newNode->next = NULL;
	newNode->next = head;
	head = newNode;
}

void dequeue(node*& head)
{
	node* temp = new node;
	node* go = head;
	while(go->next != NULL)
	{
		temp = go;
		go = go->next;
	}
	temp->next = NULL;
	delete go;
}

void printList(node* head)
{
	while(head != NULL) // Loop to go through list
	{
		cout << head->word << " ";
		head = head->next;
	}
	cout << endl;
}
