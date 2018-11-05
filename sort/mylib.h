void swap(int &a, int &b){
	int temp = a;
	a= b;
	b= temp;
}

void Random(int a[], int n){
	srand(time(0));
	for(int i=0; i< n; i++)
		a[i] = rand() % 100;
}
void print(int a[], int n){
	for(int i=0; i< n; i++)
		cout<<a[i] <<"  ";
	cout<<endl;
}