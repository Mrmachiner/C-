#include<iostream> 

int max(int a, int b) 
{ return (a > b)? a : b; } 
int knapSack(int W, int wt[], int val[], int n) 
{ 

   if (n == 0 || W == 0) 
       return 0; 
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
                    knapSack(W, wt, val, n-1) 
                  ); 
} 
int main() 
{ 
//    int val[] = {7, 10, 20,19,13,40}; 
//    int wt[] = {3, 4, 5,7,6,9}; 
	int wt[]={12,2,1,1,4,6,1,3,9,7};
	int val[]={4,2,1,2,10,15,3,15,2,6};
    int  W = 25; 
    int n =10; //sizeof(val)/sizeof(val[0]); 
    std :: cout<<knapSack(W, wt, val, n); 
    return 0; 
} 
