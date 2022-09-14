#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPremier(int n){
    int i,m;
    m=0;
    for (i=2;i<n;i++){
        m=n%i;
        if (m==0) return false;
    }
    return true; 
}

int main () {
    int a;
    printf("\nEntrer un entier: ");
    scanf("%d",&a);
    if (isPremier(a)) printf("%d est un nombre premier",a);
    else printf("%d n est pas un nombre premier",a);
    return 0;
}