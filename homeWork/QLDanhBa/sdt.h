#ifndef sdt_h
#define sdt_h
#include <string.h>

class SDT
{
private:
	char SoDienThoai[20];
	char ten[30];
public:
	SDT(){};
	SDT(const char *sdt,const char *t){
		strcpy(SoDienThoai, sdt);
		strcpy(ten, t);
	}

	//getters
	const char* getSdt()const {
		return SoDienThoai;
	}
	const char* getTen()const {
		return ten;
	} 

	bool operator > (SDT const &a)const{
		return ten[0] > a.getTen()[0];
	}

	friend ostream &operator <<(ostream &out, SDT const &a){
		out<<a.SoDienThoai<<"\t\t"<<a.ten<<endl;
	}

};

#endif