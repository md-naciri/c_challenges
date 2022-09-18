#include<stdio.h>
#include<stdlib.h>

int main () {
    int e,i,a;
    long long int X;
    printf("Entrer la base et l'exposant: "); 
    scanf("%d %d",&X, &e);
    i=1;
    a=X;
    while (i<e)
        {
            X=X*a;
            i++;
        }
    printf("\n%lld",X);
    return 0;
}