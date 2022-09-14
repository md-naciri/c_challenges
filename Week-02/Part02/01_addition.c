#include<stdio.h>
#include<stdlib.h>

void add(int a, int b) {
    int c;
    printf("Before exchange :\na= %d    b=%d ",a,b);
    //c=a;
    //a=b;
    //b=c;
    printf("After exchange :\na= %d    b=%d ",b,a);
}

int main () {
    int a,b;
    printf("Enter deux nombres: \n");
    scanf("%d %d",&a,&b);
    
    return 0;
}