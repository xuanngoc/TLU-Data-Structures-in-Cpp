#ifndef stack_h
#define stack_h

#include "node.h"

template <class T>
class Stack
{
public:
	Stack()
	{
		top = 0;
	};
	void Push(T val)
	{
		Node<T> * p = new Node<T>;
		p->data = val;
		p->next = top;
		top = p;
	};
	T Pop()
	{
		T t = top->data;
		Node<T> * q = top;
		top=  top->next;
		delete q;
		return t;
	};
	bool isEmpty()const{
		return top ==0;
	}
private:
	Node <T> * top;
	
};
#endif