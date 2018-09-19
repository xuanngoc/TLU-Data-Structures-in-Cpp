#include <iostream>
using namespace std;
#include "dathuc.h"

int main(){
	DaThuc dt(4);
	dt.print();
	dt.setHeSo(2, 5);
	dt.print();
	dt.setHeSo(3, 0);
	dt.print();
	dt.setHeSo(1, -4);
	dt.print();
	cout << dt.Calc(2)<<endl;
	DaThuc p;
	p.print();
	return 0;
}