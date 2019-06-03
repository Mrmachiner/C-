#include<iostream>
using namespace std;

class SoPhuc
{
	private:
		float Thuc;
		float Ao;
	public:
		SoPhuc();
		void Nhap();
		void Xuat();
		SoPhuc operator+ (SoPhuc sp2);
		SoPhuc operator- (SoPhuc sp2);
		SoPhuc operator* (SoPhuc sp2);
		SoPhuc operator/ (SoPhuc sp2);
		bool operator> (SoPhuc sp2);
		bool operator= (SoPhuc sp2);
};

bool SoPhuc::operator=(SoPhuc sp2)
{
	this->Thuc= sp2.Thuc;
	this->Ao= sp2.Ao;
}

bool SoPhuc::operator>(SoPhuc sp2)
{
	if(this->Thuc>sp2.Thuc)
	{
		return true;
	}
	else if(this->Thuc< sp2.Thuc)
	{
		return false;
	}
	else{
		if(this->Ao>sp2.Ao)
		{
			return true;
		}
		return false;
	}
}

SoPhuc::SoPhuc()
{
	Thuc=0;
	Ao=0;
}

void SoPhuc::Nhap()
{
	cout<<endl<<"nhap phan thuc= ";
	cin>>Thuc;
	cout<<endl<<"nhap phan ao = ";
	cin>>Ao;
}

void SoPhuc::Xuat()
{
	cout<<Ao<<"*i + "<<Thuc<<endl;
}

SoPhuc SoPhuc::operator+ (SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= this->Thuc+ sp2.Thuc;
	sp3.Ao= this->Ao+ sp2.Ao;
}

SoPhuc SoPhuc::operator-(SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= this->Thuc- sp2.Thuc;
	sp3.Ao= this->Ao- sp2.Ao;
}

SoPhuc SoPhuc::operator*(SoPhuc sp2)
{
	SoPhuc sp3;
	sp3.Thuc= this->Thuc*sp2.Ao+sp2.Thuc*this->Ao;
	sp3.Ao= this->Ao*sp2.Ao-sp2.Thuc*this->Thuc;
	return sp3;
}

SoPhuc SoPhuc::operator/(SoPhuc sp2)
{
	SoPhuc sp3;
	double T= sp2.Thuc*sp2.Thuc+ sp2.Ao*sp2.Ao;
	sp3.Thuc= (this->Thuc*sp2.Ao-sp2.Thuc*this->Ao)/T;
	sp3.Ao= (this->Thuc*sp2.Thuc+this->Ao*sp2.Ao)/T;
	return sp3;
}

class DaySoPhuc
{
	private:
		int N;
		SoPhuc X[100];
	public:
		DaySoPhuc();
		void Nhap();
		void Xuat();
		void SapXep();	
};

DaySoPhuc::DaySoPhuc()
{
	N=0;
}

void DaySoPhuc::Nhap()
{
	cout<<endl<<"Nhap so phan tu cua day";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		X[i].Nhap();
	}
}

void DaySoPhuc::Xuat()
{
	cout<<endl<<"		THONG TIN DAY "<<endl;
	for(int i=0;i<N;i++)
	{
		X[i].Xuat();
	}
}

void DaySoPhuc::SapXep()
{
	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(X[j]>X[i])
			{
				SoPhuc sp;
				sp= X[i];
				X[i]=X[j];
				X[j]=sp;
			}
		}
	}
}

int main()
{
	DaySoPhuc day1;
	day1.Nhap();
	day1.Xuat();
	
	day1.SapXep();
	day1.Xuat();
}
