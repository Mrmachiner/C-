#include <iostream>

using namespace std;

int a[10][10]={{0,20,15,-1,80,-1},
                    {40,0,-1,-1,10,30},
                    {20,4,0,-1,-1,10},
                    {36,18,15,0,-1,-1},
                    {-1,-1,90,15,0,-1},
                    {-1,-1,45,4,10,0}
            };
int n=6;

void XuatDdnn(int Ddnn[10],int s,int k){
    cout<<"Duong Di Ngan Nhat tu "<<s<<" den "<<k<<": ";
    int i=k;
    while(i!=s){
        cout<<i<<" <= ";
        i=Ddnn[i];
    }
    cout<<s<<endl;
}

void Dijkstra(int s)
{
    int Ddnn[10];//chua duong di ngan nhat tu dinh s den cac dinh con lai
    int i,//bien dem de duyet mang
        k,//bien luu dinh ke tiep trong chu trinh
        Dht,//bien luu dinh hien tai cua chu trinh dang tim
        Min;//dung de tim nhan nho nhat
    bool Daxet[10];//danh dau nhung dinh da dk dua vao s
    int L[10];//L[i] chua nhan cua dinh i
    ///khoi tao///
    for(i=0;i<n;i++){
        Daxet[i]=false;
        L[i]=10000;
    }
    //dua s vao tap dinh
    Daxet[s]=true;
    L[s]=0;
    //Ddnn[s]=0;
    Dht=s;
    int h=1;//dem du n dinh thi dung lai

    ///Chay////
    while(h<n)
    {
        Min=10000;
        for(i=0;i<n;i++){
            if(!Daxet[i]){
                if(a[Dht][i]!=-1 && L[Dht]+ a[Dht][i]<L[i]){///cap nhat nhan
                    L[i]= L[Dht]+a[Dht][i];
                    Ddnn[i]=Dht;///gan dinh hien tai la dinh truoc cua i tren lo trinh
                }
                if(L[i]<Min){
                    Min=L[i];
                    k=i;
                }
            }
        }
         ///tai buoc h: tim dk duong di ngan nhat tu s->k
         XuatDdnn(Ddnn,s,k);
         cout<<"gia tri la: "<<L[k]<<endl<<endl;
         Dht=k;
         Daxet[Dht]=true;
         h++;

    }
}

int main()
{

    Dijkstra(0);


    return 0;
}
