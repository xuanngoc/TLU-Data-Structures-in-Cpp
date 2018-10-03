#include <iostream>
using namespace std;
#include "Tree.h"

int main()
{
	BinaryTree<int> t;
	t.AddChild(3);
	t.AddChild(32007);
	t.AddChild(32014);
	t.AddChild(32021);
	t.AddChild(32028);
	t.AddChild(32162);
	t.AddChild(32163);
	t.AddChild(31970);

	t.InOrder();
	t.PreOrder();
	t.PostOrder();
	t.print();
	//cout<<t.Height()<<endl;
	//t.BreadthFirst();
	//cout<<t.Height()<<endl;;
	//cout<<Max(2, 4)<<endl;
	return 0;
}