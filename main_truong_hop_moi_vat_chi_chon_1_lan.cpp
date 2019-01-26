#include <stdio.h>
#include <conio.h>
#include <iostream>
int weight[1000];
int worth[1000];
int K[50][100];
int W;
int n;
FILE *input;
using namespace std;
void nhapfile()
{
    char inName[64]="D:\\TKGT\\code\\code\\Test2.txt";
    int i;
//    printf("Enter input file name: ");
//    scanf("%63s", inName);
    if ((input = fopen (inName, "r")) != NULL)
    {
    fscanf(input,"%d",&n); // so luong do vat
    fscanf(input,"%d",&W); // trong luong cai tui
    for(i=1; i<=n; i++) fscanf(input,"%d", &weight[i]); // trong luong do vat
    for(i=1; i<=n; i++) fscanf(input,"%d", &worth[i]); // gia tri do vat
    fclose(input);
    printf("\nTrong luong cai tui la: %d", W); // in du lieu da nhap
    printf("\nVec to gia tri do vat: ");
    for(i=1; i<=n; i++) printf("%d ", worth[i]);
    printf("\nVec to trong luong do vat: ");
    for(i=1; i<=n; i++) printf("%d ", weight[i]);
    }
}
void xuat(int K[50][100], int n, int w)
{
	cout<< endl;
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= w; j++)
		{
			cout<<K[i][j]<<"  ";
		}
		cout<< endl;
	}
}
void taoBang(int K[50][100],int weight[], int worth[], int n, int W)
{
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= W; j++)
		{
			if(i == 0 || j == 0)
			{
				K[i][j] = 0;
				continue;
				
			}
			if(j< weight[i])
			{
				K[i][j] = K[i-1][j];
				continue;
			}
			int x = j-weight[i];
			if(K[i-1][j] > worth[i]+K[i-1][x])
				K[i][j] = K[i-1][j];
			else 
				K[i][j] = worth[i]+K[i-1][x];
		}
	}
}
void truyVet(int K[50][100],int weight[], int worth[], int n, int W)
{
	cout<< "Cac vat nen chon la: ";
	int j = W;
	for(int i = n; i>0; i--)
	{
			if(K[i][j] != K[i-1][j])
			{
				cout<<"\t"<<i<<"\t";
				j -= weight[i];
				gt+=K[i][j];
			}
			if(K[i][j] == 0)
				return;
	}
}
int main()
{
	nhapfile();
	taoBang(K,weight,worth,n,W);
	xuat(K,n,W);
	truyVet(K,weight,worth,n,W);
	getch();
	return 0;
}
