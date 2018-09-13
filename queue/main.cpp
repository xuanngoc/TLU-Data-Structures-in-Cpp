#include "queue.h"
#include <iostream>
using namespace std;

int main(){
	Queue<int> qu;
	qu.EnQueue(5);
	qu.EnQueue(15);
	qu.EnQueue(55);
	cout<<qu.DeQueue()<<endl;
	cout<<qu.DeQueue()<<endl;
	cout<<qu.DeQueue()<<endl;
	cout<<qu.isEmpty()<<endl;


	return 0;
}