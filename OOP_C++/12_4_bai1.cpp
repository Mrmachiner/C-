#include<iostream>
using namespace std;

class DaThuc
{
	private:
		int N;
		float A[100];
	public:
		DaThuc();
		void Nhap();
		void Xuat();
		float TinhGiaTri(float x0);
		DaThuc operator* (float k);
		bool operator> (DaThuc dt2);
		bool operator< (DaThuc dt2);
		bool operator== (DaThuc dt2);
		bool operator!= (DaThuc dt2);
		DaThuc operator+ (DaThuc dt2);
};

DaThuc::DaThuc()
{
	N=0;
}

void DaThuc::Nhap()
{
	cout<<endl<<"Nhap vao so bac cua da thuc: ";
	cin>>N;
	cout<<endl<<"Nhap vao cac he so cua da thuc: ";
	for(int i=0;i<=N;i++)
	{
		cout<<endl<<"A["<<i<<"]= ";
		cin>>A[i];
	}
}

void DaThuc::Xuat()
{
	cout<<A[0];
	for(int i=1;i<=N;i++)
	{
		if(A[i]!=0)		cout<<"+ "<<A[i]<<"*x^"<<i;	
	}
	cout<<endl;
}

float DaThuc::TinhGiaTri(float x0)
{
	float kq=A[0];
	float x=x0;
	for(int i=1;i<=N;i++)
	{
		kq+=A[i]*x;
		x*=x0;
	}
	return kq;
}

DaThuc DaThuc::operator*(float k)
{
	DaThuc dt;
	dt.N= this->N;
	for(int i=0;i<=N;i++)
	{
		dt.A[i]=this->A[i]*k;
	}
	return dt;
}

bool DaThuc::operator>(DaThuc dt2)
{
	if(this->N> dt2.N)
		return true;
	else if(this->N< dt2.N)
		return false;
	for(int i=N;i>=0;i--)
	{
		if(this->A[i]>dt2.A[i])
			return true;
		else if(this->A[i]<dt2.A[i])
			return false;		
	}
	
	return false;
}

bool DaThuc::operator<(DaThuc dt2)
{
	if(this->N< dt2.N)
		return true;
	else if(this->N> dt2.N)
		return false;
	for(int i=N;i>=0;i--)
	{
		if(this->A[i]<dt2.A[i])
			return true;
		else if(this->A[i]>dt2.A[i])
			return false;		
	}	
	return false;
}

bool DaThuc::operator==(DaThuc dt2)
{
	if(this->N!= dt2.N)
		return false;
	for(int i=0;i<=N;i++)
	{
		if(this->A[i]!= dt2.A[i])
			return false;
	}	
	
	return true;
}

bool DaThuc::operator!=(DaThuc dt2)
{
	if(this->N!= dt2.N)
		return true;
	for(int i=0;i<=N;i++)
	{
		if(this->A[i]!= dt2.A[i])
			return true;
	}	
	
	return false;
}

DaThuc DaThuc::operator+(DaThuc dt2) 
{
	DaThuc dt3;
	int i=0;
	while(i<=this->N || i<= dt2.N)
	{
		if(i<=this->N && i<= dt2.N)
		{
			dt3.A[i]=this->A[i]+ dt2.A[i];
		}
		else if(i<=this->N && i> dt2.N)
		{
			dt3.A[i]= this->A[i];
		}
		else 
		{
			dt3.A[i]= dt2.A[i];
		}
		i++;
	}	
	dt3.N=i;

	while(N>0 && dt3.A[N]==0)
	{
		dt3.N--;
	}
	
	return dt3;
}

int main()
{
	DaThuc dt1;
	dt1.Nhap();
	dt1.Xuat();
	
	float f= dt1.TinhGiaTri(3);
	cout<<"gia tri  = "<<f<<endl;
	
	DaThuc dt2;
	dt2.Nhap();
	dt2.Xuat();
	
	if(dt1>dt2){
		cout<<"da thuc1 lon hon da thuc 2"<<endl;
	}
	if(dt1<dt2){
		cout<<"da thuc 1 nho hon da thuc 2"<<endl;
	}
	if(dt1== dt2){
		cout<<"dathuc 1 bang da thuc 2"<<endl;
	}
	if(dt1!= dt2)
	{
		cout<<"da thuc 1 khac da thuc 2"<<endl;
	}
	
//	dt2=dt2*2;
//	cout<<"sau khi nhan vois 2:"<<endl;
//	dt2.Xuat();
	
	DaThuc dt3= dt1+ dt2;
	dt3.Xuat();
	
	
}
