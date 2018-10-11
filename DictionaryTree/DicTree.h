#ifndef DICTREE_H
#define DICTREE_H
#include "node.h"
#include <string.h>
class DicTree
{
private:
	Node *root;
	///
	Node* AddLetter(char a, Node *p)
	{
		Node * q =p->child;
		if(q == 0)
		{
			Node *con= new Node(a);
			p-> child = con;
			return con;
		}
		else{
			while( q -> ch != a && q -> next !=0)
			{
				q = q -> next;
			}	
			if( q -> ch == a)
				return q;
			else
			{
				Node *em= new Node(a);
				q -> next = em;
				return em;
			}
		}	
	}
	Node * SearchLetter(char a, Node *p)const
	{
		Node * q = p -> child;
		while( q != 0)
		{
			if( q-> ch == a)
				return q;
			q = q->next;
		}		
		return 0;
	}
public:
	DicTree()
	{
		root = new Node;
	}
	void AddWord(const char* word)
	{
		int len = strlen(word);
		Node * p = root;
		for(int i = 0; i< len ; i++)
		{
			p = AddLetter(word[i], p);
		}
		// Add letter # after word
		Node * pe = new Node('#');
		
		Node *q = p->child;
		if( q == 0)
			p->child = pe;
		else{
			while( q-> ch != '#' && q->next !=0)
			{
				q = q->next;
			}
			if( q -> next == 0)
				q->next = pe;
		}
	}
	bool Search( const char * word)const
	{
		int len = strlen(word);
		Node * p = root;
		for(int i = 0; i< len ; i++)
		{
			p = SearchLetter(word[i], p);
			//cout<<p->ch<<endl;
			if(p == 0){
				return 0;
			}
		}
		Node *q = p-> child;
		while( q != 0)
		{
			if( q-> ch == '#')
				return 1;
			q = q-> next;
		}
		return 0;	
	}
};
#endif