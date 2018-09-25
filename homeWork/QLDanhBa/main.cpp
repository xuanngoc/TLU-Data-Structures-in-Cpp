#include <iostream>
using namespace std;
#include "sdt.h"
#include "list.h"
#include "mylib.h"

int main()
{
	List<SDT> DanhBa;

	int chon;
	do{
		chon = Menu();
		switch(chon){
			case 1:
				ThemLienHe(DanhBa);
				break;
			case 2:
				XemDanhSach(DanhBa);
				break;
			case 3:
				SuaLienHe(DanhBa);
				break;
			case 4:
				XoaLienHe(DanhBa);
				break;
			case 5:
				LuuDanhBa(DanhBa);
				break;
			case 6:
				XuatHTML(DanhBa);
				break;
			default:
				chon = 0;
				break;					
		}
	}while(chon);
		SDT a("0933123", "ngoc");
		SDT b("421312312", "bui");
		bool x=  b > a ;
		cout <<x<<endl;



	
}

