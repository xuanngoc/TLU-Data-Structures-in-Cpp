#include <iostream>
using namespace std;
#include "dictree.h"

int main()
{
	DicTree dic;
	dic.AddWord("HELLO");
	dic.AddWord("HELL");
	dic.AddWord("HEY");
	dic.AddWord("NO");
	dic.AddWord("NOT");
	dic.AddWord("NEED");
	cout<<dic.Search("HELLO")<<endl;

	return 0;
}
