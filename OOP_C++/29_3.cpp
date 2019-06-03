#include<iostream>
using namespace std;

class SinhVien
{
	private:
		int id;
		string hoTen;
		bool gt;
		string ngaySinh;
	public:
		SinhVien();
		SinhVien(int d,string ten,bool Gt,string ns);
		void Nhap();
		void Xuat();	
		
};

SinhVien::SinhVien()
{
	id=0;
	hoTen="";
	gt= 1;
	ngaySinh ="";
}

SinhVien::SinhVien(int d,string ten,bool Gt,string ns)
{
	id=d;
	hoTen= ten;
	gt=Gt;
	ngaySinh=ns;
}

void SinhVien::Nhap()
{
	cout<<endl<<"Nhap id: ";
	cin>>id;
	cout<<endl<<"Nhap ho ten: ";
	cin>>hoTen;
	cout<<endl<<"Nhap Gioi Tinh (nam 1, nu 0):";
	cin>>gt;
	cout<<endl<<"Nhap Ngay Sinh: ";
	cin>>ngaySinh;
}

void SinhVien::Xuat()
{
	cout<<"id: "<<id<<endl;
	cout<<"ho ten: "<<hoTen<<endl;
	if(gt)
	{
		cout<<"gioi tinh: Nam"<<endl;
	}
	else
	{
		cout<<"gioi tinh: Nu"<<endl;
	}
	cout<<"Ngay sinh: "<<ngaySinh<<endl;
}

class SinhVienQS: public SinhVien
{
	private:
		string CapBac;
		string ChucVu;
	public:
		SinhVienQS();// ko the goi o ben trong ham
		SinhVienQS(int d,string ten,bool Gt,string ns,string capbac,string chucvu);
		void Nhap();
		void Xuat();
};

SinhVienQS::SinhVienQS(): SinhVien()
{
	CapBac="";
	ChucVu="";
}

SinhVienQS::SinhVienQS(int d,string ten,bool Gt,string ns,
			string capbac,string chucvu): SinhVien(d,ten,Gt,ns)
{
	CapBac= capbac;
	ChucVu= chucvu;
}

void SinhVienQS::Nhap()
{
	SinhVien :: Nhap();
	cout<<endl<<"Nhap Cap Bac: ";
	cin>>CapBac;
	cout<<endl<<"Nhap CHuc Vu: ";
	cin>>ChucVu;
}

void SinhVienQS::Xuat()
{
	SinhVien::Xuat();
	cout<<"Cap Bac: "<<CapBac<<endl;
	cout<<"Chuc Vu: "<<ChucVu<<endl;
}
int main()
{
	SinhVienQS sv2 (1,"gg",1,"1/2","1","ld");
	sv2.Xuat();
	SinhVienQS sv1;
	sv1.Xuat();
}
