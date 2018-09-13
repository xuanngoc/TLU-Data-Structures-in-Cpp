#ifndef queue_h
#define queue_h
#include "node.h"

template <class T>
class Queue
{
private:
	Node<T> * queue;
public:
	Queue(){
		queue =0;
	};
	void EnQueue(T val)
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
};
#endif