#include<stdio.h>
#include<stdlib.h>

int main () {

    float X1,X2,Y1,Y2,X,Y,a,b,D;
    
    printf("\nEntrez les coordonnees des deux extremites d'un segment X1,Y1,X2 et Y2: ");
    scanf("%f %f %f %f",&X1,&Y1,&X2,&Y2);

    //Equation d'une droite : Y= aX+b;
    a = (Y2-Y1)/(X2-X1);
    b = Y1-(a*X1);

    printf("\nEntrez les coordonnees d'un point dans le plan X et Y: ");
    scanf("%f %f",&X,&Y);
    D = (Y-(a*X)-b);
    if (D == 0) printf("\nLe point se trouve sur le segment");
    else printf("\nLe point ne se trouve pas sur le segment");
    
    return 0;
}