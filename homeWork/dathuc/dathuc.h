#include "node.h"
#include <math.h>
class DaThuc{
private:
	Node *head;
public:
	DaThuc(){
		head = 0;
		/*head->heSo = 0;
		head->bac = 0;
		head ->next =0;*/
	}
	DaThuc(int b){
		head = 0;
		int n= b;	
		for(int i=0; i<= n; i++){
			Node *t = new Node(1, b--);
			if(head == 0){
				head = t;
				
			}else{
				Node *p = head;
				while( p -> next != 0){
					p = p -> next;
				}
				p -> next = t;
			}
		}
	}
	void setHeSo(int b, int val){
		Node *p = head;
		while(p->bac != b){
			p=p->next;
		}
		p->heSo = val;
	}
	DaThuc operator + (DaThuc a)const{
		int maxBac = a.head->bac > head->bac ? a.head->bac : head->bac;
		int minBac = a.head->bac < head->bac ? a.head->bac : head->bac;
		DaThuc kq(maxBac);
		cout<<maxBac<<" "<<minBac<<endl;

		if(a.head->bac == maxBac){
			int t = maxBac;
			Node *p = a.head;
			Node *q = head;
			for(int i=0; i< a.head->bac - head->bac; i++){
				kq.setHeSo(t--, p->heSo);
				p=p->next;
			}
			for(int i=0; i< minBac; i++){
				kq.setHeSo(t--, p->heSo + q -> heSo);
				p = p->next;
				q = q->next;
			}
		}else if( head->bac == maxBac){
			int t = maxBac;
			Node *p = head;
			Node * q = a.head;

			for(int i=0; i<  head->bac - a.head->bac ; i++){
				kq.setHeSo(t--, p->heSo);
				p=p->next;
			}
			for(int i=0; i< minBac; i++){
				kq.setHeSo(t--, p->heSo + q -> heSo);
				p = p->next;
				q = q->next;
			}
			
		} else{
			Node *p = head;
			Node * q = a.head;
			for(int i=0; i< minBac; i++){
				int t = minBac;
				kq.setHeSo(t--, p->heSo + q->heSo);
				p=p->next;
				q=q->next;
			}
			
		}
		return kq;
	}
	int Calc(int x)const{
		int kq=0;
		Node *p = head;
		while( p != 0){
			int t= pow(x, p->bac);
			//cout<<"t = "<<t<<endl;
			if(p->heSo != 0){
				kq += p->heSo * t;
				//<<"kq = "<<kq<<endl;
			}
			p=p->next;
		}
		return kq;
	}
	void print()const{
		if(head ==0){
			cout<<"0\n";
			return;
		}

		Node *p = head;
		while(p->next->next != 0){
			if(p->heSo ==0 ){
				cout<<"";
			}
			else if(p->heSo == 1){
				cout<<"x^"<<p->bac;//<<" + ";
				if(p->next->heSo < 0){
					cout<<" ";
				}else{
					cout<<" + ";
				}
			}else{
				cout<<p->heSo<<"x^"<<p->bac;//<<" + ";
				if(p->next->heSo < 0){
					cout<<" ";
				}else{
					cout<<" + ";
				}
			}
			p=p->next;
		}
		if(p->heSo ==1){
			cout<<"x ";
			if(p->next->heSo < 0){
					cout<<" ";
			}else{
					cout<<" + ";
			}
		}else{
			cout<<p->heSo<<"x ";
			if(p->next->heSo < 0){
					cout<<" ";
			}else{
					cout<<" + ";
			}
		}
		cout<<p->next->heSo<<endl;;
	}

};