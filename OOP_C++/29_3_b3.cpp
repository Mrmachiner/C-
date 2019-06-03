#include<iostream>
#include<math.h>
using namespace std;

class HinhHoc
{
	public:
		void Nhap();
		void Xuat();
		float ChuVi()
		{
			return 0;
		}
		float DienTich()
		{
			return 0;
		}
};

class TamGiac :public HinhHoc
{
	private:
		int a;
		int b;
		int c;
	public:
		TamGiac();
		TamGiac(int d1,int d2,int h);
		void Nhap();
		void Xuat();
		float ChuVi();
		float DienTich();
};

TamGiac::TamGiac()
{
	a=b=c=0;
}

TamGiac::TamGiac(int d1,int d2,int h)
{
	a=d1;
	b=d2;
	c=h;
}

void TamGiac::Nhap()
{
	cout<<endl<<"nhap canh thu nhat: ";
	cin>>a;
	cout<<endl<<"nhap canh thu 2: ";
	cin>>b;
	cout<<endl<<"nhap canh thu 3(lon hon hieu 2 canh tr va nho hon tong) :";
	cin >>c;	
}

void TamGiac::Xuat()
{
	cout<<"3 canh tam giac la: "<<a<<","<<b<<","<<c<<endl;
		cout<<"Chu vi: "<<ChuVi();
			cout<<"Dien Tich: "<<DienTich();
}

float TamGiac::ChuVi()
{
	return a+b+c;
}

float TamGiac::DienTich()
{
	float p= (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

class HinhTron :public HinhHoc
{
	private:
		int r;
	public:
		HinhTron();
		HinhTron(int bk);
		void Nhap();
		void Xuat();
		float ChuVi();
		float DienTich(); 
};

HinhTron::HinhTron()
{
	r=0;
}

HinhTron::HinhTron(int bk)
{
	r=bk;
}

void HinhTron::Nhap()
{
	cout<<endl<<"nhap ban kinh hinh tron: ";
	cin>>r;
}

void HinhTron::Xuat()
{
	cout<<"Ban Kinh Hinh Tron la: "<<r<<endl;
	cout<<"Chu vi: "<<ChuVi();
			cout<<"Dien Tich: "<<DienTich();
}

float HinhTron::ChuVi()
{
	return 3.14*r*2;
}

float HinhTron::DienTich()
{
	return 3.14*3.14*r;
}

class HinhChuNhat: public HinhHoc
{
	private:
		int a;
		int b;
	public:
		HinhChuNhat();
		HinhChuNhat(int n,int d);
		void Nhap();
		void Xuat();
		float ChuVi();
		float DienTich();
		
};

HinhChuNhat::HinhChuNhat()
{
	a=b=0;
}

HinhChuNhat::HinhChuNhat(int n, int d)
{
	a=n;
	b=d;
}

void HinhChuNhat::Nhap()
{
	cout<<endl<<"nhap canh ngan cua hinh chu nhat: ";
	cin>>a;
	cout<<endl<<"nhap canh dai cua hinh chu nhat : ";
	cin>>b;
}

void HinhChuNhat::Xuat()
{
	cout<<"canh ngan: "<<a<<"	canh dai: "<<b<<endl;
	cout<<"Chu vi: "<<ChuVi();
			cout<<"Dien Tich: "<<DienTich();
}

float HinhChuNhat::ChuVi()
{
	return 2*(a+b);
}

float HinhChuNhat::DienTich()
{
	return a*b;
}

int main()
{
	TamGiac tg0;
	tg0.Nhap();
	tg0.Xuat();
	
	HinhTron ht0;
	ht0.Nhap();
	ht0.Xuat();
	
	HinhChuNhat hcn0;
	hcn0.Nhap();
	hcn0.Xuat();
}




