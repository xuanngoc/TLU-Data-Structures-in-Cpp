#ifndef queue_h
#define queue_h
#include "node.h"
#include <fstream>
template <class T>
class Queue
{
private:
	Node<T> * queue;
public:
	Queue(){
		queue =0;
	}
	Queue(T const &value, int const &loop){
		queue = 0;
		for(int i=0; i< loop; i++){

			Node<T> *n = new Node<T>;
			n-> data = value;
			n-> next = 0;
			if(queue == 0)
			{	
				queue = n;
			}else
			{
				Node<T> * p = queue;
				while(p->next != 0)
				{
					p=p->next;
				}
				p->next = n;		
			}	
		}
			
	}
	Queue(char * filename){
		queue =0;
		ifstream fin(filename);
		//cout<<"filename = "<<filename<<endl;
		if(!fin.is_open()){
			cout<<"File isn't exist !!!\n";
			return;
		}
		while(!fin.eof()){
			T temp;
			fin>>temp;
			Node<T> * n = new Node<T>(temp);
			if(queue ==0){
				queue = n;
			}else{
				Node<T> *p = queue;
				while(p->next !=0){
					p=p->next;
				}
				p->next = n;
			}
		}
		fin.close();
	}

	void EnQueue(T const &val)
	{	
		Node<T> *n = new Node<T>;
		n-> data = val;
		n-> next = 0;
		if(queue == 0)
		{	
			queue = n;
		}else
		{
			Node<T> * p = queue;
			while(p->next != 0)
			{
				p=p->next;
			}
			p->next = n;		
		}	
	}
	T DeQueue()
	{
		T t = queue->data;
		Node<T> * q = queue;
		queue=  queue->next;
		delete q;
		return t;
	}
	bool isEmpty()const{
		return queue ==0;
	}
	void deleteAt(int const &pos){
		if(pos == 1){
			Node<T> * q = queue;
			queue= queue->next;
			delete q;
		}else{
			Node<T> * p = queue;
			for(int i=1; i< pos-1; i++){
				p = p->next;
			}
			Node<T> *q = p->next;
			p->next = p->next->next;
			delete q;
		}
	}
	void sort(){
		Node<T> * p = queue;
		while(p != 0){
			Node<T> * q = p->next;
			while(q != 0){
				if(p-> data > q->data){
					T t = p->data;
					p->data = q->data;
					q->data = t;
				}
				q = q->next;
			}
			p=p->next;
		}
	}
	bool has(T const &value){
		Node<T> * p = queue;
		while(p != 0){
			if(p->data == value){
				return 1;
			}
			p=p->next;
		}
		return 0;
	}
	T top()const{
		return queue->data;
	}
	T last()const{
		Node<T> * p = queue;
		while( p->next != 0){
			p=p->next;
		}
		return p-> next;
	}

	void operator + (T const &value){
		Node<T> *p = queue;
		while(p != 0){
			p->data += value;
			p = p->next;
		}
	}
	void operator - (T const &value){
		Node<T> *p = queue;
		while(p != 0){
			p->data -= value;
			p = p->next;
		}
	}
	void operator * (T const &value){
		Node<T> *p = queue;
		while(p != 0){
			p->data *= value;
			p = p->next;
		}
	}
	void operator / (T const &value){
		Node<T> *p = queue;
		while(p != 0){
			p->data /= value;
			p = p->next;
		}
	}

	void swap(int const & pos1, int const &pos2){
		Node<T> *p =queue;
		for(int i=1; i< pos1; i++){
			p=p->next;
		}
		Node<T> *q =queue;
		for(int i=1; i< pos2; i++){
			q=q->next;
		}
		T temp = p->data;
		p->data = q->data;
		q->data =temp;
	}
	void swap(Queue<T> &qu){
		Queue<T> t = *this;
		*this = qu;
		qu = t;
	}
	int size()const{
		Node<T> * p =queue;
		int counter=0;
		while(p != 0){
			counter++;
			p=p->next;
		}
		return counter;

	}
	void print()const{
		Node<T> * p =queue;
		while(p != 0){
			cout<<p->data<<"  ";
			p=p->next;
		}
		cout<<endl;
	}
};
#endif