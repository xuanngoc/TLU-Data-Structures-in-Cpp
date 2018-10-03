#include <iostream>
using namespace std;

bool ChuaXuatHien(char const &a, char rs[], int const &n )
{
	for(int i=0; i < n; i++)
		if(rs[i] == a)
			return 0;
	return 1;	
}
void Permutation(int const &pos, char rs[], char const lt[], int const &n)
{
	if(pos > n){
		cout<<rs<<endl;
	}else{
		for(int i=1; i<= n; i++)
		{
			if(ChuaXuatHien(lt[i-1], rs, pos - 1 ) )
			{
				rs[pos -1] = lt[i-1];
				Permutation(pos+1, rs, lt ,n);
			}	
		}
	}
}

int main()
{
	int n;
	cout<<"Enter a integer number: ";
	cin >> n;
	char letters[100];
	for(int i=0; i<n; i++){
		cout<<"Enter a letter: ";
		cin >> letters[i];
	}
	char result[100];
	Permutation(1, result, letters, n);
	return 0;
}