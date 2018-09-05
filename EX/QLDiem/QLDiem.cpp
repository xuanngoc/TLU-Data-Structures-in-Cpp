#include "mylib.h"


int main(){
	bool f = true;
	int c;
	vector <MonHoc> DSMH;
	do{
		c = menu();
		switch(c){
			case 1:{
				themMon(DSMH);
				break;
			}
			case 2:{
				themDiem(DSMH);
				break;
			}
			case 3:{
				inBangDiem(DSMH);
				break;
			}
			case 4:{
				tinhTrungBinhCong(DSMH);
				break;
			}
			case 5:{
				moBangDiem(DSMH);
				break;
			}
			case 6:{
				luuVaoFile(DSMH);
				break;
			}
			default:{
				f=false;
				break;
			}
		}
		cin.ignore();
		cin.get();
		system("clear");
	}while(f);
}
