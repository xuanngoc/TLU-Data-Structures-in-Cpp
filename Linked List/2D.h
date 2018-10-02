# include "node2D.h"

template <class T>
class List2D{
private:
	Node<T> *head;
public:
	List2D(){
		//head =0;
		head -> right = 0;
		head -> down =0;
	}

	void Add(int const &a, int const &b, T const &val){
		if( a ==0 && b ==0){
			Node<T> * n = new Node<T>;
			n->data = val;
			head = n;
			cout<<"ok\n";
		}else{
			Node<T> * p = head;
			cout<<"head ="<<head->data<<endl;
			
			for(int i=1; i< b; i++){
				p= p->right;
			}
			for(int i=1; i< a; i++){
				p= p->down;
			}
			p->data =val;
			cout<<p->data<<endl;
			cout<<"head ="<<head->data<<endl;

		}
	}
	T get(int const &a, int const &b)const{
		Node<T> * p = head;//->right;
		for(int i=1; i< b; i++){
			p= p->right;
		}
		for(int i=1; i< a; i++){
			p= p-> down;
		}
		return p->data;
	}
	void print()const{
		Node<T> * p = head;
		//cout<<head->data<<endl;
		/*while( p != 0){
			Node <T> *q = p;
			while(q != 0){
				cout<<q->data<<"--";
				q=q-> right;
			}
			cout<<endl;
			p=p->down;

		}*/
	}
};
