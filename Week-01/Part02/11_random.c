#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main () {

int r;
srand(time(NULL));
r= rand()%7; ;

switch (r)
{
case 0: printf("\nMonday");
    break;
case 1: printf("\nTuesday");
    break;
case 2: printf("\nWednesday");
    break;
case 3: printf("\nThursday");
    break;
case 4: printf("\nFriday");
    break;
case 5: printf("\nSaturday");
    break;
case 6: printf("\nSunday");
    break;
}

return 0;
}