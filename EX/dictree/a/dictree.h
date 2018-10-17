#include "node.h"
#include <string.h>
class DicTree
{
private:
	Node * root;
	////

	Node* AddLetter(char lt, Node* p)
	{
		Node *q = p-> child;
		if(q == 0)
		{
			Node *temp = new Node(lt);
			p->child = temp;
			return temp; 
		}	
		else
		{
			while(q -> ch != lt && q-> next != 0)
				q= q->next;

				
			if(q-> ch == lt)
			{
				return q;
			}
			else
			{
				Node * em = new Node(lt);
				q-> next  = em;
				return em;
			}	
		}
	}
	Node* SearchLetter(char lt, Node* p)
	{
		Node* q= p->child;
		while( q != 0)
		{
			if( q -> ch == lt)
			{
				return q;
			}	
			q= q -> next;
		}
		return 0;	
	}
public:
	DicTree()
	{
		root = new Node();
	}
	void AddWord(const char *word)
	{
		int len = strlen(word);
		Node *p = root;
		for(int i=0; i< len; i++)
		{
			p = AddLetter(word[i], p);
		}  
		Node * q = p->child;

		Node * thang = new Node('#');

		if( q == 0)
		{
			p-> child = thang;
		}	
		else
		{
			while( q-> ch != '#' && q->next !=0)
			{
				q= q->next;
			}
			if( q-> next == 0)
			{
				q -> next = thang;
			}
		}
	}
	bool Search(const char* word)
	{
		int len = strlen(word);
		Node *p = root;
		for(int i = 0; i< len; i++)
		{
			p= SearchLetter(word[i], p);
			if(p == 0 )
			{
				return 0;
			}	
		}
		Node *q= p-> child;
		while(q != 0)
		{
			if(q-> ch == '#')
				return 1;
			q = q-> next;
		} 
		return 0;
	}
};