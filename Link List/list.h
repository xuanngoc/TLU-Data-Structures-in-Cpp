#include <iostream>
#include "node.h"
using namespace std;

template < class T>
class List
{
private:
	Node <T> * head;
public:
	List(): head(0){};
	void Add(T v){
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
	int Count()const{
		Node <T> * p =  head;
		int counter =0;
		while( p -> next != 0 ){
			p = p->next;
			counter++;
		}
		return counter+1;	
	}	
	void Del(int const &pos){
		 if(pos == 1){
		 	Node <T> *q = head;
		 	head = head -> next;
		 	delete q;
		 }
		 else{
		 	Node <T> *p = head;
		 	for(int i=1; i< pos-1; i++){
		 		p = p->next;
		 	}
		 	Node <T> *q = p->next;
		 	p->next= p->next->next;
		 	delete q;
		 }
	}
	void Change(int const &pos, T const &v){
		Node <T> *p = head;
		for(int i=1; i< pos; i++){
			p= p-> next;
		}
		p -> data = v;
	}
	
	void Insert(int const &pos, T const &val){
		Node <T> *temp = new Node<T>;
		temp -> data = val;
		temp -> next = NULL;
		if( pos == 1){
			Node <T> *p = head;
			temp -> next = head;	
			head = temp;
			temp = p;
			return;
		}
		Node <T> *p = head;
		for(int i=1; i< pos-1; i++){
			p= p-> next;
		}
		temp -> next = p-> next;
		p-> next =  temp;

	}
	/*
	void Swap(int const &pos1, int const &pos2){
		
	}*/
	int Count(T val){
		int counter=0;
		Node <T> * p = head;
		while(p != NULL){
			if(p-> data == val){
				counter++;
			}
			p = p-> next;
		}
		return counter;
	}
	/*bool In(T const &val){
		
	}
	void Del(int const &pos1 , int const &pos2 ){
		
	}
	void DaoList(){
		
	}*/
	
	void PrintAll()const{
		Node <T> * p = head;
		while(p != NULL){
			cout<<p-> data <<"  ";
			p= p->next;
		}
		cout<<endl;
	}
};
