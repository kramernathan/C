#pragma once
#include <string>
using std::string;

struct node
{
	node* next;
	string word;
};

void push(node*& head, string inp);
void pop(node*& head);
void enqueue(node*& head, string inp);
void dequeue(node*& head);
void printList(node* head);
string returnNode(node* head, int index);
