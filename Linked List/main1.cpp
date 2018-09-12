
#include "linkedList.h"

int main(){
	List<int> a(32007, 2);
	a.pushBack(32);
	a.pushBack(32011);
	
	a.pushBack(3);

	a.pushBack(3922);
	

	a.print();

	/*a.deleteAt(11);
	a.print();*/
	a.insert(100, 1);
	a.print();
	a.insert(32014, 7);
	a.print();
	a.swap(2, 1);
	a.print();
	a.sort();
	a.print();
	a.sort();
	a.sort();
	a.sort();
	
	a.print();
		

}