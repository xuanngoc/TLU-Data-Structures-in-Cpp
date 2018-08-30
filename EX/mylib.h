#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
int menu(){
	cout<<"Cac tuy chon: \n";
	cout<<"1. Them 1 so.\n";
	cout<<"2. HIen thi cac so\n";
	cout<<"3. Nap kho so tu file.\n";
	cout<<"4. Luu kho so xuong file.\n";
	cout<<"5. Sinh so ra file.\n";
	//cout<<"3. Tim kiem.\n";

	int c;
	cout<<"Moi ban nhap lua chon: ";
	cin >>c;
	return c;
}
void themMotSo(int arr[], int &n){
	cout<<"\n---- Them mot so----\n";
	cout<<"Nhap so ban muon them: ";
	int temp;
	cin >>temp;
	arr[n++] = temp;
	cout<<"\n---Them so thanh cong---\n";
	return ;
}
void hienThiCacSo(int arr[], int n){
	cout<<"\n---- Hien thi cac so ----\n";
	for(int i=0; i< n; i++){
		cout<< arr[i] <<" ";
	}
	cout<<"\n---HIen thi thanh cong---\n";
	return ;
}



void napKhoSoTuFile(int arr[], int &n){
	cout<<"\n------ Nap kho so tu file ------\n\n";
	char t[100];
	cout<<"NHap ten file ban muon them so: ";
	cin.ignore();
	cin.getline(t, 100);
	ifstream fin(t);
	if(!fin.is_open()){
		cout<<"\n\nERROR---File khong co san\n\n";
		return ;
	}
	cout<<"Ban muon nap so vao file dang thuc thi khong ?\n";
	cout<<"1.Co\n2.KHong";

	int temp;
	if(temp ==1){	
		while(!fin.eof()){
			fin >> arr[n++]; 
		}
	
	}else if(temp ==2){
		n = 0;
		while(!fin.eof()){
			fin >> arr[n++]; 
		}
	}
	fin.close();
	cout<<"\n------ Nap so tu file thanh cong------\n\n";
}

void LuuKhoSoXuongFile(int arr[], int n){
	cout<<"\n------ Luu kho so tu file ------\n\n";
	char t[100];
	cout<<"NHap ten file ban muon luu: ";
	cin.ignore();
	cin.getline(t, 100);
	ofstream fout(t);
	for(int i=0; i< n; i++){
		fout << arr[i]<<" ";
	}
	fout.close();
	cout<<"\n--- Luu thanh cong----\n";
}

void SinhKhoSoNgauNhien(int arr[], int &n){
	cout<<"\n--- Sinh kho so---\n\n";
	cout<<"Ban muon sinh so vao file dang thuc thi khong ?\n";
	cout<<"\t1.Co\n\t2.KHong";

	int temp;
	if(temp == 1){	
		int size;
		cout<<"Ban muon nhap bao nhieu so: ";
		cin >>size;
		n+= size;
		srand(time(NULL));
		for(int i=n-1; i< n; i++){
			arr[i] = rand() % 10000;
		}
	
	}else if(temp == 2){
		int size;
		cout<<"Ban muon nhap bao nhieu so: ";
		cin >>size;
		n = size;
		srand(time(NULL));
		for(int i=0; i< n; i++){
			arr[i] = rand() % 10000;
		}
	
	}
	
	cout<<"\n------ Sinh kho so thanh cong------\n\n";
}
