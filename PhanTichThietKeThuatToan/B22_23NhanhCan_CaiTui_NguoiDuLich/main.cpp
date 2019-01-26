#include <iostream>

using namespace std;

///Bai toan cai tui loai 2: Knapsharp 2
int n=5;
int ten[10]={1,2,3,4,5};
int w[10]={5,6,7,8,9};///trong luong
int v[10]={7,8,9,10,10};///Gia tri
float dg[10];///mang don gia luu gia tri v/w

int m= 24;
int S,TL;///S la gia tri/Tl la trong luong cua tui thu dk

///output
int x[10];///loi giai tam gioi
int fx;///gia tri loi giai  tam thoi

int Patu[10];///loi giai toi uu (phuong an toi uu)
int Gttu;///gia tri cua loi giai toi uu (Gia tri toi uu)


void Xuat_CaiTui(){
    int kl=0;
    cout<<endl<<"Thong tin tui gom cac vat: "<<endl;
    for(int i=0;i<n;i++){
        if(Patu[i]!=0){
            cout<<" Vat "<<ten[i]<<" co so luong:  "<<Patu[i]<<endl;
            kl+=Patu[i]*w[i];
        }
    }
    cout<<"co tong trong luong: "<<kl<<endl;
    cout<<" co gia tri: "<<Gttu<<endl;
}

void Kt_CaiTui(){
    S=0;TL=0;fx=0;Gttu=0;
    for(int i=0;i<n;i++){
        x[i]=0;
        Patu[i]=0;
        dg[i]=1.0*v[i]/w[i];
    }
    ///sap xep mang dg theo thu tu giam dan v[i]/w[i]
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(dg[i]<dg[j]){
                swap(ten[i],ten[j]);
                swap(w[i],w[j]);
                swap(v[i],v[j]);
                swap(dg[i],dg[j]);
            }
        }
    }

}

void CapNhat_Gttu(){
    for(int i=0;i<n;i++)
        Patu[i]=x[i];
}

void Try_CaiTui(int i)
{
    int t= (m-TL)/w[i];///so luong vat i co the dua vao tui
    int g;///de danh gia can
    for(int j=t;j>=0;j--){
        x[i]=j;///chon j(soluong) vat  thu i
        TL+= w[i]*x[i];///cap nhat trong luong
        S+= v[i]*x[i];///cap nhat gia tri
        if(i==n-1){///duyet het: kiem tra toi uu
            if(S>Gttu){
                CapNhat_Gttu();
                Gttu=S;
            }
        }
        else{
            g= S+ dg[i+1]*(m-TL);/// day la danh gia can tot nhat co the vi dg la ti le cao nhat
            if(g>Gttu){/// neu can nay ko tot hon thi ko can try lam gi nua
                Try_CaiTui(i+1);
            }
        }
        TL-= w[i]*x[i];///cap nhat trong luong
        S-= v[i]*x[i];///cap nhat gia tri
       // cout<<"ql  ";
    }
}



///Bai toan nguoi du lich
int n2=5;
//int C[10][10]={{0,1,2,7,5},
//                {1,0,4,4,3},
//                {2,4,0,1,2},
//                {7,4,1,0,3},
//                {5,3,2,3,0}
//            };
int C[10][10]={{0,3,14,18,15},
                {3,0,4,22,20},
               {17,9,0,16,4},
               {6,2,7,0,12},
                {9,15,11,5,0}
            };
bool Daxet[10];///xem diem nay da co trong hanh trinh chua
int Ddau;///diem xuat phat
int x2[10];///luu lai lan luot hanh trinh
int S2;///gia tri cua hanh trinh
int Cmin;

int Gttu2;///gia tri cua hanh trinh co chi phi ngan nhat
int Lgtu[10];/// hanh trinh voi chi phi ngan nhat

void Xuat_DuLich(){
    cout<<"Duong di toi uu het cac thanh pho: "<<endl;
    for(int i=0;i<=n2;i++){
        cout<<"  "<<Lgtu[i];
    }
    cout<<endl<<"Voi gia tri la: "<<Gttu2<<endl;
}

void Kt_DuLich(){
    Ddau=0;
    for(int i=0;i<n2;i++){
        Daxet[i]=false;
    }
    ///tim Cmin
    Cmin=10000;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n2;j++){
            if(Cmin>C[i][j] && C[i][j]>0 && C[i][j]<10000){
                Cmin=C[i][j];
            }
        }
    }
    cout<<"Cmin la: "<<Cmin<<endl;
    ///trang thai dau
    Daxet[Ddau]=true;
    x2[0]=Ddau;
    Gttu2=10000;
    S2=0;
}

void CapNhat_Lttu(){
    for(int i=0;i<=n2;i++){
        Lgtu[i]=x2[i];
    }
}

void Try_DuLich(int i)///tim dinh thu i trong hanh trinh
{
    int g,Tong;///g de danh gia can, tong de luu gia tri khi ve ca dinh dau tien
    for(int j=1;j<n2;j++){
        if(C[x2[i-1]][j]>0 && C[x2[i-1]][j]<10000 && !Daxet[j] ){
            Daxet[j]=true;
            x2[i]=j;
            S2+=C[x2[i-1]][x2[i]];
            if(i==n2-1 && C[x2[i]][Ddau]>0 && C[x2[i]][Ddau]<10000){
                x2[i+1]=Ddau;
                Tong=S2+ C[x2[i]][Ddau];
                if(Tong<Gttu2){
                    CapNhat_Lttu();
                    Gttu2=Tong;
                }
            }
            else{
                g= S+ (n2-i)*Cmin;
                if(g<Gttu2){
                    Try_DuLich(i+1);
                }
            }
            S2-=C[x2[i-1]][x2[i]];
            Daxet[j]=false;
        }
    }

}

int main()
{
//    Kt_CaiTui();
//    Try_CaiTui(0);
//    Xuat_CaiTui();
    Kt_DuLich();
    Try_DuLich(1);
    Xuat_DuLich();

    return 0;
}
