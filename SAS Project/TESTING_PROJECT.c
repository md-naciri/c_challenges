#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include <ctype.h>


int main () {
char CH;
// scanf("%c",)
printf("begin:\n");
do{
    // printf("\033[0;33m"); //Yellow Color
  	
  	scanf("%s",&CH);
	printf("typed number: %c\n", CH);
}while(CH != 'b');
printf("END:\n");

return 0;


}
 
 
 
time_t t = time(NULL);
ctime(&t);