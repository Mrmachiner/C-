#include<iostream>
#include<string>

using namespace std;

class Sach
{
	private:
	 string TenSach;
	 int GiaSach;
	 int MaSach;
	 string NhaXb;
	 string TacGia;
	
	public :
		Sach()
		{
			TenSach= "Tam Quoc Dien Nghia";
			GiaSach= 100000;
			MaSach= 010101;
			NhaXb= "Khong bo";
			TacGia= "La Quan Trung";
		}
		 Sach(string TenSach,int GiaSach,int MaSach,string NhaXb,string TacGia)
		{
			this->TenSach= TenSach;
			this->MaSach= MaSach;
			this->GiaSach= GiaSach;
			this->NhaXb= NhaXb;
			this->TacGia= TacGia;
		}	
		 void NhapDL()
		{
			cout<<"\nMa sach: ";
			cin>> MaSach ;
			cout<<"\nten Sach =: ";
			cin>> TenSach;
			cout<<"\ngia sach =:";
			cin>> GiaSach;
			cout<<"\nNha Xuat Ban: ";
			cin>> NhaXb;
			cout<<"\nTac Gia :";
			cin>> TacGia;	
		}
		
		 void XuatDl()
		{
			cout<<"Thong tin cua sach la: "<<endl;
			cout<<"ten sach :"<<TenSach<<endl;
			cout<<"Ma sach: "<<MaSach<<endl;;
			cout<<"Gia Sach: "<<GiaSach<<endl;;
			cout<<"Nha XuatBan: "<<NhaXb<<endl;;
			cout<<"Ten tach gia :"<<TacGia<<endl;;
		}
		
		void setTenSach(string ten)
		{
			this->TenSach= ten;
		}
		string getTenSach()
		{
			return this->TenSach;
		}
		void setGiaSach(int gia)
		{
			if(gia>0 )
				{
					this->GiaSach= gia;
				}
			else{
				this->GiaSach= 0;
			}
		}
		int getGiaSach()
		{
			return this->GiaSach;
		}
		void setTacGia(string tg)
		{
			this->TacGia=tg;
		}		
		string getTacGia()
		{
			return this->TacGia;
		}
};

class ListSach
{
	private :
		int n;
		Sach arrSach[100];
	public :
		ListSach();
		ListSach(int m);
		void Nhap();
		void Xuat();
		int TimTheoGia();
		int DemTacGia(string tenTacGia);
};

ListSach::ListSach()
{
	n=10;
}
ListSach::ListSach(int m)
{
	n=m;
}

void ListSach::Nhap()
{
	for(int i=0;i<n;i++)
	{
		arrSach[i].NhapDL();
	}
}
void ListSach::Xuat()
{
	for(int i=0;i<n;i++)
	{
		arrSach[i].XuatDl();
	}
}

int ListSach::TimTheoGia()
{
	int max=arrSach[0].getGiaSach();
	for(int i=1;i<n;i++)
	{
		if(arrSach[i].getGiaSach()>max)
		{
			max=arrSach[i].getGiaSach();
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arrSach[i].getGiaSach()==max)
		{
			arrSach[i].XuatDl();
		}
	}
	return max;
}

int ListSach::DemTacGia(string tenTacGia)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(arrSach[i].getTacGia()==tenTacGia)
		{
			arrSach[i].XuatDl();
			k++;
		}
	}
	return k;
}

int main()
{
	Sach sach1;
	sach1.XuatDl();
	Sach sach2("TamQuoc",12333,10101,"KB","LaQuanTrung");
	sach2.XuatDl();	
	
	ListSach Ds1(3);
	Ds1.Nhap();
	cout<<"cac sach co gia cao nhat la"<< endl<<endl;
	Ds1.TimTheoGia();
	
}

