#pragma one

template <class T>
struct LNode{
	T data;
	LNode * next;
	LNode(T _data){
		data = _data;
		next = 0;
	}
	LNode(){
		next=0;
		
	}
};