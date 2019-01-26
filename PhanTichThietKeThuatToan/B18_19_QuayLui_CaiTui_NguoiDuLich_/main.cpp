#include <iostream>

using namespace std;

int n=5;
int w[10]={5,6,7,8,9};
int c[10]={7,8,9,10,10};
int chon[10]={0,0,0,0,0};
int b= 20;
int max_Temp=0;

void Xuat_CaiTui(){
    int s=0,v=0;;
    cout<<endl<<"Thong tin tui gom cac vat: ";
    for(int i=0;i<n;i++){
        if(chon[i]==1){
            cout<<i<<", ";
            s+=w[i];
            v+=c[i];
        }
    }
    cout<<"co tong trong luong: "<<s;
    cout<<" co gia tri: "<<v;
}

int tong_W(){
    int s=0;
    for(int i=0;i<n;i++){
        if(chon[i]==1)  s+=w[i];
    }
    return s;
}

int tong_C(){
    int s=0;
    for(int i=0;i<n;i++){
        if(chon[i]==1)  s+=c[i];
    }
    return s;
}

void Kt_CaiTui(){
    for(int i=0;i<n;i++){
        chon[i]=0;
    }
}

void Try_CaiTui(int i)
{
    for(int j=i+1;j<n;j++){
        if(chon[j]==0 && tong_W()+w[j]<=b){
            chon[j]=1;
            Try_CaiTui(j);
            chon[j]=0;///quay tro lai
        }
    }
    if(max_Temp<tong_C()){///chi xuat ra truong hop sau neu gia tri tui lon hon truong hop truoc
        max_Temp=tong_C();
        Xuat_CaiTui();
    }
}

///Bai toan nguoi du lich
 int a[10][10]={{0,1,2,7,5},
                {1,0,4,4,3},
                {2,4,0,1,2},
                {7,4,1,0,3},
                {5,3,2,3,0}
            };
int n2=5;
int Tour[10];
bool Daxet[10];
int Ddau=0;

///khoi tao
void Kt_DuLich(){
    for(int i=0;i<n2;i++){
        Daxet[i]=false;
    }
    Daxet[Ddau]=true;
    Tour[0]=Ddau;
}

///gia tri quang duong
int Tong_DuLich(){
    int s=0;
    for(int i=0;i<n2;i++){
        s+=a[Tour[i]][Tour[(i+1)]];
    }
    return s;
}
///Xuat ket qua
void Xuat_DuLich()
{
    cout<<endl<<"chu trinh la: ";
    for(int i=0;i<=n2;i++)   cout<<Tour[i]<<"  ";
    cout<<endl<<"gia tri cua chu trinh la: "<<Tong_DuLich()<<endl;
}

void Try_DuLich(int i){///tim dinh thu i trong chu trinh
    if(i==n){
        if(a[i-1][Ddau]>0 && a[i-1][Ddau]<10000)    {
            Tour[i]=Ddau;
            Xuat_DuLich();
        }
        else return;
    }
    for(int j=0;j<n2;j++){
        if(a[Tour[i-1]][j]>0 && a[Tour[i-1]][j]<10000 && !Daxet[j]){
            Tour[i]=j;
            Daxet[j]=true;
            Try_DuLich(i+1);

            Daxet[j]=false;//tra lai trang thai
        }
    }
}



int main()
{
//    for(int i=0;i<n;i++){
//        chon[i]=1;
//        Try_CaiTui(i);
//        chon[i]=0;
//    }
    Kt_DuLich();

    Try_DuLich(1);


    return 0;
}
