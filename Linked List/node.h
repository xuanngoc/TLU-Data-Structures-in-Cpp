#pragma one

template <class T>
struct Node{
	T data;
	Node * next;
	Node(T _data){
		data = _data;
		next = 0;
	}
	Node(){
		next=0;
		
	}
};