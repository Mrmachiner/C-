#include<iostream>
#include<string>

using namespace std;

class NhanVien
{
	private:
		int maNV;
		string hoTen;
		int namSinh;
		bool gioiTinh;
		string phongBan;
		double hesoLuong;
		double phuCap;
	public:
		NhanVien()
		{
			hoTen= "HC";
		}
		double tinhLuong()
		{
			return (hesoLuong*1200000+phuCap);
		}
		
		int getTuoi()
		{
			return 2018-this->namSinh;
		}
		int getGioiTinh()
		{
			return this->gioiTinh;
		}
		void NhapDL()
		{
			cout<<"ma nhan vien:"<<endl;
			cin>>maNV;
			cout<<"ho ten nhan vien: "<<endl;
			cin>> hoTen;
			cout<<"nam sinh:"<<endl;
			cin>>namSinh;
			cout<<"gioi tinh "<<endl;
			cin>>gioiTinh;
			cout<<"phong ban: "<<endl;
			cin>>phongBan;
			cout<<"he so luong:"<<endl;
			cin>>hesoLuong;
			cout<< "phu cap: "<<endl;
			cin>>phuCap;
		}
		void XuatDL()
		{
			cout<<"THONG TIN NHAN VIEN :"<<endl;
			cout<<"ma nhan vien:"<<maNV<<endl;
			cout<<"ho ten nhan vien: "<<hoTen<<endl;
			cout<<"nam sinh:"<<namSinh<<endl;
			cout<<"gioi tinh "<< gioiTinh<<endl;
			cout<<"phong ban: "<<phongBan<<endl;
			cout<<"he so luong:"<< hesoLuong<<endl;
			cout<< "phu cap: "<<phuCap<<endl;
		}
		
};

class listNV
{
	private:
		int n;
		NhanVien ListNv[100];
	public:
		listNV();
		void Nhap();
		int LuongCaoNhat();
		int TongQuyLuong();
		int NguoiVeHuu();
};

listNV::listNV()
{
	n=3;
}
void listNV::Nhap()
{
	for(int i=0;i<n;i++)
	{
		ListNv[i].NhapDL();
	}
}
int listNV::LuongCaoNhat()
{
	int max= ListNv[0].tinhLuong();
	for(int i=1;i<n;i++)
	{
		if(ListNv[i].tinhLuong()>max)
		{
			max= ListNv[i].tinhLuong();
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ListNv[i].tinhLuong()== max)
		{
			ListNv[i].XuatDL();
		}
	}
	return 1;
}
int listNV::TongQuyLuong()
{
	int Tong=0;
	for(int i=0;i<n;i++)
	{
		Tong+=ListNv[i].tinhLuong();
	}
	return Tong;
}
int listNV::NguoiVeHuu()
{
	for(int i=0;i<n;i++)
	{
		if(ListNv[i].getGioiTinh()== true && ListNv[i].getTuoi()>=58)
		{
			ListNv[i].XuatDL();
		}
		if(ListNv[i].getGioiTinh()== false && ListNv[i].getTuoi()>=55)
		{
			ListNv[i].XuatDL();
		}
	}
	return 1;
}

int main()
{
	listNV list1;
	list1.Nhap();
	cout<<"nhung nguoi co luong CAO NHAT"<<endl;
	list1.LuongCaoNhat();
	cout<<"nhung nguoi tuoi VE HUU"<<endl;
	list1.NguoiVeHuu();
	cout<<"Tong Quy Luong: "<<	list1.TongQuyLuong();
}
