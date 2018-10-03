#ifndef TreeNode_h
#define TreeNode_h

template <class T>
struct Node
{
	T data;
	Node<T> *right;
	Node<T> *left;
	Node(){
		right =0;
		left =0;
	}
	Node(T const val){
		data = val;
		right = 0;
		left = 0;
	}
};

#endif