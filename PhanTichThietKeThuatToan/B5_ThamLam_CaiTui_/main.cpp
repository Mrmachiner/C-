#include <iostream>

using namespace std;

int n=5;
int w[10]={5,6,7,8,9};
int c[10]={7,8,9,10,10};
int chon[10]={0,0,0,0,0};
int b= 20;

int tongW(){
    int s=0;
    for(int i=0;i<n;i++){
        if(chon[i]==1){
            s+=w[i];
        }
    }
    return s;
}
int tongC(){
    int s=0;
    for(int i=0;i<n;i++){
        if(chon[i]==1){
            s+=c[i];
        }
    }
    return s;
}

void XuatDB(){
    int i;
    cout<<endl<<"Vat        :";
    for(i=0;i<n;i++){
        cout<<i+1<<"  ";
    }
    cout<<endl<<"Trong Luong:";
    for(i=0;i<n;i++){
        cout<<w[i]<<"  ";
    }
    cout<<endl<<"Gia Tri    :";
    for(i=0;i<n;i++){
        cout<<c[i]<<"  ";
    }
    cout<<endl;
}
void XuatKQ()
{
    cout<<endl<<"cac vat dk chon la: ";
    for(int i=0;i<n;i++){
        if(chon[i]==1) cout<<i+1;
    }
    cout<<endl<<"co tong trong luong la: "<<tongW()<<endl;
    cout<<endl<<"co tong gia tri la: "<<tongC()<<endl;
}

/// Tham lam 1: chon vat co gia tri lon nhat

int select1(){
    int Max=-10000;
    int k=-1;
    for(int i=0;i<n;i++){
        if(!chon[i] && c[i]>=Max){
            Max=c[i];
            k=i;
        }
    }
    return k;
}

/// Tham lam 2: chon vat co trong luong nho nhat

int select2(){
    int Min=10000;
    int k=-1;
    for(int i=0;i<n;i++){
        if(!chon[i] && w[i]<=Min){
            Min=w[i];
            k=i;
        }
    }
    return k;
}
/// Tham lam 3: chon vat co ti le (giatri/trongluon) lon nhat

int select3(){
    float Max=-10000;
    int k=-1;
    for(int i=0;i<n;i++){
        if(!chon[i] && ((1.0*c[i])/(1.0*w[i]))>=Max){
            Max=(1.0*c[i])/(1.0*w[i]);
            k=i;
        }
    }
    return k;
}

void ThamLam()
{
    //int k=select1();
    //int k=select2();
    int k=select3();
    if(k<0)     return;
    if(tongW()+w[k]<b)   {
        chon[k]=1;
        ThamLam();
    }
    else {
        chon[k]=2;
        ThamLam();
    }

}

int main()
{
    XuatDB();
    ThamLam();
    XuatKQ();
    return 0;
}
