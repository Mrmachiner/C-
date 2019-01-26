#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<time.h>
int Kg[1000],GT[1000],K[1000][1000],w,n;
FILE *input;
using namespace std;
void nhapfile(){
	char inName[1000]="D:\\TKGT\\code\\code\\Test2.txt";
	if((input=fopen(inName,"r"))!=NULL){
		fscanf(input,"%d",&n);//So Luong Do
		fscanf(input,"%d",&w);//Khoi Luong cua Balo
		for(int i=1;i<=n;i++) fscanf(input,"%d",&Kg[i]); //mang Khoi Luong
		for(int i=1;i<=n;i++) fscanf(input,"%d",&GT[i]);//Mang Gia Tri
		cout<<"Khoi Luong Cua Tui La: "<<w;
		cout<<"\n Vecto Khoi Luong Do Vat La: ";
		for(int i=1;i<=n;i++) cout<<" "<<Kg[i];
		cout<<"\n Vecto Gia Tri Do Vat La   : ";
		for(int i=1;i<=n;i++) cout<<" "<<GT[i];

	}
}
void xuat(int K[1000][1000], int n, int w)
{
	cout<< endl;
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= w; j++)
		{
			cout<<K[i][j]<<" ";
		}
		cout<< endl;
	}
}
void TaoBang(int K[1000][1000],int KG[],int GT[],int n,int w){
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= w; j++)
		{
			if(i == 0 || j == 0)
			{
				K[i][j] = 0;
				continue;
				
			}
			if(j< KG[i])
			{
				K[i][j] = K[i-1][j];
				continue;
			}
			int x = j-KG[i];
			if(K[i-1][j] > GT[i]+K[i-1][x])
				K[i][j] = K[i-1][j];
			else 
				K[i][j] = GT[i]+K[i-1][x];
		}
	}
}
void truyVet(int K[1000][1000],int KG[],int GT[],int n,int w){
	cout<<"Cac Vat Nen Chon la:\n";
	int j=w;
	int gt=0;
	for(int i=n;i>0;i--){
		if(K[i][j]!=K[i-1][j]){
			cout<<"\t"<<i<<"  ";
			gt=gt+K[i][j];
			j-=KG[i];
		}
		if(K[i][j]==0)
		break ;
	}
	cout<<"\n Gia Tri Max La: "<<gt;

}
main(){
	clock_t begin = clock();
	nhapfile();
	TaoBang(K,Kg,GT,n,w);
	xuat(K,n,w);
	truyVet(K,Kg,GT,n,w);
	clock_t end = clock(); 
   	cout<<"\nTime run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}
