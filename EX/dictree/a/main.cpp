#include <iostream>
using namespace std;
#include "dictree.h"

int main()
{
	DicTree dic;
	dic.AddWord("HELLO");
	dic.AddWord("HELL");
	dic.AddWord("HELP");
	cout<<dic.Search("HELLO")<<endl;
	cout<<dic.Search("HEELO")<<endl;
	cout<<dic.Search("HELL")<<endl;

}
