#include<stdio.h>
#include<stdlib.h>

int main () {
    int X,e,i,a;
    printf("Entrer la base et l'exposant: "); 
    scanf("%d %d",&X, &e);
    i=1;
    a=X;
    while (i<e)
        {
            X=X*a;
            i++;
        }
    printf("\n%d",X);
    return 0;
}