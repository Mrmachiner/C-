#include<iostream>
using namespace std;

class SinhVien
{
	private:
		int MaSV;
		string Ten;
		int DiemTB;
	public:
		SinhVien();
		int getDiem();
		bool operator> (SinhVien sv2);
		void NhapDl();
		void XuatDl();
};

void SinhVien::NhapDl()
{
	cout<<"Nhap ma sv : ";
	cin>>MaSV;
	cout<<"Nhap ten sv: ";
	cin>> Ten;
	cout<<"Nhap diem TB: ";
	cin>>DiemTB;
}
void SinhVien::XuatDl()
{
	cout<<"thong tin sinh vien:"<<endl;
	cout<<"ma sv:"<<MaSV<<endl;
	cout<<"Ten: "<<Ten<<endl;
	cout<<"Diem Tb:"<<DiemTB<<endl;
}
SinhVien::SinhVien()
{
	MaSV=0;
	Ten="0";
	DiemTB=0;
}
int SinhVien:: getDiem()
{
	return this->DiemTB;
}

bool SinhVien:: operator> (SinhVien sv2)
{
	if((this->DiemTB>sv2.DiemTB)|| 
	(this->DiemTB==sv2.DiemTB && this->Ten.compare(sv2.Ten)==1))
		return true;
	
	return false; 
}

class ListSV
{
	private:
		SinhVien arrSV[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		void SapXep();
};

void ListSV::Nhap()
{
	cout<<"Nhap so sinh vien n="; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		arrSV[i].NhapDl();
	}
}
void ListSV::Xuat()
{
	for(int i=0;i<n;i++)
	{
		arrSV[i].XuatDl();
	}	
}

void ListSV::SapXep()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arrSV[j]>arrSV[i])
			{
				SinhVien sv;
				sv=arrSV[i];
				arrSV[i]=arrSV[j];
				arrSV[j]=sv;
			}
		}
	}
}

int main()
{
	ListSV ds1;
	ds1.Nhap();
	ds1.SapXep();
	ds1.Xuat();
}
