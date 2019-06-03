#include<iostream>
using namespace std;

class SoPhuc
{
	private:
		double Thuc;
		double Ao;
	public:
		SoPhuc();
		SoPhuc(double a,double b);
		void Nhap();
		void Xuat();
		SoPhuc Cong(SoPhuc sp1,SoPhuc sp2);
		SoPhuc Tru(SoPhuc sp1,SoPhuc sp2);
		SoPhuc Nhan(SoPhuc sp1,SoPhuc sp2);
		SoPhuc Chia(SoPhuc sp1,SoPhuc sp2);
		
		SoPhuc operator+(SoPhuc sp2);
		
		void setThuc(double a);
		double getThuc();
		void setAo(double a);
		double getAo();
};

SoPhuc:: SoPhuc()
{
	Thuc= 0;
	Ao=0;
}

SoPhuc:: SoPhuc(double a,double b)
{
	Thuc=a;
	Ao=b;
}

void SoPhuc::Nhap()
{
	cout<<"nhap phan thuc cua so phuc:"<<endl;
	cin>>Thuc;
	cout<<"Nhap phan ao cua so phuc:"<<endl;
	cin>>Ao;
}

void SoPhuc::Xuat()
{
	cout<<"so Phuc la: "<<Ao<<"*i+"<<Thuc;
}

double SoPhuc::getThuc()
{
	return this->Thuc;	 
}
double SoPhuc::getAo()
{
	return this->Ao;
}

void SoPhuc:: setThuc(double a)
{
	this->Thuc =a;
}

void SoPhuc :: setAo(double b)
{
	this->Ao= b;
}


SoPhuc SoPhuc:: Cong(SoPhuc sp1, SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= sp1.Thuc+sp2.Thuc;
	sp3.Ao= sp1.Ao+sp2.Ao;
	return sp3;
}

SoPhuc SoPhuc:: operator+( SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= this->Thuc+sp2.Thuc;
	sp3.Ao= this->Ao+sp2.Ao;
	return sp3;
}



SoPhuc SoPhuc::Tru(SoPhuc sp1,SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= sp1.Thuc-sp2.Thuc;
	sp3.Ao= sp1.Ao-sp2.Ao;
	return sp3;
}

SoPhuc SoPhuc::Nhan (SoPhuc sp1,SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= sp1.Thuc*sp2.Ao+sp2.Thuc*sp1.Ao;
	sp3.Ao= sp1.Ao*sp2.Ao-sp2.Thuc*sp1.Thuc;
	return sp3;
}

SoPhuc SoPhuc::Chia (SoPhuc sp1,SoPhuc sp2)
{
	SoPhuc sp3;
	double T= sp2.Thuc*sp2.Thuc+ sp2.Ao*sp2.Ao;
	sp3.Thuc= (sp1.Thuc*sp2.Ao-sp2.Thuc*sp1.Ao)/T;
	sp3.Ao= (sp1.Thuc*sp2.Thuc+sp1.Ao*sp2.Ao)/T;
	return sp3;
}

int main()
{
	SoPhuc sp1;
	sp1.Nhap();
	SoPhuc sp2(1,6);
	
	SoPhuc sp3;
	sp3= sp3.Cong(sp1,sp2);
	sp3.Xuat();
	
	SoPhuc sp4;
	sp4= sp1+sp2;
	sp4.Xuat();
}
