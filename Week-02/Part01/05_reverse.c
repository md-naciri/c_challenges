#include<stdio.h>
#include<stdlib.h>

int main () {

    int m,inv,n;

    printf("\nEntrer un entier: ");
    scanf("%d",&n);

    while (n!=0){

        m=n%10;
        inv=(inv+m)*10;
        n/=10;

    }

    printf("\nL'entier inverse est: %d",inv/10);

    return 0;

}