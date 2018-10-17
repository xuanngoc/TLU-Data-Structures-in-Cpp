#ifndef DICTREE_H
#define DICTREE_H

#include "node.h"
#include "string.h"

class DicTree
{
private:
	Node *root;
	////
	
	
	Node* AddLetter(char lt, Node *p)
	{
		Node *q = p->child;
		if( q == 0)
		{
			Node * con= new Node(lt);
			p -> child = con;
			return con;
		}	
		else{
			while( q-> ch != lt && q -> next !=0)
			{
				q = q->next;
			}
			if(q -> ch ==lt)
			{
				return q;
			}		
			else{
				Node * em = new Node(lt);
				q ->next= em;
				return em;
			}
		}
	}

	Node * SearchLetter(char lt, Node* p)const
	{
		Node *q = p->child;

		while( q != 0)
		{
			if(q -> ch == lt)
			{
				return q;
			}
			q= q-> next;
		}
		return 0;
	}
public:
	DicTree(){
		root = new Node;
	}
	
	void AddWord(const char *word, const char *ng )
	{
		//cout<<"\t\tnghia: "<<ng<<endl;
		Node *p = root;

		for(int i=0; i< strlen(word); i++)
		{
			p = AddLetter(word[i], p);
			//cout<<p->ch<<"";
		}
		//cout<<"\n";

		Node * pe = new Node('#', ng);
		
		Node * q = p -> child;
		if( q == 0)
		{
			p->child = pe;;
			//cout<<"1: "<<p->child -> ch<<" "<<p->child-> nghia<<endl;
		}
		else
		{
			while(q -> ch != '#' && q-> next != 0)
			{
				q = q->next;
			}	
			if(q->next ==0)
			{
				q-> next = pe;
			}	
			//cout<<"2: "<<p->next-> nghia<<endl;
		}
	}
	bool Search(const char* word)const
	{
		Node *p= root;
		
		for(int i=0; i< strlen(word); i++)
		{
			p = SearchLetter(word[i], p);
			//cout<<p->ch<<"  ";
			if(p ==0)
			{
				return 0;
			}
		}
		Node * q = p -> child;
		while( q != 0)
		{
			if( q-> ch == '#')
				return 1;
			q = q-> next;
		}
		return 0;
	}
	const char* Translate(const char* word)const
	{
		Node *p= root;
		for(int i=0; i< strlen(word); i++)
		{
			p = SearchLetter(word[i], p);
			
			if(p ==0)
			{
				return 0;
			}
		}
		Node * q = p -> child;
		while( q != 0)
		{
			cout<<q->ch<<"\n\t";
			if( q -> ch == '#'){
				return q->nghia;
			}
			q = q-> next;
		}
		return 0;
	}
	
};

#endif