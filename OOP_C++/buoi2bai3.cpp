#include<iostream>
using namespace std;

class Date
{
	private:
		int Ngay;
		int Thang;
		int Nam;
	public:
		Date();
		Date(int d,int m,int y);
		
		void Nhap();
		void Xuat();
		
		int getNgay();
		int getThang();
		int getNam();
		void setNgay(int d);
		void setThang(int m);
		void setNam(int y);
		
		bool operator> (Date t2);
		bool operator>= (Date t2);
		bool operator< (Date t2);
		bool operator<= (Date t2);
		bool operator== (Date t2);
		bool operator!= (Date t2);
		
		Date operator++ ();
		Date operator-- ();
		
		bool  CheckNHuan();		
};

Date::Date()
{
	Ngay=0;
	Thang=0;
	Nam=0;
}
Date::Date(int d,int m,int y)
{
	Ngay=d;
	Thang=m;
	Nam=y;
}

void Date::Nhap()
{
	cout<<"nhap Ngay:";
	cin>>Ngay;
	cout<<"nhap Thang:";
	cin>>Thang;
	cout<<"nhap Nam";
	cin>>Nam;
}
void Date::Xuat()
{
	cout<<"Ngay: "<<Ngay<<" Thang: "<<Thang<<" Nam: "<<Nam;
}

int Date:: getNgay()
{
	return this->Ngay;
}
int Date::getThang()
{
	return this->Thang;
}
int Date::getNam()
{
	return this->Nam;
}
void Date::setNgay(int d)
{
	this->Ngay= d;
}
void Date::setThang(int m)
{
	this->Thang=m;
}
void Date::setNam(int y)
{
	this->Nam=y;
}

bool Date::operator> (Date t2)
{
	if((this->Nam> t2.Nam) || (this->Nam==t2.Nam && this->Thang>t2.Thang)
	|| this->Nam==t2.Nam && this->Thang==t2.Thang && this->Ngay>t2.Ngay)
	{
		return true;
	}
	return false;
}

bool Date::operator>= (Date t2)
{
	if((this->Nam> t2.Nam) || (this->Nam==t2.Nam && this->Thang>t2.Thang)
	|| this->Nam==t2.Nam && this->Thang==t2.Thang && this->Ngay>=t2.Ngay)
	{
		return true;
	}
	return false;
}

bool Date::operator<(Date t2)
{
	if((this->Nam< t2.Nam) || (this->Nam==t2.Nam && this->Thang<t2.Thang)
	|| this->Nam==t2.Nam && this->Thang==t2.Thang && this->Ngay<t2.Ngay)
	{
		return true;
	}
	return false;
}

bool Date::operator<= (Date t2)
{
	if((this->Nam< t2.Nam) || (this->Nam==t2.Nam && this->Thang<t2.Thang)
	|| this->Nam==t2.Nam && this->Thang==t2.Thang && this->Ngay<=t2.Ngay)
	{
		return true;
	}
	return false;
}

bool Date::operator== (Date t2)
{
	if((this->Nam== t2.Nam) && (this->Thang==t2.Thang) && 
		(this->Ngay== t2.Ngay))
	{
		return true;
	}
	return false;
}

bool Date::operator!= (Date t2)
{
	if((this->Nam!= t2.Nam) || (this->Thang!=t2.Thang) ||
		(this->Ngay!= t2.Ngay))
	{
		return true;
	}
	return false;
}

bool Date::CheckNHuan()
{
	if((this->Nam%4==0 && this->Nam%100!=0)|| this->Nam%400==0)
	{
		return true;
	}
	return false;
}
Date Date::operator++()
{
	Date t;
	if((this->Thang== 1 ||this->Thang== 3||this->Thang== 5||this->Thang== 7
	||this->Thang== 8||this->Thang== 10||this->Thang== 12) && this->Ngay== 31)
	 {
	 	this->Ngay= 1;
	 	this->Thang+=1;
	 }
	 
	else if((this->Thang== 4||this->Thang== 6||this->Thang== 9
	||this->Thang== 11) && this->Ngay== 30)
	{
		this->Ngay=1;
		this->Thang+=1;
	}
	
	else if(this->Thang==2 &&this->CheckNHuan()==true && this->Ngay==28)
	{
		this->Ngay=1;
		this->Thang=3;
	}
	else if(this->Thang==2 &&this->CheckNHuan()==false && this->Ngay==29)
	{
		this->Ngay=1;
		this->Thang=3;
	}
	else if(this->Thang== 12 && this->Ngay==31)
	{
		this->Ngay=1;
		this->Thang=1;
		this->Nam+=1;
	}
	else
	{
		this->Ngay+=1;
	}
	t.Ngay= this->Ngay;
	t.Thang=this->Thang;
	t.Nam= this->Nam;
	return t;
}

Date Date::operator--()
{
	Date t;
	if((this->Thang== 5||this->Thang== 7 ||this->Thang== 10||this->Thang== 12) && this->Ngay== 1)
	 {
	 	this->Ngay=30 ;
	 	this->Thang-=1;
	 }
	 
	else if((this->Thang==2||this->Thang== 4||this->Thang== 6||this->Thang==8||
		this->Thang== 9 ||this->Thang== 11) && this->Ngay==1)
	{
		this->Ngay=31;
		this->Thang-=1;
	}
	
	else if(this->Thang==3 &&this->CheckNHuan()==true && this->Ngay==1)
	{
		this->Ngay=28;
		this->Thang=2;
	}
	else if(this->Thang==2 &&this->CheckNHuan()==false && this->Ngay==1)
	{
		this->Ngay=29;
		this->Thang=2;
	}
	else if(this->Thang==1 &&this->Ngay==1)
	{
		this->Ngay=31;
		this->Thang=12;
		this->Nam-=1;
	}
	else
	{
		this->Ngay-=1;
	}
	t.Ngay= this->Ngay;
	t.Thang=this->Thang;
	t.Nam= this->Nam;
	return t;
}

int main()
{
	Date t1;
	t1.Nhap();
	t1++;
	t1.Xuat();
	Date t2( 3, 5,1999);
	t2--;
	t2.Xuat();
	system("pause");
}
