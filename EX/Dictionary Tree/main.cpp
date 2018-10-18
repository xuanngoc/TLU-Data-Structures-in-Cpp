#include <iostream>
using namespace std;

#include "DicTree.h"
#include "mylib.h"
int main()
{
	DicTree td;
	
	

	td.AddWord("hello", "xin chao");
	td.AddWord("hell", "dia nguc");
	td.AddWord("bobo", "ngu");
	td.AddWord("application", "ung dung");
	td.AddWord("stupid", "ngu vc");
	td.AddWord("student", "hoc sinh");


	
	int c;
	do{
		cout<<"nhap 1-2: ";
		cin >>c;
		switch (c){
			case 1:{

				

				cout<<"---THEM TU----\n";
				char ta[10];
				cout<<"Nhap tu can them: ";
				cin >> ta;
				cout<<"Nhap nghia cua tu: ";
				char tv[20];
				//cin.ignore();
				//cin.getline(tv, 30);
				cin >> tv;
				cout<<ta<<tv<<endl;
				td.AddWord(ta, tv);
				break;
			}
			case 2:{
				cout<<"---Tra tu---\n";
				char tu[10];
				cout<<"Nhap tu can tra: ";
				cin >> tu;
				cout<<tu <<" co nghia la: "<<td.Translate(tu)<<endl;;
				break;
			}	
			default:
				c=0;
				break;	
		}
		cin.get();
	}while(c);
	
	return 0;
}
