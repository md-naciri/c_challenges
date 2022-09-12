#include<stdio.h>
#include<stdlib.h>
int main()
{
    int sum,M,n;
    sum=0;
    M=0;
    n=1;
    printf("Entrez une serie d'entier inferieur a 100\n");
    while(n!=0)
    {
       do{
            scanf("%d",&n);
            if(n>100) printf("Entrez un entier inferieur a 100\n");
       }while(n>=100);
       sum+=n;
       if(n>M) M=n;
    }
    printf("la somme: %d\n",sum);
    printf("le max: %d\n",M);
    
    return 0; 
}