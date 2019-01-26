#include <iostream>

using namespace std;

///Bt 8 con hau: xep lan luot 8 con hau vao 8 hang lien tiep
int x[10];///x[i]: con hau o hang i xep tai cot x[i]
bool a[10];///a[i] xet cot thu i co dk dat hay ko
bool b[20];///b[i+j] xet duong cheo phu cua o hang i cot j co dk dat hay ko
bool c[10];///c[i-j] xet duong cheo chinh ..................................
int lan=0;
void Kt_Hau(){///khoi tao hau
    for(int i=1;i<=8;i++){
        a[i]=true;
        for(int j=1;j<=8;j++){
            b[i+j]=true;
            c[i-j]=true;
        }
    }
}
void Xuat_Hau()
{
    cout<<endl<<"Ket qua lan thu : "<<lan<<endl;
    for(int i=1;i<=8;i++){
        cout<<"Hau thu "<<i<<"xep hang thu "<<i<<"cot thu "<<x[i]<<endl;
    }
}
void Try_Hau(int i)///xep hau tai hang thu i
{
    for(int j=1;j<=8;j++){
        if(a[j]&& b[i+j] &&c[i-j]){///dk 1
            x[i]=j;
            a[j]=b[i+j]=c[i-j]=false;
            if(i<8)     Try_Hau(i+1);///de i<8 ma ko phai i<=8 vi neu de vay i=> 9: khong thoa man dk1 => ket thuc
            else    {
                lan++;
                Xuat_Hau();
            }
            a[j]=b[i+j]=c[i-j]=true;///chon dap an khac nen quay lai trang thai truoc do
           // cout<<"Cmcm "<<i+1<<"  ";
        }
    }
}

///BAI toan Ngua di Tuan
int h[8][8];///h[x][y]: o vi tri x,y:  h[x][y]=0: chua co ngua di qua, h[x][y]=k da di qua o buoc thu k
///chi can lap day mang h khac 0 la hoan thanh 1 phuong an
int a2[8]={1,2,2,1,-1,-2,-2,-1};///tang x them a[i] thi co la nuoc di hop le tuong ung voi tang y them b[i]
int b2[8]={2,1,-1,-2,-2,-1,1,2};
void Kt_Ma()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            h[i][j]=0;
        }
    }
}
void Xuat_Ma(){
    cout<<endl<<"Dap an Ma di tuan thu "<<lan<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<h[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void Try_Ma(int i,int x,int y)
{
    //cout<<" "<<i;
    for(int k=0;k<8;k++){
        int u=x+a2[k];
        int v=y+b2[k];
        if(u>=0 && v>=0 && u<8 && v<8 && h[u][v]==0){
            h[u][v]=i;
            if(i<64)    Try_Ma(i+1,u,v);
            else{
                lan++;
                Xuat_Ma();
                //cout<<"c ";
            }
            h[u][v]=0;

        }
        //h[u][v]=0;
    }
}

///Bai toan 3: suduku:
///s[x][y]=0 vi tri x,y chua dk xu ly, 1...9 la da dk dien
int S[9][9]={{0,0,0,5,0,0,0,0,7},{0,0,0,0,0,3,5,0,9},{7,0,2,0,9,0,4,0,8},{0,0,0,0,0,7,2,0,0},{3,0,0,2,0,6,0,0,5},
        {0,0,7,8,0,0,0,0,0},{1,0,5,0,7,0,8,0,3},{2,0,8,3,0,0,0,0,0},{4,0,0,0,0,9,0,0,0}};
//Ứng viên k được đặt vào ô (x i ,y i ) nếu
//– Trên hàng x i chưa có giá trị k
//– Trên cột y j chưa có giá trị k
//– Vùng 3x3 chứa (x i ,y i ) chưa có giá trị k

void Xuat_Suduku(){
    cout<<endl<<"dap an suduku lan thu "<<lan<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<S[i][j]<<"  ";
        }
        cout<<endl;
    }
}
bool Feasible(int x,int y,int k)///gia tri k dat o vi tri x,y co hop le ko
{
    for(int i=0;i<9;i++){
        if(S[i][y]==k)  return false;
        if(S[x][i]==k)  return false;
    }
    int a=x/3, b=y/3;
    for(int i=3*a;i<3*a+3;i++){
        for(int j=3*b;j<3*b+3;j++)
            if(S[i][j]==k)  return false;
    }
    return true;
}
void Suduku(int x,int y){
    if(y==9){
        if(x==8){
            lan++;
            Xuat_Suduku();
        }
        else{
            Suduku(x+1,0);
        }
    }
    else if(S[x][y]==0){
        for(int k=1;k<10;k++){
            if(Feasible(x,y,k)){
                S[x][y]=k;
                Suduku(x,y+1);
                S[x][y]=0;///cho lan quay lai tiep
            }
        }
    }
    else    Suduku(x,y+1);
}


int main()
{
//    Kt_Hau();
//    Try_Hau(1);
//    Kt_Ma();
//    h[0][0]=1;///chon vi tri (0,0) la vi tri xuat phat
//    Try_Ma(2,0,0);

    Suduku(0,0);
    return 0;
}
