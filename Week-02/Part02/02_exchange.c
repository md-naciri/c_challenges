#include<stdio.h>
#include<stdlib.h>

/*void Exchange(int a, int b) {
    int c;
    printf("Before exchange :\na= %d    b=%d ",a,b);
    c=a;
    a=b;
    b=c;
    printf("\nAfter exchange :\na= %d    b=%d ",a,b);
}*/

//  void exchange() {
//         int a,b,c;
//         printf("Before exchange :\na= %d    b=%d ",a,b);
//         c=a;
//         a=b;
//         b=c;
//         printf("\nAfter exchange :\na= %d    b=%d ",a,b);

//     }

int main () {
    int a,b;
    void exchange() {
        int c;
        printf("Before exchange :\na= %d    b=%d ",a,b);
        c=a;
        a=b;
        b=c;
        printf("\nAfter exchange :\na= %d    b=%d ",a,b);
    }
    printf("Enter deux nombres: \n");
    scanf("%d %d",&a,&b);
    exchange();
    exchange();
    printf("\n%d",a);
    return 0;
}