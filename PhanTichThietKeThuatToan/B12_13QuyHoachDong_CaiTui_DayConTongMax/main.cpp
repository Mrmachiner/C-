#include <iostream>

using namespace std;

///bai toan cai tui
int n=6,b=19;
int c[6]={7,10,20,19,13,40};
int w[6]={3,4,5,7,6,9};
int MaxV [7][20];

//Đã có MaxV(i-1,L): Giá trị lớn nhất mang đi được
//với i-1 đồ vật khi trọng lượng túi là L.
//– Xét đồ vật thứ i khi trọng lượng túi vẫn là L:
//• Chỉ mang thêm đồ vật thứ i khi giá trị của túi lúc mang
//i-1 đồ vật ở trọng lượng túi là L-w[i] (như thế mới đảm
//bảo mang thêm được đồ vật i có trọng lượng w[i] khi
//trọng lượng túi là L) cộng với giá trị của đồ vật thứ i,
//c[i], lớn hơn khi không mang đồ vật thứ i, MaxV(i-1,L).
//• Nghĩa là
//MaxV(i, L) = Max{MaxV(i-1,L-w[i])+c[i], MaxV(i-1,L)}

void QHD_CaiTui()
{
    for(int L=0;L<=b;L++)    MaxV[0][L]=0;
    for(int i=0;i<=n;i++)    MaxV[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int L=1;L<=b;L++){
            MaxV[i][L]=MaxV[i-1][L];
            if ((L >= w[i-1]) && (MaxV[i-1][L-w[i-1]]+c[i-1] >MaxV[i-1][L])){
                MaxV[i][L]=MaxV[i-1][L-w[i-1]]+c[i-1];
            }
        }
    }
    ///Xuat Kq
    for(int i=0;i<=n;i++){
        for(int L=0;L<=b;L++){
            cout<<MaxV[i][L]<<"  ";
        }
        cout<<endl;
    }

    ///Tim vat dk chon: tai cot cuoi: tim hang co gia tri lon nhat, chi so nho nhat: chon vat tuong ung hang do
    /// cot moi= cot cu tru trong luong vat vua chon, tiep tuc tim nhu vay
    int chon[10],k=0,L=b,i=n,s=0;///L la Cot hien tai, i la hang hien tai la vat thu bn luon, s tong trong luong
    while(MaxV[i][L]-w[i-1]>0){
        if(MaxV[i][L]==MaxV[i-1][L]) i--;
        else if(MaxV[i][L]==MaxV[i][L-1])   L--;
        else{
            chon[k]=i;
            k++;
            L=L-w[i-1];
            s+=w[i-1];
            i--;///da chon vat thu i roi nen phai --
        }

    }
    cout<<endl<<"cac vat dk chon: ";
    for(int j=0;j<k;j++){
        cout<<"  "<<chon[j];
    }
    cout<<endl<<"Co tong trong luong la: "<<s<<" Tong Gia tri: "<<MaxV[n][b];
}

///Bai  2: Day Con co tong lon nhat
int n2=9;
int A2[9]={13,-15,2,18,4,8,0,-5,-8};
int MaxS;///gia tri max cuoi :  MaxS[i] = max{MaxS[i-1], MaxE[i]}
int MaxE;///gia tri max tam thoi:  MaxE[i] = max {a[i], MaxE[i-1]+a[i]}, i>1

void QHD_subMax()
{
    MaxS=A2[0]; MaxE= A2[0];
    int s=0, e=0, s1=0;///s: chi so dau, e: chi so cuoi, s1: chi so dau tam thoi
    for(int i=1;i<n2;i++){
        if(MaxE>0)  MaxE+= A2[i];
        else{
            MaxE=A2[i]; s1=i;///MaxE da nho hon 0, ta tim thu day moi xem
        }
        if(MaxE>MaxS){
            MaxS=MaxE;
            e=i;
            s=s1;
        }
    }

    ///xuat ket qua:
    cout<<"Day con lien tiep co tong lon nhat la: ";
    for(int i=s;i<=e;i++)
        cout<<A2[i]<<"  ";
}


int main()
{
    //QHD_CaiTui();
    QHD_subMax();

    return 0;
}
