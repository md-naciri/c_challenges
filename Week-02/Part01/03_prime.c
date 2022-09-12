#include<stdio.h>
#include<stdlib.h>


int main () {

    int n,i,m;

    printf("\nEntrer un entier: ");
    scanf("%d",&n);
    m=0;
    for (i=2;i<n;i++){

        m=n%i;
        if (m==0){
            printf ("%d n est pas un nombre premier",n);
            break;
        } 

    }

    if (m!=0) printf ("%d est un nombre premier",n);

    return 0;

}