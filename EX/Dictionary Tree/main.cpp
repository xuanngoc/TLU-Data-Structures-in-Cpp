#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "mylib.h"
#include "DicTree.h"
int main()
{
	DicTree td;

	/*char t[10]= "td.txt";
	td.ReadFile(t);*/
	int c;
	do{
		c = Menu();
		switch (c){
			case 1:{
				cout<<"--- Them tu ---\n";
				char *ta = new char[10];
				cout<<"Nhap tu can them: ";
				cin >> ta;
				cout<<"Nhap nghia cua tu: ";
				char *tv = new char[20];
				cin.ignore();
				cin.getline(tv, 30);
				ToUpper(ta);
				td.AddWord(ta, tv);
				break;
			}
			case 2:{
				cout<<"--- Tra tu ---\n";
				char *ta = new char[10];
				cout<<"Nhap tu can tra: ";
				cin >> ta;
				cout<<ta <<" co nghia la: "<<td.Translate(ToUpper(ta))<<endl;;
				cin.get();
				break;
			}	
			case 3:{
				cout<<"--- Them tu trong file ---\n";
				char *fname = new char[30];
				cin >> fname;
				td.ReadFile(fname);
				break;
			}
			default:
				c = 0;
				break;
		}
		cin.get();
		system("clear");
	}while(c);
	return 0;
}
