#ifndef node_h
#define node_h

struct Node
{
	char ch;
	Node *child;
	Node *next;
	Node()
	{
		next = child = 0;
	}
	Node(char c)
	{
		ch = c;
		next = child = 0; 
	}
};

#endif