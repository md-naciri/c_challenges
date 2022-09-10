#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float moy;
    
    printf("\nEntrer ta moyenne: ");
    scanf("%f",&moy);
    
    if (moy>20) printf("Entrer un moyenne <= 20\n");
    else if (moy>=16) printf("tres bien\n");
    else if (moy>=14) printf("bien\n");
    else if (moy>=12) printf("assez bien\n");
    else if (moy>=10) printf("passable\n");
    else printf("recale\n");

    return 0;
}