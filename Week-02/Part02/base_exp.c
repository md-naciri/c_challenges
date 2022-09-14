#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main () {
    int n,i,j;
    printf("Entrer un nombre: ");
    scanf("%d",&n);

    for (i=2; i<=sqrt(n); i++)
    {
        j=1;
        while (pow(i,j)<=n){
            if (pow(i,j)==n) printf("\nB=%d et E=%d)",i,j);
            j++;
        }
        i++;
    }

    return 0;
}