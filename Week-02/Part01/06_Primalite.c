#include<stdio.h>
#include<stdlib.h>

int main () {

    int n,p,i,m1,m2;

    printf("\nEntrer un nombre: ");
    scanf("%d",&n);

    for (p=2;p<=n;p++){
        m2=1;
        for (i=2;i<p;i++){
            m1=p%i;
            if (m1==0) {m2 = 0; break;}
        }
        if (m1!=0) printf("%d  ",p);
    }

    return 0;

}