#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main () {
    
    float x1,y1,x2,y2,D;
    printf("\nEntre les coordonnees du premier point:  ");
    scanf("%f %f",&x1,&y1);
    printf("\nEntre les coordonnees du 2eme point:  ");
    scanf("%f %f",&x2,&y2);
    D = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    printf("\nLa distance est: %.2f",D);

    return 0;
}