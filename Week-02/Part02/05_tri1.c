#include<stdio.h>
#include<stdlib>

void main(){
    int list1[] = {9, 10, 11};
    int list2[] = {0, 10, 25};
    int list3[6];
    int a = 0, b = 0;

    for(int i = 0; i <= 10; i++){
        if(list1[a] < list2[b]){
            if(a == 3){
                list3[i] = list2[b];
            }else{
                list3[i] = list1[a];
                ++a;
            }
        }else{
            if(b == 3){
                list3[i] = list1[a];
            }else{
                list3[i] = list2[b];
                ++b;

            }
        }
    }

    for(int j = 0; j < 6; j++){
        printf("%d \n", list3[j]);
    }
}