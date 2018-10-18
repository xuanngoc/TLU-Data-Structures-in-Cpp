#ifndef NODE_H
#define NODE_H

struct Node
{
	char ch;
	Node *next;
	Node *child;
	const char *nghia; 
	Node(){
		next = child = 0;
		nghia =0;
	}
	Node(char c){
		ch = c;
		next = child = 0;
	}
	Node(char c, const char * ng)
	{
		ch= c;
		nghia = ng;
		next = child =0;
	}
}; 
#endif