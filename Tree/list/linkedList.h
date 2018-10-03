#include "LNode.h"
#include <fstream>

template <class T>

class List{
private:
	LNode <T> * head;
public:
	List(): head(0){}
	List(T const &value, int const &loop){
		head =0;
		for(int i=0; i< loop; i++){
			LNode<T> * n = new LNode<T>(value);
			if(head ==0){
				head = n;
			}else{
				LNode<T> *p = head;
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
		cout<<"filename = "<<filename<<endl;
		if(!fin.is_open()){
			cout<<"File isn't exist!!!\n";
			return;
		}
		while(!fin.eof()){
			T temp;
			fin>>temp;
			LNode<T> * n = new LNode<T>(temp);
			if(head ==0){
				head = n;
			}else{
				LNode<T> *p = head;
				while(p->next !=0){
					p=p->next;
				}
				p->next = n;
			}
		}
		fin.close();
	}
	void pushBack(T const &value){
		LNode<T> *n = new LNode<T>(value);
		
		if(head == 0){
			head = n;
		}else{
			LNode<T> *p = head;
			while(p->next != 0){
				p=p->next;
			}
			p->next = n;
		}
	}
	void pushTop(T const & value){
		LNode<T> * n = new LNode<T>(value);
		LNode<T> *p = head;
		head = n;
		n-> next = p;
	}
	void deleteLast(){
		LNode<T> * p = head;
		while(p->next->next != 0){
			p=p->next;
		}
		
		LNode<T> * q = p->next; // giu cai LNode cuoi cung
		p->next=0; //cho cai vi tri ap chot = 0
		delete q; //xoa phan tu cuoi cung

	}
	void deleteFirst(){
		LNode<T> * p = head;
		head=head -> next;
		delete p;

	}
	T last()const{
		LNode<T> * p= head;
		while(p->next != 0){
			p=p->next;
		}
		return p->data;
	}
	T first()const{
		return head -> data;
	}
	void clear(){
		LNode<T> *p = head;
		while(p != 0){
			LNode<T> * q = head;
			head=head->next;
			delete q;
			p=p->next;
		}
	}
	void insertBefore(int const &pos, T const &value){
		LNode<T> * n = new LNode<T>(value);
		if(pos ==1){
			pushTop(value);
		}else{
			LNode<T> *p = head;
			for(int i=1; i< pos-1; i++){
				p=p->next;
			}
			LNode<T> * q = p->next;
			p -> next = n;
			n -> next = q;
		}
	}
	void insertAfter(int const &pos, T const &value){
		LNode<T> * n = new LNode<T>(value);
		if(pos ==1){
			pushTop(value);
		}else{
			LNode<T> *p = head;
			for(int i=1; i< pos; i++){
				p=p->next;
			}
			LNode<T> * q = p->next;
			p -> next = n;
			n -> next = q;
		}
	}
	T getValue(int pos){
		if( pos == 1){
			return head -> data;
		}else{
			LNode<T> * p = head;
			for(int i=1; i< pos; i++)
				p =p-> next;
			return p->data;
		}
	}
	void swap(int const & pos1, int const &pos2){
		if(pos1 == pos2)
			return;
		LNode<T> * p = head;
		for(int i=1; i < pos1; i++){
			p = p-> next;
		}
		LNode<T> * q = head;
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
		//take LNode at pos1
		LNode<T> * x= head;
		LNode<T> * preX= 0;
		for(int i=1; i< pos1; i++){
			preX = x;
			x=x->next;
		}
		//take LNode at pos2
		LNode<T> * y= head;
		LNode<T> * preY= 0;
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
		LNode<T> * temp = new LNode<T>;
		temp = y->next;
		y->next = x->next;
		x->next = temp;

	}*/
	int count(T const & value)const{
		int counter=0;
		LNode<T> * p= head;
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
			LNode<T> * q = head;
			head=head->next;
			delete q;
		}else{
			LNode<T> * p = head;
			for(int i=1; i< pos-1  ; i++){
				p=p -> next;
			}
			LNode<T> * q = p;//new LNode<T> ;
			q= p->next;
			p->next = p->next->next;
			delete q;
		}
	}
	void deleteValues(T const & value){
		LNode<T>  *p= head;
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
		LNode<T> *p = head;
		while(p !=0){
			LNode<T> * q = p->next;
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
		LNode<T> * p = head;
		for(int i=1; i<pos1-1; i++){
			p=p->next;
		}
		cout<<"gia tri: "<<p->data<<"\n";

		LNode<T> * q = head;
		for(int i=1; i< pos2 -1 ; i++){
			q=q->next;
		}
		cout<<"gia tri: "<<q->data<<"\n\n";

		while(p->next != q->next->next){
			cout<<"gia tri: "<<p->data<<"\t";
			LNode <T> *t = p;
			t= p->next;
			cout<<"gia tri t : "<<t->data<<"\n";

			p->next = p->next->next;
			cout<<"gia tri: "<<p->data<<"\n";
			delete t; 
		}
	}
	bool has(T const &value)const{
		LNode<T> *p= head;
		while(p !=0){
			if(p->data == value)
				return 1;
			p=p->next;
		}
		return 0;
	}
	T max()const{
		T max = head->data;
		LNode<T> * p = head->next;
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
		LNode<T> * p = head->next;
		while(p != 0){
			if(max > p->data){
				max= p->data;
			}
			p=p->next;
		}
		return max;
	}
	List subList(int const &pos1, int const &pos2){
		LNode<T> * p = head;
		for(int i=1; i<pos1; i++){
			p=p->next;
		}
		LNode<T> * q= head;
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
		LNode<T> * p =head;
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
		LNode<T> * pre = 0;
		LNode<T> * cur = head;
		LNode<T> * n= 0;
		while(cur != 0){
			n = cur->next;
			cur->next = pre;
			pre = cur;
			cur = n;
		}
		head = pre;
		
	}
	int size()const{
		LNode<T> * p = head;
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
	T &operator [](int const & index){
		LNode <T> *  p  = head;
		for(int i=0; i<index ; i++){
			p=p->next;
		}
		return p->data;
	}
	void print()const{
		LNode<T> *p = head;
		while(p != 0){
			cout<<p->data<<"  ";
			p=p->next;
		}
		cout<<endl;
	}

};