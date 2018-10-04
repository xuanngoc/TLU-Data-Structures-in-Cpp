#ifndef tree_h
#define tree_h
#include "node.h"
#include "queue/queue.h"
#include "list/linkedList.h"

#define Max1(a, b) (a > b ? a : b)
#define Min1(a, b) (a < b ? a : b)

template <class T>
class BinaryTree
{
private:
	Node<T> * root;

	T max(Node<T> * root)const
	{
		if(root == 0)
		{
			return -1;
		}
		T t= root -> data;
		
		return t = max(root->left) > t ? max(root->left) : max(root-> right) > t ? max(root-> right): t;
	}
	

	int height(Node<T> * root)const{
		if(root == 0){
			return 0;
		}
		return  1 + Max1(height(root->left), height(root -> right));
	}
	int size(Node<T> * root)const{
		if( root == 0){
			return 0;
		}
		return 1+ size(root->left) + size(root -> right);
	}
	void PrintIn(Node<T> *root) const
    {        
        if (root != 0)
        {
            PrintIn(root->left);
            cout<<root->data<<" -- ";
            PrintIn(root->right);
        }
    }
    void PrintPre(Node<T> *root) const
    {        
        if (root != 0)
        {
            cout<<root->data<<" -- ";
            PrintPre(root->left);
            PrintPre(root->right);
        }
    }
    void PrintPost(Node<T> *root) const
    {        
        if (root != 0)
        {
            PrintPost(root->left);
            PrintPost(root->right);
            cout<<root->data<<" -- ";
        }
    }
    List<T> breadthFirst(Node<T> *root)const{
    	List<T> rs;
    	if(root ==0){
    		return rs;
    	}
    	Queue<Node<T> *> qu;
    	qu.EnQueue(root);
    	while( !qu.isEmpty()){
    		Node<T> * t = qu.DeQueue();
    		rs.pushBack( t -> data );
    		//cout<<t -> data<<" -- ";
    		if(t -> left != 0){
    			qu.EnQueue(t -> left);
    		}
    		if( t -> right){
    			qu.EnQueue(t -> right);
    		}
    	}
    	cout<<"here ";
    	rs.print();
    	return rs;
    };
public:
	BinaryTree()
	{
		root =0;
	}
	void AddChild(T const & val)
	{
		Node<T> * n = new Node<T>(val);
		if(!root){
			root  = n;
		}else{
			Queue<Node<T> *> q;
			Node<T> * p = root;
			q.EnQueue(p);
			while( ! q.isEmpty()){
				Node<T> *t  =q.DeQueue();
				if(t -> left == 0){
					t -> left = n;
					break;
				}else if( t -> right == 0){
					t -> right = n;
					break;
				}else{
					q.EnQueue(t -> left );
					q.EnQueue(t -> right );
				}
			}
		}
	}
	void printRoot(){
		cout<<root -> data<<endl;
	}
	T Max()const
	{
		//cout<<root -> data << endl;
		return max(root);
	}
	
	void Add(T const &val1, T const val2)
	{

	}
	int Height()const{
		return height(root) -1 ;
	}
	int Size()const{
		return size(root);
	}
	void InOrder()const{
		PrintIn(root);
		cout<<endl;
	}
	void PreOrder()const{
		PrintPre(root);
		cout<<endl;
	}
	void PostOrder()const{
		PrintPost(root);
		cout<<endl;
	}
	List<T> BreadthFirst()const{
		
		return breadthFirst(root);
	}
	/*void print()const{
		List<T> t = BreadthFirst();
		int n=height(root);
		int x=1;
		int c =1;
		for(int i=0; i< n ; i++){
			for(int k=i; k< n; k++){
				cout<<"\t";
			}
			for(int l = i; l < c ; l++){\
				if(!t.isEmpty()){
					cout<<t.getValue(x)<<"      ";
					x++;
				}
				else
					break;
			}
			c+=2;
			cout<<endl;
		}
	}*/
};

#endif