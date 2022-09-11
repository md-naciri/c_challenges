#include<stdio.h>
#include<stdlib.h>

int main () {

    float ag,ma;
    int i;

    ma = 1000000;
    ag = 500000;
    i=0;
    
    while (ag<ma)
    {
        ma+=50000;
        ag+=(ag*0.8);
        i++;
    }
    printf("\nLa population de Agadir depassera celle de Marrakech dans %d annees\n",i);
    
return 0;
}