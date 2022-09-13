#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main () {

    float a, b, m;
    a = -15;
    b = -10;
    while ((b-a)>0.00001)
    {
        m=(b+a)/2;
        if ((pow(a,3)+(12*pow(a,2))+1)*(pow(b,3)+(12*pow(b,2))+1)<0) b = m;
        else a = m;
        
    }
    printf("\nLa solution est: %.2f", m);
    
    return 0;
}