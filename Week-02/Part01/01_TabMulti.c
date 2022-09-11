#include<stdio.h>
#include<stdlib.h>

int main () {

    int i,n;
    printf("\nEntrez un nombre: ");
    scanf("%d",&n);
    
    for (i = 1; i <= 10; i++)
    {
        printf("\n%d x %d = %d",n,i,n*i);
    }
    
    return 0;
}