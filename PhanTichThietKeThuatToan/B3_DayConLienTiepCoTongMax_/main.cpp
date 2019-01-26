#include <iostream>
#include <algorithm>

using namespace std;

//cho mang a, tim day con lien tiep trong mang co tong lon nhat
int maxLeft(int a[],int l,int m,int &beginM)
{
    int maxSum= -10000;
    int sum=0;
    for(int k=m;k>=l;k--){
        sum+=a[k];
        if(sum>maxSum)  {
            maxSum=sum;
            beginM=k;
            }
    }
    return maxSum;
}

int maxRight(int a[],int m, int r, int &endM)
{
    int maxSum= -10000;
    int sum=0;
    for(int k=m;k<=r;k++){
        sum+=a[k];
        if(sum>maxSum)  {
            maxSum=sum;
            endM=k;
            }
    }
    return maxSum;
}

int MaxSub(int a[],int i, int j,int &Begin,int &End)
{
    if(i==j)    return a[j];
    int m= (i+j)/2;
    int beginL,endL,beginR,endR,beginM,endM;
    int wL= MaxSub(a,i,m,beginL,endL);
    int wR= MaxSub(a,m+1,j,beginR,endR);
    int wM= maxLeft(a,i,m,beginM)+ maxRight(a,m+1,j,endM);

    int Max= max(max(wL,wR),wM);
    if(wL==Max){
        Begin=beginL;   End=endL;
    }
    if(wR==Max){
        Begin=beginR;   End=endR;
    }
    if(wM==Max){
        Begin=beginM;   End=endM;
    }
    return Max;
}

int main()
{
    int a[]={-98,54,67,65,-897,78,65,32,-6,67};
    int b,e;
    int m=MaxSub(a,0,9,b,e);
    cout<<"daycon lien tiep co tong lon nhat la: "<<endl;
    for(int i=b;i<=e;i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl<<"co tong la: "<<m;
    cout << "Hello world!" << endl;
    return 0;
}
