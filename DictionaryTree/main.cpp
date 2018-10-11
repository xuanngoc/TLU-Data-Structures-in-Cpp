#include <iostream>
using namespace std;
#include "DicTree.h"
int main()
{
	DicTree tr;
	tr.AddWord("HELLO");
	tr.AddWord("HELL");
	tr.AddWord("HAPPY");
	tr.AddWord("SPACE");
	tr.AddWord("SPRITE");
	tr.AddWord("DOCUMENT");
	cout<<"\t"<<tr.Search("HELLO")<<endl;;
	cout<<"\t"<<tr.Search("HELL")<<endl;;
	cout<<"\t"<<tr.Search("HAPPY")<<endl;

	return 0;
}