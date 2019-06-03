#include<iostream>
using namespace std;

class Diem
{
	private:
		int x;
		int y;
	public:
		Diem();
		Diem(int h,int t);
		void Nhap();
		void Xuat();
};

Diem::Diem()
{
	x=y=0;
}

Diem::Diem(int h,int t)
{
	x=h;
	y=t;
}

void Diem::Nhap()
{
	cout<<endl<<"nhap hoanh do: ";
	cin>>x;
	cout<<endl<<"nhap tung do: ";
	cin>>y;
}

void Diem::Xuat()
{
	cout<<"toa do diem la: ("<<x<<","<<y<<")"<<endl;
}

class HinhTron : public Diem
{
	private:
		int r;
	public:
		HinhTron();
		HinhTron(int h,int t,int bk);
		void Nhap();
		void Xuat();
};

HinhTron::HinhTron():Diem()
{
	r=0;
}

HinhTron::HinhTron(int h,int t,int bk): Diem(h,t)
{
	r=bk;
}

void HinhTron::Nhap()
{
	Diem::Nhap();
	cout<<endl<<"nhap ban kinh: ";
	cin>>r;
}

void HinhTron::Xuat()
{
	Diem::Xuat();
	cout<<"ban kinh: "<<r<<endl;
}

int main()
{
	Diem d1;
	d1.Nhap();
	d1.Xuat();
	
	HinhTron ht1;
	ht1.Xuat();
	HinhTron ht2(2,1,4);
	ht2.Xuat();
	HinhTron ht3;
	ht3.Nhap();
	ht3.Xuat();
	
}
