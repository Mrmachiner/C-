#include <iostream>

using namespace std;


int GTS(int a[10][10],int n,int Tour[],int Ddau)
{
    int v,//dinh dang xet
        k,//bien tam de duyet
        w;//dinh dk chon tai moi buoc
    int mini,//gia tri nho nhat tam thoi
        cost;//gia tri nho nhat cua chu trinh
    bool daxet[10];//mang bao hieu xem dinh thu i da xet tai chu trinh chua
    for(k=0;k<n;k++)
        daxet[k]=false;
    cost=0;

    int i=1;//bien dem: khi i chay den n thi ket thuc
    v=Ddau;
    Tour[i]=v;
    daxet[v]=true;

    while(i<n)
    {
        mini=10000;
        for(k=0;k<n;k++){
            if(!daxet[k] && mini>a[v][k]){
                mini= a[v][k];
                w=k;
            }
        }
        cost+=mini;
        i++;
        v=w;
        Tour[i]=w;
        daxet[v]=true;
    }
    cost+= a[v][Ddau];
    return cost;
}

int main()
{

    int a[10][10]={{0,1,2,7,5},
                {1,0,4,4,3},
                {2,4,0,1,2},
                {7,4,1,0,3},
                {5,3,2,3,0}
            };
    int n=5;
    int Tour[10];
    int s=GTS(a,n,Tour,0);
    cout<<"chu trinh ngan nhat la: ";
    for(int i=1;i<=n+1;i++)   cout<<Tour[i]<<"  ";
    cout<<endl<<"gia tri cua chu trinh la: "<<s;

    return 0;
}
