#ifndef NODE_H
#define NODE_H

struct Node
{
	char ch;
	Node *next;
	Node *child;
	Node(){
		next = 0;
		child = 0;
	}
	Node(char c){
		ch = c;
		next = 0;
		child =0;
	}
};
#endif