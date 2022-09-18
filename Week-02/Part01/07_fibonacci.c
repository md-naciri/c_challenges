#include<stdio.h>
#include<stdlib.h>

int main () {
    int U0, U1, S, n, i;
    printf("Entrer un nombre: ");
    scanf("%d",&n);
    U0=1;
    U1=1;
    if ((n == 0) || (n == 1)) printf ("le 1 eme terme de la suite de Fibonacci est 1");
    else
    {
        for (i = 2; i <= n; i++)
        {
        S=U0+U1;
        U0=U1;
        U1=S;
        //   printf("%d ", S);
        }
    printf("\nle %deme terme de la suite de Fibonacci est %d",n,S);
    }

    return 0;
}