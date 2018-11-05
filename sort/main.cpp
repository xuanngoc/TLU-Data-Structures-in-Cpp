#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "mylib.h"
#include "mySortLib.h"



int main()
{
	int *a = new int[100];
	Random(a, 10);
	print(a, 10);
	cout<<endl;
	mergeSort(a,0, 9);
	cout<<"\n\n-----------------------\n";
	print(a, 10);
}