#include<stdio.h>
#include<stdlib.h>

int main () {
    float a,b,c,d,S,M;
    printf("\nEnter the four numbers:  ");
    scanf("%f %f %f %f",&a,&b,&c,&d);
    S=a+b+c+d;
    M=S/4;
    printf("\nSum = %.2f    Average = %.2f",S,M);

    return 0;
}