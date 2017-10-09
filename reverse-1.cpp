#include <iostream>

struct Node 
{
	int data;
	Node * next;
};

Node * reverse(Node * head) 
{
	Node *reversed = NULL;

	for (Node *node = head, *next; node != NULL; node = next)
	{
		next = node->next;
		node->next = reversed;
		reversed = node;
	}

	return reversed;

}
