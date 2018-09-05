#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

class MonHoc{
private:
	string tenMonHoc;
	string maMonHoc;
	float diem;
public:
	MonHoc():tenMonHoc(""), maMonHoc(""), diem(0.0){}
	MonHoc(string a, string b, float c): tenMonHoc(a), maMonHoc(b), diem(c) {}
	//setters
	void setTenMonHoc(string tenMH){
		this-> tenMonHoc = tenMH;
	}
	void setMaMonHoc(string maMH){
		this -> maMonHoc = maMH;
	}
	void setDiem(float d){
		this -> diem = d;
	}
	//getters
	string getTenMonHoc(){
		return this-> tenMonHoc;
	}
	string getMaMonHoc(){
		return this -> maMonHoc;
	}
	int getDiem(){
		return this -> diem;
	}

	friend ostream &operator << (ostream & out, MonHoc & b){
		out<<b.tenMonHoc<<"\n"<<b.maMonHoc<<"\n"<<b.diem<<endl;
		return out;
	}	


};

int menu(){
	cout<<"Cac tuy chon: \n";
	cout<<"1. Them mon hoc.\n";
	cout<<"2. Them diem.\n";
	cout<<"3. In bang diem.\n";
	cout<<"4. Tinh trung binh cong.\n";
	cout<<"5. Mo bang diem.\n";
	cout<<"6. Luu bang diem.\n";

	int c;
	cout<<"Moi ban nhap lua chon: ";
	cin >>c;
	return c;
}

void themMon(vector <MonHoc> &arr){
	cout<<"--- Them mon ---\n\n";
	MonHoc temp;
	cout<<"Moi nhap ten mon hoc: ";
	string t;
	cin.ignore();
	getline (cin, t);
	temp.setTenMonHoc(t);
	cout<<"Moi nhap ma mon hoc: ";
	cin >>t;
	temp.setMaMonHoc(t);
	arr.push_back(temp);
	cout<<"--- Them mon thanh cong---\n";
}
void themDiem(vector<MonHoc> &arr){

	string t;
	cout<<"Moi ban nhap ma mon muon them diem: ";
	cin >>t;
	for(int i=0; i< arr.size(); i++){
		if(arr[i].getMaMonHoc() == t){
			float temp;
			cout<<"Moi ban nhap diem cho mon hoc "<<arr[i].getMaMonHoc()<<": ";
			cin >>temp;
			arr[i].setDiem(temp);
			return;
		}
	}
	cout<<"--- Mon hoc khong ton tai---\n";
}

void inBangDiem(vector<MonHoc> arr){

	cout<<"\t\t*** Bang Diem ***\n\n";
	cout<<"Ten mon hoc\tMa Mon Hoc\tDiem\n";
	for(int i=0; i<arr.size(); i++ ){
		cout<<arr[i];
	}

}

void tinhTrungBinhCong(vector<MonHoc>arr){

	float total =0;
	for(int i=0; i<arr.size(); i++ ){
		total+= arr[i].getDiem();
	}
	cout<<"Tong trung binh cac mon hoc: "<< total / arr.size()<<endl;
}

void moBangDiem(vector<MonHoc>&arr){
	cout<<"Moi nhap ten file ban muon mo: ";
	char t[100];
	cin.ignore();
	cin.getline(t, 100);

	ifstream fin(t);
	if(!fin.is_open()){
		cout<<"---- File chua ton tai  !!!!\n\n";
		return;
	}
	cout<<"Ban muon them cac diem vao chuong trinh dang thuc thi:\n";
	cout<<"\t1. Co\n\t2.Khong\n";
	int temp;
	cout<<"Moi ban lua chon(1, 2): ";

	cin >> temp;
	/*if( temp == 1){
		
		while(!fin.eof()){
			
			string ten;
			string ma;
			float d;
			
			getline(fin, ten);
			fin>>ma;
			//cout<<"ma"<<ma<<"[-\n";
			fin >> d;
			cout<<"diem"<<d<<"-";
			//break;

			MonHoc temp = MonHoc(ten, ma, d);
			arr.push_back(temp);
		}
		fin.close();

		cout<<"\n---Mo file thanh cong ---\n";*/
	}/*else if(temp ==2){
		vector<MonHoc> arr1;
		while(!fin.eof()){
			string ten;
			string ma;
			float d;
			fin >> ten;
			fin >> ma;
			fin >> d;
			MonHoc temp = MonHoc(ten, ma, d);
			arr1.push_back(temp);
		}
		arr = arr1;
		fin.close();
		cout<<"\n--- Mo file thanh cong---\n";
	}else{
		cout<<"\n\nERROR\n\n";
	}*/
}

void luuVaoFile(vector<MonHoc> arr){
	cout<<"Moi nhap ten file ban muon mo: ";
	char t[100];
	cin.ignore();
	cin.getline(t, 100);

	ofstream fout(t);
	for(int i=0; i<arr.size(); i++){
		fout<<arr[i];
	}
	fout.close();
	cout<<"\n---Luu file thanh cong---\n\n";
}