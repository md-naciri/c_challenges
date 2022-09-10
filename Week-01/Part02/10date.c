#include<stdio.h>
#include<stdlib.h>

int main () {

int dd,mm,yy;

printf("\nEnter a date in the format dd/mm/yy: ");
scanf("%d/%d/%d",&dd,&mm,&yy);

switch (mm)
{
case 1: printf("\n%d-January-%d",dd,yy);
    break;
case 2: printf("\n%d-February-%d",dd,yy);
    break;
case 3: printf("\n%d-March-%d",dd,yy);
    break;
case 4: printf("\n%d-April-%d",dd,yy);
    break;
case 5: printf("\n%d-May-%d",dd,yy);
    break;
case 6: printf("\n%d-June-%d",dd,yy);
    break;
case 7: printf("\n%d-July-%d",dd,yy);
    break;
case 8: printf("\n%d-August-%d",dd,yy);
    break;
case 9: printf("\n%d-September-%d",dd,yy);
    break;
case 10: printf("\n%d-October-%d",dd,yy);
    break;
case 11: printf("\n%d-November-%d",dd,yy);
    break;
case 12: printf("\n%d-December-%d",dd,yy);
    break;
        

default: printf("\nEnter a correct date");
    break;
}

return 0;
}