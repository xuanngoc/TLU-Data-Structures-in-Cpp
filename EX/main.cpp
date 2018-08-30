#include "mylib.h"

int main(){
	int arr[100000];
	int n = 0;
	bool f= true;
	do{
		int c = menu();
		switch (c){
			case 1:{
				themMotSo(arr, n);
				break;
			}	
			case 2:{
				hienThiCacSo(arr, n);
				break;				
			}
			case 3:{
				napKhoSoTuFile(arr, n);
				break;
			}
			case 4:{
				LuuKhoSoXuongFile(arr, n);
				break;
			}
			case 5:{
				SinhKhoSoNgauNhien(arr, n);
				break;
			}
			default:{
				f= false;
				cout<<"\nThoat chuong trinh\n";
				break;
			}

		};
		cin.ignore();
		cin.get();
		system("clear");
	}while(f);
}