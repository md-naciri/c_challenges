#include<stdio.h>
#include<stdlib.h>

int main () {
    float m,M;
    printf("Enter the distance in mile:  ");
    scanf("%f",&M);
    m= M*1609;
    printf("\nThe distance in meter is: %.2f",m);
    return 0;
}