#include <iostream>
#include <algorithm>

using namespace std;
//Liet ke theo canh:  Diem dau , Diem cuoi, Trong so theo thu tu tang dan
//int a[12][3]={{1,2,1},{2,3,2},{4,5,3},{6,7,3},{1,4,4},{3,5,4},{4,7,4},{3,6,5},{2,4,6},{2,5,6},{5,7,7},{5,6,8}};

typedef struct Egde {
    int x,y;
};

//ma tran ke: nhung dinh nao ko no truc tiep voi nhau bd= 10000;; gia tri qua lon
int n=7;
int c[10][10]={{0,1,10000,4,10000,10000,10000},
                {1,0,2,6,6,10000,10000},
                {10000,2,0,10000,4,5,10000},
                {4,6,10000,0,3,10000,4},
                {10000,6,4,3,0,8,7},
                {10000,10000,5,10000,8,0,3},
                {10000,10000,10000,4,7,3,0}
            };

//QuickSort sap xep tang dan
int Partition(int a[],int l,int r){
    int x=a[l];
    int i=l+1;
    int j=r;
    while(i<j){
        while(i<j && a[i]<x)    i++;
        while(j>=i && a[j]>=x)  j--;
        if(i<j) swap(a[i],a[j]);
    }
    if(a[l]>a[j])   swap(a[l],a[j]);
    return j;
}
void QuickSort(int a[],int l,int r){
    if(l>=r)    return;
    int i=Partition(a,l,r);
    QuickSort(a,l,i-1);
    QuickSort(a,i+1,r);
}

//MergeSort//
void Merge(int a[],int l,int t,int r)
{
    int c[20];
    int i=l,j=t+1,p=l;
    while(i<=t && j<=r){
        if(a[i]<a[j]){
            c[p]=a[i];
            i++;
        }
        else{
            c[p]=a[j];
            j++;
        }
        p++;
    }
    while(i<=t){
        c[p]=a[i];
        i++; p++;
    }
    while(j<=r){
        c[p]=a[j];
        j++; p++;
    }
    for(int k=l;k<=r;k++){
        a[k]=c[k];
    }
}
void MergeSort(int a[],int l,int r)
{
    if(l>=r)    return;
    int t=(l+r)/2;
    MergeSort(a,l,t);
    MergeSort(a,t+1,r);
    Merge(a,l,t,r);
}


///Thuat Toan Prim
void Prim(int Closest[],int lowcost[])//closest[i] luu lai dinh phia truoc cua dinh i
{//lowcost[i] luu lai gia tri tu dinh i den cay khung truoc khi them i vao
    int k,Min;//k luu lai dinh dk chon de them vao cay khung, Min bien tam tim lowcost  min
    ///chon dinh xuat phat la 0, khoi tao
    for(int i=1;i<n;i++){
        lowcost[i]=c[0][i];
        Closest[i]=0;///cac dinh con lai tam thoi noi vao dinh 0
    }

    cout<<"cay khung be nhat: ";

    for(int i=1;i<n;i++){
        /// tim dinh gan dinh moi them vao cay nhat
        Min=10000;//bang dung gia tri ko noi dk giua 2 dinh
        k=-1;
        for(int j=1;j<n;j++){
            if(lowcost[j]<Min && lowcost[j]>-1){//chi thoa man neu ton tai 2 dinh noi dk vs nhau va khac
                k=j;                            // cac dinh da dk chon
                Min=lowcost[j];
            }
        }
        if(k==-1) {cout<<"khong tim dk cay khung"; return;}
        lowcost[k]=-1;//chon dk dinh k la dinh ke tiep them vao cay khung
        cout<<" ( "<<Closest[k]<<","<<k<<" ) ";
        ///cap nhat lai lowcost vi cay khung da them dinh k vao
        for(int j=1;j<n;j++){
            if(lowcost[j]>c[k][j] ){
                lowcost[j]=c[k][j];
                Closest[j]=k;
            }
        }
    }
}



///Kruskal
//Nếu D[i]=D[j]=0, cạnh (i,j) chưa thuộc vào cây nên
//khi lấy 2 đỉnh này vào tập cạnh ta cho chúng thuộc
//vào 1 cây mới. Khi đó k=k+1 và D[i]=D[j]=k.
//– Nếu D[i]=0 và D[j]<>0: i chưa thuộc vào T, j thuộc
//T => Ghép i vào cùng cây chứa j, D[i]=D[j].
//– Nếu D[i]<>0 và D[j]=0: i thuộc vào T, j không thuộc
//T => Ghép j vào cùng cây chứa i, D[j]=D[i].
//– Nếu D[i]<>D[j] và D[i]<>0, D[j]<>0: i, j thuộc 2 cây
//khác nhau trong T => Ghép 2 cây thành 1

void Kruskal()
{
    int D[10];///D[i]: dinh i thuoc cay thu bn
    Egde L[10];
    int Dem=0,Sum=0,T=0;///Dem: tim du so canh thi dung, Sum: tong gia tri cay, T: so cay tao moi(xem duoi)
    int Min;
    for(int i=0;i<n;i++)    D[i]=0;///tat ca dinh ban dau chua thuoc cay nao

    do{
        Min=10000;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            ///tim 2 dinh co canh nho nhat: ko trung nhau, ko thuoc cung 1 cay:(D[i]!=0 va D[i]=D[j] thi no thuoc cung cay)
                if(Min>c[i][j] && c[i][j]>0 && !(D[i]!=0 && D[i]==D[j]))
                {
                    L[Dem].x=i; L[Dem].y=j;///luu lai 2 dinh cua canh
                    Min=c[i][j];
                    //cout<<Min;
                }
            }
        }
        if(Min==10000)  {cout<<"khong co cay bao trum "; return;}
        ///sau khi tim dk canh nho nhat: lan luot xem thuoc loai nao trong so 4 loai ben tren de them
        ///Loai 1: D[i]=D[j]=0
        if(D[L[Dem].x] ==0 && D[L[Dem].y] == 0){
            T++;
            D[L[Dem].x] = D[L[Dem].y] = T;
        }
        ///Loai 2: D[i]=0 va D[j]!=0
        if(D[L[Dem].x] == 0 && D[L[Dem].y] != 0)
            D[L[Dem].x] = D[L[Dem].y];

        ///Loai 3: D[i]!=0 va D[j]=0
        if(D[L[Dem].x] != 0 && D[L[Dem].y] == 0)
            D[L[Dem].y] = D[L[Dem].x];

        ///Loai 4: thuoc 2 cay khac nhau va phai noi : chuyen het nhung dinh thuoc cay D[i] sang cay D[j]
        if(D[L[Dem].x] != D[L[Dem].y] && D[L[Dem].y]!=0) {
            int Temp = D[L[Dem].x];
            for(int i=0; i<n; i++)
            if(Temp==D[i])
            D[i]=D[L[Dem].y];
        }
        Sum+=Min;
        Dem++;
    }
    while(Dem<n-1);

    ///Xuat Thong tin cay
    cout<<"cay bao trum nho nhat la: ";
    for(int i=0;i<n-1;i++){
        cout<<" ( "<<L[i].x<<","<<L[i].y<<" ) ";
    }
    cout<<endl<<"Tong gia tri cay  :"<<Sum;
}

int main()
{
//    int Closest[10],lowcost[10];
//    Prim(Closest,lowcost);
    Kruskal();
    return 0;
}
