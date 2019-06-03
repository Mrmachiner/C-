#include<iostream>
using namespace std;

class AnPham
{
	private:
		int Ma;
		string Ten;
		string TheLoai;
	public:
		AnPham();
		AnPham(int m,string t, string tl);
		
		void Nhap();
		void Xuat();
		
		string getTen();
		int getID();
		string getTheLoai();
		void setMa(int m);
		void setTen(string t);
		void setTheLoai(string tl);
};

void AnPham:: setMa(int m)
{
	this->Ma= m;
}
void AnPham::setTen(string t)
{
	this->Ten= t;
}
void AnPham::setTheLoai(string tl)
{
	this->TheLoai= tl;	
}

string AnPham::getTheLoai()
{
	return this->TheLoai;
}
int AnPham::getID()
{
	return this->Ma;
}

string AnPham::getTen()
{
	return this->Ten;
}

AnPham::AnPham()
{
	Ma=0;
	Ten="";
	TheLoai="";
}

AnPham::AnPham(int m, string t, string tl)
{
	Ma=m;
	Ten=t;
	TheLoai= tl;
}

void AnPham::Nhap()
{
	cout<<endl<<"Nhap ma an: ";
	cin>>Ma;
	cout<<endl<<"Nhap Ten An: ";
	cin>>Ten;
	cout<<endl<<"Nhap The Loai: ";
	cin>>TheLoai;
}

void AnPham::Xuat()
{
		cout<<"				THONG TIN SACH"<<endl;
	cout<<"ma an: "<<Ma<<endl;
	cout<<"Ten an: "<<Ten<<endl;
	cout<<"The Loai: "<<TheLoai<<endl;
}

class TapChi : public AnPham
{
	private:
		string KyXuatBan;
		int SoBan;
		int SoLuuChieu;
	public:
		TapChi();
		TapChi(int m,string t, string tl,string kxb,int sb,int slc );
		void Nhap();
		void Xuat();
};

TapChi::TapChi(): AnPham()
{
	KyXuatBan="";
	SoBan= 0;
	SoLuuChieu=0;
}

TapChi::TapChi(int m,string t, string tl,string kxb,int sb,int slc):
				AnPham(m,t,tl)
{
	KyXuatBan=kxb;
	SoBan=sb;
	SoLuuChieu= slc;
}

void TapChi::Nhap()
{
	AnPham::Nhap();
	cout<<endl<<"Nhap Ky Xuat Ban: ";
	cin>>KyXuatBan;
	cout<<endl<<"Nhap So Ban: ";
	cin>>SoBan;
	cout<<endl<<"Nhap So Luu Chieu phat hanh: ";
	cin>>SoLuuChieu;
}

void TapChi::Xuat()
{
	AnPham::Xuat();
	
	cout<<"Ky Xuat Ban: "<<KyXuatBan<<endl;
	cout<<"So Ban: "<<SoBan<<endl;
	cout<<"SO Luu chieu phat hanh: "<<SoLuuChieu<<endl;
}


class Sach : public AnPham
{
	private:
		string TacGia;
		string NhaXuatBan;
		int SoTrang;
		int NamXuatBan;
		int GiaBia;
	public:
		Sach();
		Sach(int m,string t, string tl,string tg,int nxb,int st,
				int nam,int gia);
		string getTenTacGia();
		void Nhap();
		void Xuat();
		void operator= (Sach s2);
		int getNamXuatBan();
};

int Sach::getNamXuatBan()
{
	return this->NamXuatBan;
}

void Sach::operator=(Sach s2)
{
	this->setMa(s2.getID());
	this->setTen(s2.getTen());
	this->setTheLoai(s2.getTheLoai());
	this->TacGia= s2.TacGia;
	this->NhaXuatBan= s2.NhaXuatBan;
	this->SoTrang= s2.SoTrang;
	this->NamXuatBan= s2.NamXuatBan;
	this->GiaBia= s2.GiaBia;
}

string Sach::getTenTacGia()
{
	return this->TacGia;
}

Sach::Sach(): AnPham()
{
	TacGia="";
	NhaXuatBan="";
	SoTrang= 0;
	NamXuatBan=0;
	GiaBia=0;
}

Sach::Sach(int m,string t, string tl,string tg,int nxb,int st,
				int nam,int gia) : AnPham(m,t,tl)
{
	TacGia=tg;
	NhaXuatBan= nxb;
	SoTrang= st;
	NamXuatBan= nam;
	GiaBia= gia;	
}

