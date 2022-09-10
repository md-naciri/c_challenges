#include<stdio.h>
#include<stdlib.h>

int main () {

char a;

printf("\nEntrer un caractere: ");
scanf("%c",&a);

if(a>=65 && a<= 90) printf("\n%c est un alphabet majuscule", a);
else if (a>='a' && a<='z') printf("\n%c est un alphabet minuscule", a);
else printf("\n%c n est pas un alphabet", a);

return 0;
}