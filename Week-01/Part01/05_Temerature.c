#include<stdio.h>
#include<stdlib.h>

int main () {
    float f,c;
    printf("\nEnter the temperature in F:  ");
    scanf("%f",&f);
    c = (f-32)/1.8;
    if (c <= 5) {
    printf("Very cold\n");
    }
    else if (c > 5 && c <= 20) {
    printf("Cold\n");
    }
    else if (c > 20 && c <= 32) {
    printf("Hot\n");
    }
    else  {
    printf("Very Hot\n");
    }
    return 0;
}