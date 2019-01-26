#include <iostream>
#include <math.h>

using namespace std;

//MergeSort sap xep tang dan
void Merge(int a[10],int l,int t,int r)
{
    int i=l;
    int j=t+1;
    int p=l;
    int c[10];

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
        j++;  p++;
    }
    for(int k=l;k<=r;k++)
        a[k]=c[k];
}

void MergeSort(int a[10],int left, int right)
{
    if(left>=right) return;//o day phai co dau= vi t=(left+right)/2: khi left=right -> t=left=right -> lap vo tan
    int t=(left+right)/2;
    MergeSort(a,left,t);
    MergeSort(a,t+1,right);
    Merge(a,left,t,right);
}

void Xuat(int a[10],int l,int r){
    for(int i=l;i<=r;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}


//QuickSort sap xep tang dan

void Swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}

int Partition(int a[10],int l,int r)
{
    int x=a[l];
    int i=l+1;
    int j=r;
    while(i<j)//neu i=j se lap vo tan vi vong while thu 2 ben duoi j giu nguyen
    {
        while(i<j && a[i]<x)    i++;//tim vi tri ma a[i]>x, th ko co nhay den vi tri i=j
        while(j>=i && a[j]>=x)    j--;//tim vi tri ma a[j]<x, th i=j ma a[j] van >x -> j-- -> a[j]<x

        if(i<j) Swap(a[i],a[j]);//doi cho 2 vi tri nay cho nhau
    }
    //xong roi doi cho cho x ve dung vi tri khi sap xep
    if(a[l]>a[j])//vi sao: th chi co 2 pt : a[l]=1, i=j=2, while ko chay
    Swap(a[l],a[j]);

    return j;
}



void QuickSort(int a[10],int l,int r)
{
    if(l>=r)     return;
    int i= Partition(a,l,r);
    QuickSort(a,l,i-1);
    QuickSort(a,i+1,r);
}


int main()
{
    int a[10]= {3,2,1,5,8,5,9,7};
    Xuat(a,0,7);
    //MergeSort(a,0,7);//xong roi
    QuickSort(a,0,7);
    //int i=Partition(a,5,6);
    //cout<<a[i];

    Xuat(a,0,7);
    //cout << "Hello kdkdkkdkdkdk!" << endl;
    return 0;
}
