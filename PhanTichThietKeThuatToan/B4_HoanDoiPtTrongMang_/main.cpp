#include <iostream>

using namespace std;

void Swap(int &a, int &b){
    int c=a;
    a=b;
    b=c;
}

void HoanDoi(int a[],int n,int m){
    for(int i=0;i<m;i++){
        Swap(a[i],a[n-m+i]);
    }
}

void HoanDoiPtDauVeCuoi(int a[],int n, int m)
{

    if(m==n-m)  {
        HoanDoi(a,n,m);
        return;
    }
    else if(m<n-m)   {
        HoanDoi(a,n,m);
        HoanDoiPtDauVeCuoi(a,n-m,m);
    }
    else    {
        HoanDoi(a,n,n-m);
        HoanDoiPtDauVeCuoi(a,n-m,m);
    }
}

void Xuat(int a[],int n)
{
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int a[9]={1,2,3,4,5,6,7,8,9};
    Xuat(a,9);
    cout<<"Hoan doi 3 phan tu dau ve cuoi: "<<endl;
    HoanDoiPtDauVeCuoi(a,9,4);
    Xuat(a,9);
    return 0;
}
