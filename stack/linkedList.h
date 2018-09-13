#ifndef list_h
#define list_h

#include "node.h"
#include <iostream>
using namespace std;
template <class T>
class List{ 
private:
	Node<T> * head;
public:
	List(): head(0){}
	List(T const &val, int const &loop){
		head =0;
		
		for(int i=0; i < loop; i++){
			Node <T> *n = new Node<T>;
			n -> data = val;
			n -> next = 0;
			if(head == 0){
				head =  n;
			}else{
				Node <T> * p =  head;
				while( p -> next != 0 ){
					p = p->next;
				}
				p->next = n;
			}		
		}

	}
	void pushBack(T v){
		Node <T> *n = new Node<T>;
		n -> data = v;
		n -> next = 0;
		if(head == 0){
			head =n;
		}else{
			Node <T> * p =  head;
			while( p -> next != 0 ){
				p = p->next;
			}
			p->next = n;
		}	
	}
	void deleteAt(int const &pos){
		if(pos ==1){
			Node<T> * p= head;
			head = head->next;
			delete p;
			return;
		}
		Node<T> * p = head;
		for(int i=1; i< pos-1; i++){
			p = p-> next;
		}
		Node<T> * q = new Node<T>;
		q = p-> next;
		p->next = p->next->next;
		delete q;
	}
	void insert(T const &value, int const &pos){
		Node<T> * n = new Node<T>;
		n->data = value;
		n-> next = 0;
		if(pos == 1){
			Node<T> * p= head;
			head  = n;
			n-> next = p ;
		}else{
			Node<T> * p= head;
			for(int i=1; i< pos-1; i++){
				p = p -> next;
			}
			n->next = p->next;
			p->next= n;
		}
	}
/*	void swap(int const &pos1, int const &pos2){
		if(pos1 == pos2)
			return;
		//take Node at pos1
		Node<T> * x= head;
		Node<T> * preX= 0;
		for(int i=1; i< pos1; i++){
			preX = x;
			x=x->next;
		}
		//take Node at pos2
		Node<T> * y= head;
		Node<T> * preY= 0;
		for(int i=1; i< pos2; i++){
			preY = y;
			y = y->next;
		}

		if(preX != 0)
			preX->next = y;
		else
			head = y;
		if(preY != 0)
			preY->next = x;
		else
			head = x;
		// let swap
		Node<T> * temp = new Node<T>;
		temp = y->next;
		y->next = x->next;
		x->next = temp;

	}*/
	void swap(int const &pos1, int const &pos2) { 
		Node<T> * x= head;

		for(int i=1; i< pos1; i++){
			x=x->next;
		}
		Node<T> * y= head;
		for(int i=1; i< pos2; i++){
			y = y->next;
		}
	    int temp = x->data; 
	    x->data = y->data; 
	    y->data = temp; 
	} 
	int Size()const{
		Node<T> * p = head;
		int counter=0;
		while(p!= 0){
			counter++;
			p=p->next;
		}
		return counter;
	}
	void sort(){
		/*Node<T> * p= head;
		Node<T> * q = head;
		Node<T> * temp = 0;
		for(int i=0; i< Size(); i++){
			p=q=head;
			while(q->next != 0){
				if(q->data > q->next->data){
					temp = q-> next;
					q-> next = q->next->next;
				}
			}
		}*/
	}
	bool has(T const &value){
		Node<T> *p= head;
		while(p!= 0){
			if(p-> data == value){
				return 1;
			}
			p=p->next;
		}
		return 0; 
	}

	void print()const{
		Node <T> * p = head;
		while(p != NULL){
			cout<<p-> data <<"  ";
			p= p->next;
		}
		cout<<endl;
	}
};
#endif