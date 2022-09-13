#include<stdio.h>
#include<stdlib.h>

int main () {
    int b,e,i,p,a;
    printf("Entrer la base et l'exposant: "); 
    scanf("%d %d",&b, &e);
    i=1;
    a=b;
    while (i<e)
        {
            p=b*a;
            i++;
            b=p;
        }
    printf("\n%d",p);
    return 0;
}