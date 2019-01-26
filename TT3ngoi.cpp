#include<stdio.h>

#include<conio.h>

int main(){

     int a = 10, b = 5, c = 10;

     printf("Minh h?a phép toán tang gi?m");


     printf("\n 1: a=%d b=%d c=%d ", a, b, c);

     c =( a >= b ? a++ : b++);

     printf("\n 3: a=%d b=%d c=%d", a, b, c);

     c = a > b ? a++ : b++;

     printf("\n 4: a=%d b=%d c=%d", a, b, c);

    return 0;

}
