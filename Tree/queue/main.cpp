#include <iostream>
using namespace std;
#include "queue.h"

int main(){
	
	char a[100] = "dl.txt";
	Queue<int> qu(a);
	qu.print();

	Queue<int> qu1;
	qu1.EnQueue(111);
	qu1.EnQueue(1521);
	qu1.EnQueue(523215);
	qu1.EnQueue(515);
	qu1.EnQueue(3215);
	qu1.EnQueue(2925);
	qu1.EnQueue(25);

	qu1.print();

	cout<<qu1.has(111)<<endl;
	qu1.print();
	return 0;
}