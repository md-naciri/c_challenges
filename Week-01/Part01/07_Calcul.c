#include<stdio.h>
#include<stdlib.h>

int main () {
    int a,b;
    printf("\nEnter the two numbers:  ");
    scanf("%d %d",&a,&b);
    
    printf("\n%d + %d = %d",a,b,a+b);
    printf("\n%d - %d = %d",a,b,a-b);
    printf("\n%d * %d = %d",a,b,a*b);
    if (b != 0){
        printf("\n%d / %d = %d",a,b,a/b);
        printf("\n%d + %d = %d",a,b,a%b);
    }
    else{
        printf("\n%d / %d : Impossible",a,b);
        printf("\n%d mod %d : Impossible",a,b);
    }
    return 0;
}