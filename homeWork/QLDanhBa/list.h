#include "node.h"
#include <fstream>

template <class T>
class List{
private:
	Node <T> * head;
public:
	List(): head(0){}
	List(T const &value, int const &loop){
		head =0;
		for(int i=0; i< loop; i++){
			Node<T> * n = new Node<T>(value);
			if(head ==0){
				head = n;
			}else{
				Node<T> *p = head;
				while(p->next != 0){
					p= p->next;
				}
				p->next = n;
			}
		}
	}
	List(char * filename){
		head =0;
		ifstream fin(filename);
		if(!fin.is_open()){
			cout<<"File isn't exist!!!\n";
			return;
		}
		while(!fin.eof()){
			T temp;
			fin>>temp;
			Node<T> * n = new Node<T>(temp);
			if(head ==0){
				head = n;
			}else{
				Node<T> *p = head;
				while(p->next !=0){
					p=p->next;
				}
				p->next = n;
			}
		}
		fin.close();
	}
	void pushBack(T const &value){
		Node<T> * n = new Node<T>;
		n->data = value;
		n->next = 0;
		
		if(head == 0){
			head = n;
		}else{
			Node<T> *p = head;
			while(p->next != 0){
				p=p->next;
			}
			p->next = n;
		}
	}
	T getAt(int const &pos){
		Node<T> *p = head;
		for(int i=1; i< pos; i++){
			p = p->next;
		}
		return p->data;
	}
	void change(int const &pos, T const &value){
		Node<T> * p = head;
		for(int i=1; i< pos; i++){
			p=  p-> next;
		}
		p->data = value;
	}
	void pushTop(T const & value){
		Node<T> * n = new Node<T>(value);
		Node<T> *p = head;
		head = n;
		n-> next = p;
	}
	void deleteLast(){
		Node<T> * p = head;
		while(p->next->next != 0){
			p=p->next;
		}
		p->next=0;
		delete p->next;

	}
	void deleteFirst(){
		Node<T> * p = head;
		head=head -> next;
		delete p;

	}
	T last()const{
		Node<T> * p= head;
		while(p->next != 0){
			p=p->next;
		}
		return p->data;
	}
	T first()const{
		return head -> data;
	}
	void clear(){
		Node<T> *p = head;
		while(p != 0){
			Node<T> * q = head;
			head=head->next;
			delete q;
			p=p->next;
		}
	}
	void insertBefore(int const &pos, T const &value){
		Node<T> * n = new Node<T>(value);
		if(pos ==1){
			pushTop(value);
		}else{
			Node<T> *p = head;
			for(int i=1; i< pos-1; i++){
				p=p->next;
			}
			Node<T> * q = p->next;
			p -> next = n;
			n -> next = q;
		}
	}
	void insertAfter(int const &pos, T const &value){
		Node<T> * n = new Node<T>(value);
		if(pos ==1){
			pushTop(value);
		}else{
			Node<T> *p = head;
			for(int i=1; i< pos; i++){
				p=p->next;
			}
			Node<T> * q = p->next;
			p -> next = n;
			n -> next = q;
		}
	}

