#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    float a,b,c,D;
    printf("\nAx^2+Bx+C=0   Enter the coefficients A, B and C\n");
    scanf("%f %f %f\n",&a, &b, &c);
    D = pow(b,2)-4*a*c;
    if (D<0) printf("The solution is the Empty Set");
    else if (D==0) printf("The solution is x = %.2f\n",-b/2*a);
    else printf("The solution is x1 = %.2f et x2 = %.2f\n",(-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a));
    return 0;
}