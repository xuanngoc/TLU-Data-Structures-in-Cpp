
#include <iostream>
using namespace std;
#include "2D.h"

int main(){

	List2D<int> a;
	a.Add(0, 0, 5);
	a.print();
	
	a.Add(1, 0, 15);
	//a.Add(0, 2, 550);
	/*a.Add(1, 0, 30);
	a.Add(1, 1, 32007);*/
	//a.Add(1, 2, 32014);
	//a.Add(2, 0, 30311);
	//a.Add(2, 1, 30333);
	//a.Add(2, 2, 33999);


	a.print();
	//cout<<a.get(1,1)<<endl;;

}