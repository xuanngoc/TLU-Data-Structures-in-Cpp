#include <iostream>
using namespace std;
#include "Tree.h"

int main()
{
	BinaryTree<int> t;
	t.AddChild(10);
	t.AddChild(6);
	t.AddChild(15);
	t.AddChild(2); 
	t.AddChild(877);
	t.AddChild(11);
	t.AddChild(13);

	t.InOrder();
	t.PreOrder();
	t.PostOrder();
	//t.printRoot();
	//cout<<t.Height() << endl;
	cout <<t.Max()<<endl;

	return 0;
}