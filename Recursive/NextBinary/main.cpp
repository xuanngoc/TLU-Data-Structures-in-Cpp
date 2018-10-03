#include <iostream>
using namespace std;

void binary(int const &pos, int rs[], int const &n)
{
	if( pos > n)
	{
		for(int i=0; i< n; i++){
			cout<<rs[i];
		}
		cout<<endl;
	}else{
		for(int i=0; i<= 1; i++){
			rs[pos-1] = i;
			binary(pos +1, rs, n);
			rs[pos-1] = i;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter a integer number: ";
	cin >>n;
	int rs[100];
	binary(1, rs, n);
	return 0;
}