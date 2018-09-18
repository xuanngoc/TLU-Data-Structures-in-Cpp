#ifndef stack_h
#define stack_h

#include "node.h"
#include <fstream>

template <class T>
class Stack
{
private:
	Node <T> * top;
	

public:
	Stack()
	{
		top = 0;
	};
	Stack(T const & val, int const &loop ){
		top = 0;
		for(int i=0; i< loop; i++){
			Node<T> * p = new Node<T>(val);
			p->next = top;
			top = p;
		}
	}
	Stack(char * filename){
		ifstream fin(filename);
		if(!fin.is_open() ){
			cout<<"Can't open file !!!\n";
			return;
		}
		top = 0;
		while(!fin.eof()){
			T t;
			fin >>t;
			Node<T> *p = new Node<T>(t);
			p->next = top;
			top = p;	
		}
		fin.close();
	}

	void Push(T const &val)
	{
		Node<T> * p = new Node<T>;
		p->data = val;
		p->next = top;
		top = p;
	};
	void Push(Stack st){
		Node <T> * q = st.top;
		while(q != 0){
			Node<T> * t = new Node<T>(st.Pop());
			t->next = top;
			top = t;
			q=st.top;
		}
	}
	T Pop()
	{
		T t = top->data;
		Node<T> * q = top;
		top=  top->next;
		delete q;
		return t;
	};
	T getTop()const{
		return top->data;
	}
	void deleteAt(int const & pos){
		Node<T> * p = top;
		for(int i=0; i< pos -1; i++){
			p=p->next;
		}
		Node<T> * q = p-> next;
		p->next= p->next->next;
		delete q;
	}
	void swap(int const &pos1, int const &pos2){
		Node<T> * p = top;
		for(int i=1; i< pos1; i++){
			p=p->next;
		}
		Node<T> * q = top;
		for(int i=1; i< pos2; i++){
			q=q->next;
		}
		T t = p->data;
		p->data = q->data;
		q->data = t;
	}
	void swap(Stack &st){
		Node<T> * p  = top;
		top = st.top;
		st.top= p;   
	}
	bool isEmpty()const{
		return top ==0;
	}
	void sort(){
		Node<T> *p = top;
		while(p != 0){
			Node<T> * q= p->next;
			while( q != 0){
				if( p-> data > q->data){
					T t = p->data;
					p->data = q->data;
					q->data = t;
				}
				q=q->next;
			}
			p=p->next;
		}
	}
	int size()const{
		int counter=0;
		Node<T> * p =top;
		while(p != top){
			counter++;
			p=p->next;
		}
		return counter;
	}
	int count(T const &val){
		int c=0;
		Node<T> * p = top;
		while(p != 0){
			if(p->data == val){
				c++;
			}
			p=p->next;
		}
		return c;
	}
	void has(T const &val){
		Node<T> * p = top;
		while(p != 0){
			if(p->data = val){
				return 1;
			}
			p=p->next;
		}
		return 0;
	}
	void operator + (T const &value){
		Node <T> * p = top;
		while(p != 0){
			p->data += value;
			p=p->next;
		}
	}
	void operator - (T const &value){
		Node <T> * p = top;
		while(p != 0){
			p->data -= value;
			p=p->next;
		}
	}
	void operator *(T const &value){
		Node <T> * p = top;
		while(p != 0){
			p->data *= value;
			p=p->next;
		}
	}
	void operator /(T const &value){
		Node <T> * p = top;
		while(p != 0){
			p->data /= value;
			p=p->next;
		}
	}
	void print()const{
		Node<T> *p =top;
		while(p != 0){
			cout<<p -> data<<"  ";
			p=p->next;
		}
		cout <<endl;
	}
};
#endif