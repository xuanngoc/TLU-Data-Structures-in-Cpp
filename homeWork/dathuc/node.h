#ifndef node_h
#define node_h

struct Node{
	int heSo;
	int bac;
	Node *next;
	Node(int hs, int b){
		heSo = hs;
		bac = b;
		next = 0;
	}
	Node(){
		next = 0;
	}
};
#endif
