#ifndef QueueNode_h
#define QueueNode_h

template <class T>
struct QNode{
	T data;
	QNode <T> *next;
	QNode(T const & val){
		data = val;
		next = 0;
	}
	QNode(){
		next = 0;
	}
};

#endif
/*void InRaGocTruoc(Node<T> *root) const
    {        
        if (root != 0)
        {
            cout<<root->data<<" -- ";
            InRaGocTruoc(root->left);
            InRaGocTruoc(root->right);
        }
    }*/