void Sach:: Nhap()
{
	cout<<"					NHAP SACH"<<endl;
	AnPham::Nhap();
	cout<<endl<<"Nhap Tac Gia: ";		
	cin>>TacGia;
	cout<<endl<<"Nhap Nha xuat ban: ";
	cin>>NhaXuatBan;
	cout<<endl<<"Nhap so trang: ";
	cin>>SoTrang;
	cout<<endl<<"Nhap Nam Xuat Ban: ";
	cin>>NamXuatBan;
	cout<<endl<<"Nhap Gia Bia: ";
	cin>>GiaBia;
}		

void Sach:: Xuat()
{
	AnPham::Xuat();

	cout<<"Tac Gia: "<<TacGia<<endl;
	cout<<"Nha XUat Ban: "<<NhaXuatBan<<endl;
	cout<<"So Trang: "<<SoTrang<<endl;
	cout<<"Nam XUat Ban: "<<NamXuatBan<<endl;
	cout<<"Gia Bia: "<<GiaBia<<endl<<endl<<endl;
}	


class DanhSachSach
{
	private:
		int n;
		Sach ListSach[1000];
	public:
		void Nhap();
		void Xuat();
		void TimTen(string ten);
		void TimTacGia(string tg);
		string TacGiaMax();
		void ThemSach(int vitri,Sach s);
		void Xoa(int vitri);
		void XoaSach(int id);
		void SapXep();
};

void DanhSachSach::Nhap()
{

	cout<<endl<<"Nhap so luong sach trong danh sach : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ListSach[i].Nhap();
	}
}

void DanhSachSach::Xuat()
{
	cout<<"			XUAT DANH SACH SACH"<<endl;
	for(int i=0;i<n;i++)
	{
		ListSach[i].Xuat();
	}
}

void DanhSachSach::TimTen(string ten)
{
	for(int i=0;i<n;i++)
	{
		if(ListSach[i].getTen()== ten)
		{
			ListSach[i].Xuat();
		}
	}
	
}

void DanhSachSach::TimTacGia(string tg)
{
	for(int i=0;i<n;i++)
	{
		if(ListSach[i].getTenTacGia()== tg)
		{
			ListSach[i].Xuat();
		}
	}
}

string DanhSachSach::TacGiaMax()
{
	int max=1;
	int index=0;
	int k;
	for(int i=0;i<n-1;i++)
	{
		k=1;
		for(int j=i;j<n;j++)
		{
			if(ListSach[i].getTenTacGia()==ListSach[j].getTenTacGia())
			{
				k++;
			}
		}
		if(k>max){
			max=k;
			index=i;
		}
	}
	return ListSach[index].getTenTacGia();
}

void DanhSachSach::ThemSach(int vitri,Sach s)
{
	for(int i=n;i>vitri;i--)
	{
		ListSach[i]=ListSach[i-1];
	}
	ListSach[vitri]=s;
	n++;
}

void DanhSachSach::Xoa(int vitri)
{
	for(int i=vitri;i<n-1;i++)
	{
		ListSach[i]=ListSach[i+1];
	}
	n--;
}

void DanhSachSach::XoaSach(int id)
{
	for(int i=0;i<n;i++)
	{
		if(ListSach[i].getID()==id)
		{
			Xoa(i);
		}
	}
}

void DanhSachSach::SapXep()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n;j++)
		{
			if((ListSach[i].getTen().compare(ListSach[j].getTen())==1)
				|| ((ListSach[i].getTen().compare(ListSach[j].getTen())==1)
						&&(ListSach[i].getNamXuatBan()>ListSach[j].getNamXuatBan())))
		
			{
				Sach nhap;
				nhap=ListSach[i];	
				ListSach[i]=ListSach[j];
				ListSach[j]=nhap;
			}	
		}
	}
}

int main()
{
	AnPham ap1;
	ap1.Nhap();
	ap1.Xuat();
	
	Sach s1;
	s1.Nhap();
	s1.Xuat();
	
	TapChi tc1;
	tc1.Nhap();
	tc1.Xuat();

	Sach s2;
	s2.Nhap();
	
	
	DanhSachSach ds1;
	ds1.Nhap();
	ds1.Xuat();
	
	ds1.TimTen("a");

	ds1.TimTacGia("a");

	cout<<"tac gia nhieu dau sach nhat: "<<ds1.TacGiaMax()<<endl;
	
	ds1.ThemSach(2,s2);
	ds1.Xuat();
	
	ds1.Xoa(0);
	ds1.Xuat();
	
	ds1.XoaSach(1);
	ds1.Xuat();
	
	ds1.SapXep();
	ds1.Xuat();

}

