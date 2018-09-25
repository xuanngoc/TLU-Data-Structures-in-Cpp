#include <fstream>
int Menu(){
	cout<<"---- QUAN LY DANH BA ----\n";
	cout<<"1. Them lien he\n";
	cout<<"2. Xem danh ba\n";
	cout<<"3. Sua lien he\n";
	cout<<"4. Xoa lien he\n";
	cout<<"5. Luu danh ba\n";
	cout<<"6. Xuat HTML\n";
	cout<<"0. Thoat\n";
	cout<<"\nNhap lua chon: ";
	int a;
	cin>> a;
	return a;
}
void ThemLienHe(List<SDT> &db){
	char t[30];
	char s[20];
	cout<<"Nhap ten: ";
	cin.ignore();
	cin.getline(t, 30);
	cout<<"Nhap so dien thoai: ";
	cin.ignore();
	cin.getline(s, 20);
	db.pushBack(SDT(s, t));
	db.sort();
}
void XemDanhSach(List<SDT> const &db){
	cout<<"Ten lien he\t\tSo dien thoai\n\n";
	db.print();
}
void SuaLienHe(List<SDT> &db){
	cout<<"Ban muon sua so dien thoai thu may: ";
	int t;
	cin>> t;
	cout<<"Nhap ten lien he: ";
	cin.ignore();

	char ten[30];
	cin.getline(ten, 30);
	cout<<"Nhap so dien thoai: ";
	cin.ignore();
	char s[15];
	cin.getline(s, 15);
	db.change(t, SDT(s, ten));
}
void XoaLienHe(List<SDT> &db){
	cout<<"Ban muon xoa so dien thoai thu may: ";
	int t;
	cin >>t;
	db.deleteAt(t);
}
void LuuDanhBa(List<SDT>  db){
	ofstream fout("DATA.TXT");
	fout << db.size()<<endl;
	for(int i=1; i<= db.size(); i++){
		SDT a = db.getAt(i);
		const char* t;
		t = a.getTen();
		const char* s;
		s = a.getSdt();
		fout<<t<<endl;
		fout<<s<<endl;
	}
}
void XuatHTML(List<SDT> db){
	cout<<"Nhap ten ban muon luu: ";
	char  a[30];
	cin.ignore();
	cin.getline(a, 30);
	ofstream fout(a);
	fout<<"<!DOCTYPE html>\n";
	fout<<"<html>\n\
		<head>\n\
			<meta charset=\"UTF-8\">\
			<title>Danh ba</title>\n\
			<style>\
				table, th, td {\
    			border: 1px solid black;}\
			</style>\
		</head>\
		<body>\n";
		fout<<"<br>\n";
		fout<<"<br>\n";
		fout<<"<br>\n";
		fout<<"<br>\n";

	fout<<"<table style=\"width:100\%\">\n";	
	
	fout<<"<tr>\
    	<th>Tên</th>\
    	<th>Số điện thoại</th>\
  	</tr>\n";
	for(int i=1; i<= db.size(); i++){
		SDT a = db.getAt(i);
		const char* t;
		t = a.getTen();
		const char* s;
		s = a.getSdt();
		fout<<"\t\t<tr>\n";
		fout<<"\t\t\t<td>"<<t<<"</td>\n\t\t\t<td>"<<s<<"</td>\n";
		fout<<"\t\t</tr>\n";

	}	
	
	fout<<"</table>\n";	

	fout<<"\t</body>\n";
	fout<<"</html>\n";

}