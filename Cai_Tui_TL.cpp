#include<iostream>
#include <algorithm>
  

struct Item 
{ 
    int value, weight; 
  
    // Constructor 
    //Item(int value, int weight) : value(value), weight(weight) {} 
}; 
//H�m so s�nh de sap xep theo giatri/khoiluong
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    //Ham Co san trong thu vien algorithm sap xep theo ty le tren
    std::sort(arr, arr + n, cmp); 
    int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
    return finalvalue; 
} 
int main() 
{ 
    int W = 50;   //   Trong Luong Balo
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    std::cout << "Gia Tri Max Ta Dat Duoc = "
         << fractionalKnapsack(W, arr, n); 
    return 0; 
} 
