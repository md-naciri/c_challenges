#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
int num,o,i,s;
printf("\nEnter a number: ");
scanf("%d",&num);
if(num < 8) printf("\nThe octal value of this number is: %d",num);
else{
    i=0;
    s=0;
    while(num>=8){
        o=num%8;
        s+=o*pow(10,i);
        i++;
        num=num/8;
    }
    s+=num*pow(10,i);
    printf("\nThe octal value of this number is: %d",s);
}
return 0;
}