	void swap(int const & pos1, int const &pos2){
		if(pos1 == pos2)
			return;
		Node<T> * p = head;
		for(int i=1; i < pos1; i++){
			p = p-> next;
		}
		Node<T> * q = head;
		for(int i=1; i< pos2; i++){
			q = q -> next;
		}
		T temp = p->data;
		p -> data = q -> data;
		q -> data = temp;
	}
	/*	void swap(int const &pos1, int const &pos2){
		if(pos1 == pos2)
			return;
		//take Node at pos1
		Node<T> * x= head;
		Node<T> * preX= 0;
		for(int i=1; i< pos1; i++){
			preX = x;
			x=x->next;
		}
		//take Node at pos2
		Node<T> * y= head;
		Node<T> * preY= 0;
		for(int i=1; i< pos2; i++){
			preY = y;
			y = y->next;
		}

		if(preX != 0)
			preX->next = y;
		else
			head = y;
		if(preY != 0)
			preY->next = x;
		else
			head = x;
		// let swap
		Node<T> * temp = new Node<T>;
		temp = y->next;
		y->next = x->next;
		x->next = temp;

	}*/
	int count(T const & value)const{
		int counter=0;
		Node<T> * p= head;
		while(p !=0 ){
			if(p-> data == value){
				counter ++;
			}
			p=p->next;
		}
		return counter;
	}
	void deleteAt(int const &pos){
		if(pos == 1){
			Node<T> * q = head;
			head=head->next;
			delete q;
		}else{
			Node<T> * p = head;
			for(int i=1; i< pos-1  ; i++){
				p=p -> next;
			}
			Node<T> * q = p;//new Node<T> ;
			q= p->next;
			p->next = p->next->next;
			delete q;
		}
	}
	void deleteValues(T const & value){
		Node<T>  *p= head;
		int k=0;
		while(p != 0){
			k++;
			if(p->data == value){
				deleteAt(k);
				k--;
			}
			p=p->next;
		}
	}
	void sort(){
		Node<T> *p = head;
		while(p !=0){
			Node<T> * q = p->next;
			while(q !=0){
				if( p->data > q -> data){
					T temp = p->data;
					p->data = q->data;
					q->data = temp;
				}
				q=q->next;
			}
			p=p->next;
		}
	}
	void deleteAtoB(int const& pos1, int const &pos2){
		Node<T> * p = head;
		for(int i=1; i<pos1-1; i++){
			p=p->next;
		}
		Node<T> * q = head;
		for(int i=1; i< pos2 -1 ; i++){
			q=q->next;
		}
		while(p->next != q->next->next){
			Node <T> *t = p;
			t= p->next;
			p->next = p->next->next;
			delete t; 
		}
	}
	bool has(T const &value)const{
		Node<T> *p= head;
		while(p !=0){
			if(p->data == value)
				return 1;
			p=p->next;
		}
		return 0;
	}
	T max()const{
		T max = head->data;
		Node<T> * p = head->next;
		while(p != 0){
			if(max < p->data){
				max= p->data;
			}
			p=p->next;
		}
		return max;
	}
	T min()const{
		T max = head->data;
		Node<T> * p = head->next;
		while(p != 0){
			if(max > p->data){
				max= p->data;
			}
			p=p->next;
		}
		return max;
	}
	List subList(int const &pos1, int const &pos2){
		Node<T> * p = head;
		for(int i=1; i<pos1; i++){
			p=p->next;
		}
		Node<T> * q= head;
		for(int i=1; i< pos2; i++){
			q=q->next;
		}
		List<T> result;
		while(p != q->next){
			T temp = p->data;
			result.pushBack(temp);
			p=p->next;
		} 
		return result;
	}
	List getIndex(T const &value)const{
		Node<T> * p =head;
		List<T> result;
		int index=1;
		while(p != 0){
			T temp = p->data;
			if(temp == value){
				result.pushBack(index);
			}
			p=p->next;
			index++;
		}
		return result;
	}
	void reverse(){
		Node<T> * pre = 0;
		Node<T> * cur = head;
		Node<T> * n= 0;
		while(cur != 0){
			n = cur->next;
			cur->next = pre;
			pre = cur;
			cur = n;
		}
		head = pre;
		
	}
	int size()const{
		Node<T> * p = head;
		int counter =0;
		while(p != 0){
			counter++;
			p = p->next;
		}
		return counter;
	}
	bool isEmpty()const{
		return head ==0;
	}
	void operator + (int const& value){
		Node<T> * p = head;
		while(p != 0){
			p->data += value;
			p=p->next;
		}
	}
	void operator * (int const& value){
		Node<T> * p = head;
		while(p != 0){
			p->data *= value;
			p=p->next;
		}
	}
	void operator - (int const& value){
		Node<T> * p = head;
		while(p != 0){
			p->data -= value;
			p=p->next;
		}
	}
	void operator / (int const& value){
		Node<T> * p = head;
		while(p != 0){
			p->data /= value;
			p=p->next;
		}
	}
	void print()const{
		Node<T> *p = head;
		while(p != 0){
			cout<<p->data<<"  ";
			p=p->next;
		}
		cout<<endl;
	}

};