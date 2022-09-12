#include<stdio.h>
#include<stdlib.h>

int main () {

    int L,i,j;
    printf("\nEntrez le nombre des lignes: ");
    scanf("%d",&L);

    for (i=1; i<=L; i++) {
        for (j = 1; j <= (2*L)-1; j++)
        {
            if (j>=L-(i-1) && j<=L+(i-1))
                printf("*");
            else 
                printf (" ");
        }
        printf("\n");
    }
    return 0;
}