#include <iostream>

using namespace std;

//Qui ước màu là các số: 1, 2, 3, ...
//1. Tô màu một đỉnh bất kỳ với màu 1
//2. Với đỉnh v chưa tô màu: Tô nó với màu là số nhỏ
//nhất chưa dùng với các đỉnh kề và đã được tô
//màu của v. (Nếu tất cả các đỉnh kề của v đã tô
//màu -> v sẽ được tô với màu mới).
bool a[10][10]={{0,1,1,1,0,0,1,0,0},
                {1,0,0,0,0,0,0,0,1},
                {1,0,0,1,0,1,1,1,0},
                {1,0,1,0,0,1,0,0,1},
                {0,0,0,0,0,1,1,0,1},
                {0,0,1,1,1,0,1,1,1},
                {1,0,1,0,1,1,0,0,0},
                {0,0,1,0,0,1,0,0,0},
                {0,1,0,1,1,1,0,0,0}
            };
int n=9;

bool KtToXong(int mau[]){///Kiem tra xem to het cac mau chua
    for(int i=0;i<n;i++){
        if(mau[i]==0)   return false;
    }
    return true;
}

void ToMau(int mau[],int k)
{
    if(KtToXong(mau))   return;///neu da to xong roi thi thoi
    for(int i=0;i<n;i++){
        if(a[k][i] && mau[i]==0){///tim cac dinh ke voi dinh hien tai ma chua dk to mau
            mau[i]=1;///mau be nhat co the
            int j=0;
            while(j<n){///tai moi dinh to mau be nhat chua co trong so cac dinh ke da dk to mai
                if(a[i][j] && mau[j]==mau[i]){///neu dinh ke da to mau hien tai roi=> tang len
                    mau[i]++;
                    j=-1;///khi tang mau len phai dem lai tu dau , neu ko se bi mat
                }
                j++;
            }///to xong dinh ke nay roi => tim cac dinh ke voi dinh vua to
            ToMau(mau,i);
        }
    }
}

void ThamLam_ToMau(int s)///mau[i] luu lai mau to cho dinh i, s la dinh to mau dau tien
{
    int mau[10];
    for(int i=0;i<n;i++)    mau[i]=0;///khoi tao
    mau[s]= 1;///to mau so 1 cho dinh xuat phat

    ToMau(mau,s);
    ///xuat thong tin mau
    for(int i=0;i<n;i++)
        cout<<"Dinh thu "<<i+1<<" To mau "<<mau[i]<<endl;
}


///Phan II Bai toan khoang khong giao nhau
typedef struct Cviec{
    int Bdau,Kthuc,id;
};

int b[10]={2,3,1,10,6 ,9 ,16,14};
int e[10]={5,7,8,13,15,17,20,18};

void Nhap(Cviec cviec[],int n)
{
    for(int i=0;i<n;i++){
        cviec[i].id=i+1;
        cviec[i].Bdau=b[i];
        cviec[i].Kthuc=e[i];
    }
}

///Sapxep cong viec theo thu tu tang dan thoi diem bat dau
void SapXep1(Cviec cviec[],int n)
{
    for(int i=0;i<n-1;i++){///sap xep chon
        for(int j=i;j<n;j++){
            if(cviec[i].Bdau>cviec[j].Bdau){
                swap(cviec[i],cviec[j]);
            }
        }
    }
}

///Phan 2 dung han sap xep nhanh cho oai: sap xep cong viec theo thu tu tang dan (ketthuc- batdau)
int Partition(Cviec cviec[],int l,int r){
    int x=(cviec[l].Kthuc-cviec[l].Bdau);
    int i=l+1;
    int j=r;
    while(i<j){
        while(i<j && (cviec[i].Kthuc-cviec[i].Bdau)<x)    i++;
        while(j>=i && (cviec[j].Kthuc-cviec[j].Bdau)>=x)  j--;
        if(i<j) swap(cviec[i],cviec[j]);
    }
    if((cviec[l].Kthuc-cviec[l].Bdau)>(cviec[j].Kthuc-cviec[j].Bdau))   swap(cviec[l],cviec[j]);
    return j;
}
void QuickSort2(Cviec cviec[],int l,int r){
    if(l>=r)    return;
    int i=Partition(cviec,l,r);
    QuickSort2(cviec,l,i-1);
    QuickSort2(cviec,i+1,r);
}

///Phan 3: sap xep theo thu tu tang dan cua thoi diem ket thuc
void SapXep3(Cviec cviec[],int n)
{
    for(int i=0;i<n-1;i++){///sap xep chon
        for(int j=i;j<n;j++){
            if(cviec[i].Kthuc>cviec[j].Kthuc){
                swap(cviec[i],cviec[j]);
            }
        }
    }
}

int XepLich(Cviec cviec[],int n,Cviec chon[])
{
    ///SapXep1(cviec,n);
    SapXep3(cviec,n);
    int k=0;
    for(int i=0;i<n;i++){
        bool Duocchon=true;
        for(int j=0;j<k;j++){
            if((cviec[i].Bdau<chon[j].Kthuc && cviec[i].Kthuc>chon[j].Bdau))
            {
                Duocchon=false;
                break;
            }
            ///xet cv thu i,neu thoi diem bat dau cua no nho hon thoi diem ket thuc cua bat ky cv nao da dk chon
            /// hoac thoi diem ket thuc cua no nho hon thoi diem bat dau cua......=> out ngay vi bi trung
            ///xet den cv tiep theo
        }
        ///Neu thoa man ko bi trung  them no vao cv dk chon
        if(Duocchon){
            chon[k].Bdau=cviec[i].Bdau;
            chon[k].id=cviec[i].id;
            chon[k].Kthuc=cviec[i].Kthuc;
            k++;
        }
    }
     ///xuat ket qua
    cout<<"cac cong viec lan luot la: ";
    for(int i=0;i<k;i++)
        cout<<chon[i].id<<"  ";

    return k;
}

int main()
{
    Cviec cviec[10],chon[10];
    Nhap(cviec,8);
    for(int i=0;i<8;i++){
        cout<<"cv "<<cviec[i].id<<" : "<<cviec[i].Bdau<<" - "<<cviec[i].Kthuc<<endl;
    }
    int c=XepLich(cviec,8,chon);

    //ThamLam_ToMau(2);
    return 0;
}
