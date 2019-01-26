#include <iostream>

using namespace std;

///Bai toan xau con chung dai nhat  => CACH THUC RAT GIONG BAI TOAN CAI TUI
char x[10]="khoa hco";
char y[10]="hoa hong";
int m=8,n=8;
int C[9][9];///c[i][j] luu lai xau chung dai nhat giua 2 day x(do dai la i) va y(do dai la j)
///cach lam
//– Nếu x i = y j thì dãy con chung dài nhất của X i và Y j
//sẽ thu được bằng việc bổ sung x i (cũng là y j ) vào
//dãy con chung dài nhất của hai dãy X i-1 và Y j-1
//C[i,j] = C[i-1,j-1]+1
//– Nếu x i ≠ y j thì dãy con chung dài nhất của X i và Y j
//sẽ là dãy con dài hơn trong hai dãy con chung dài
//nhất của (X i1 và Y j ) và của (X i và Y j1 )
//C[i,j] = Max{C[i-1,j], C[i,j-1]}

void QHD_XauChungMax()
{
    for(int i=0;i<=m;i++)    C[i][0]=0;
    for(int j=0;j<=n;j++)    C[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                C[i][j]=C[i-1][j-1]+1;
            }
            else{
                C[i][j]=max(C[i-1][j],C[i][j-1]);
            }
        }
    }

    ///xuat ra cai bang vua moi thu dk
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<C[i][j]<<"  ";
        cout<<endl;
    }
    ///xuat ra chuoi thu dk
    char chon[10],k=0,j=n,i=m;
    while(C[i][j]>0){
        if(C[i][j]==C[i-1][j]) i--;
        else if(C[i][j]==C[i][j-1])   j--;
        else{
            chon[k]=x[i-1];
            k++;
            j--;
            i--;///da chon vat thu i roi nen phai --
        }
    }
    cout<<endl<<"Xau chung la : ";
    for(int j=k-1;j>=0;j--){
        cout<<chon[j];
    }
}


///Bai 2 Thuat toan tim duong di ngan nhat TT Floyd
int n2=4;//so dinh do thi
int a[4][4]={{0,5,10000,10000},{50,0,15,5},{30,10000,0,15},{15,10000,5,0}};//do thi ban dau
int d[4][4];///d[i][j] duong di ngan nhat tu dinh i->j
int p[4][4];///p[i][j] duong di ngan nhat tu i->j co di qua dinh p[i][j]
///Cach lam
//Nếu d[i,j] là đường đi ngắn nhất từ i đến j đã
//xét ở bước k-1 (đã xét đi qua từ đỉnh 1 đến
//đỉnh k-1).
//• Ở bước k:
//d[i,j] = min (d[i,j], d[i,k]+d[k,j])

void DD_Floyd()
{
    ///khoi tao
    for(int i=0;i<n2;i++)
        for(int j=0;j<n2;j++){
            d[i][j]=a[i][j];
            p[i][j]=0;
        }
    ///bat dau :
    for(int k=0;k<n2;k++){///tai buoc k:
        for(int i=0;i<n2;i++){
            if(d[i][k]>0 && d[i][k]<10000){///neu co duong di tu i->k:  i khac k
                for(int j=0;j<n2;j++){
                    if(d[k][j]>0 && d[k][j]<10000){///va neu co duong di tu k->j....
                        if(d[i][k]+d[k][j]< d[i][j]){///va neu duong di nay nho hon duong di nn o buoc k-1
                            d[i][j]=d[i][k]+d[k][j];
                            p[i][j]=k;///duong di ngan nhat nay se di qua k
                        }
                    }
                }
            }
        }
    }

    ///Xuat ra bang ket qua cuoi cung:
    cout<<"Bang duong di ngan nhat: "<<endl;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n2;j++){
            cout<<d[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Bang duong di ngan nhat co di qua nhung dinh nay: "<<endl;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n2;j++){
            cout<<p[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    //DD_Floyd();
    QHD_XauChungMax();
    return 0;
}
