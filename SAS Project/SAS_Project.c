#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<conio.h>



/* CHANGING COLOR:
To change the color, we can use this method:
Let us take the red color as an exmaple, we write this code in the printf  \033[0;31m  :  printf("\033[0;31m");
Here are some other color codes:
Black \033[0;30m
Red \033[0;31m
Green \033[0;32m
Yellow \033[0;33m
Blue \033[0;34m
Purple \033[0;35m
Cyan \033[0;36m
White \033[0;37m
*/



//The product Structure
typedef struct ProductID
{
    char code[20];
    char name[20];
    int quantity;
    float price;
}Product;
Product pro[200];
int i=0;
int j;



//Adding a new product Function:
void Add(){
    int B;
    char codeCompare[20];
    int op; //op for option.
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------|| Adding a new product ||-----------------------||\n\n");
    sleep(1);
    NO1:
    printf("\n\tPlease Enter your product code:\t");
    scanf("%s",codeCompare);

    for (j=0;j<i;j++){
        if (strcmp(pro[j].name,codeCompare)==0){
            NO2:
            printf("\n\tThis product already exists, you can add more quantity of this product by typing 1, \nor 0 to add another new product :\t");
            scanf("%d",&op);
            if (op==1) Replenish();
            else if (op==0) goto NO1;
            else goto NO2;
        }
    }
    strcpy(pro[i].code,codeCompare);
  	printf("\tPlease Enter your product name:\t");
  	scanf("%s",pro[i].name);
  	printf("\tEnter the quantity please:\t");
  	scanf("%d",&pro[i].quantity);
  	printf("\tPlease Enter the price:\t");
  	scanf("%f",&pro[i].price);
    NO:
    printf("\tEnter a 0 to return to the main menu\t\t");
    scanf("%d",&B);
    i++;
    if (B == 0){
        system("cls");
        printf("\033[0;37m"); //White color
        main();
    }
    else goto NO;
    // while(CH != 'B'){
    //  printf("\033[0;33m"); //Yellow Color
  	// 	printf("\tPlease enter a capital B to return to the main menu:\t");
  	// 	scanf("%c",&CH);
	//   }
    
    
}



//Adding several products Function:
void AddSev(){
    int n;
    int count =1;
    int B; //B for back
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Adding several products ||-----------------------------||\n\n");
    sleep(1);
    printf("\n\tHow many products you want to add:\t");
  	scanf("%d",&n);
    n=n+i;
    for(i; i<n; i++){
    printf("\n\tPlease Enter your product N%d code:\t",count);
  	scanf("%s",pro[i].code);
  	printf("\tPlease Enter your product N%d name:\t",count);
  	scanf("%s",pro[i].name);
  	printf("\tEnter the quantity please:\t");
  	scanf("%d",&pro[i].quantity);
  	printf("\tPlease Enter the price:\t");
  	scanf("%f",&pro[i].price);
    printf("\n");
    count++;
    }
    NO:
    printf("\tEnter a 0 to return to the main menu\t\t");
    scanf("%d",&B);
    if (B == 0){
        system("cls");
        printf("\033[0;37m"); //White color
        main();
    }
    else goto NO;
}



//Listing products Function:
void List(){
    int op; //op for option.
    int B; //B for back
    int k; //We need it for the sort
    struct ProductID temp;
    
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Listing products ||-----------------------------||\n\n");
    sleep(1);
    NO1:
    usleep(30000);
  	printf("\n\t-> list the products by the name in ascending alphabetical        .1.");
    usleep(30000);
    printf("\n\t-> list the products by the price in descending order             .2.\n");
    usleep(30000);
    printf("\n\t\t-> Choose an option:\t\t");
    scanf("%d",&op);
    printf("\n\n");
    for (j=0;j<i;j++){
        printf("Name: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f\n",pro[j].name,pro[j].price,pro[j].price*1.15);
    }
    switch (op)
    {
    case 1:
        for (j=0;j<i-1;j++){
            for(k=j+1;k<i;k++){
                if(strcmp(pro[j].name,pro[k].name)>0){
                    temp=pro[j];
                    pro[j]=pro[k];
                    pro[k]=temp;
                }
            }
        }
        printf("\n\n");
        for (j=0;j<i;j++){
        printf("Name: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f\n",pro[j].name,pro[j].price,pro[j].price*1.15);
        }
        break;
    case 2:
        for (j=0;j<i-1;j++){
            for(k=j+1;k<i;k++){
                if(pro[j].price < pro[k].price){
                    temp=pro[j];
                    pro[j]=pro[k];
                    pro[k]=temp;
                }
            }
        }
        printf("\n\n");
        for (j=0;j<i;j++){
        printf("Name: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f\n",pro[j].name,pro[j].price,pro[j].price*1.15);
        }
        break;
    default: goto NO1;
        break;
    }
    NO2:
    printf("\n\n\tEnter a 0 to return to the main menu:\t\t");
    scanf("%d",&B);
    i++;
    if (B == 0){
        system("cls");
        printf("\033[0;37m"); //White color
        main();
    }
    else goto NO2;
}



//Buy a product Function:
void Buy(){
int B; //B for back
char nameCompare[20];
int nb; //number of items to buy 

printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Buying a product ||-----------------------------||\n\n");
    NO:
    printf("\n\tEnter the name of the product you want to buy:\t");
  	scanf("%s",nameCompare);
    int c=0; //check if there is a product
    for (j=0;j<i;j++){
        if (strcmp(pro[j].name,nameCompare)==0){
            printf("\n\tEnter how many item you want to buy:\t");
            scanf("%d",&nb);
            printf("\n\tQuantity before buying: ");
            printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
            pro[j].quantity=pro[j].quantity-nb;
            c++;
            break;
        }
    }
    if (c==0) {
        printf("\n\tThere is no such product");
        goto NO;
    }
    printf("\n\n\tQuantity after buying: ");
    printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
    NO2:
    printf("\n\n\tEnter a 0 to return to the main menu:\t\t");
    scanf("%d",&B);
    i++;
    if (B == 0){
        system("cls");
        printf("\033[0;37m"); //White color
        main();
    }
    else goto NO2;
    
}



//Products search Function:
void Search(){

}



//Stock status Function:
void StockStatus(){

}



//Replenish stock Function:
void Replenish(){

}



//Delete products Function:
void Delete(){

}



//Sales statistics Function:
void Statistics(){

}



//The main function
int main () {
    int op; //op for option.
    printf("\n\t||-----------------------------|| Hello & Welcome ||-----------------------------||\n\n");
    sleep(1);
    printf("\n\t\t\t-> Add a new product                    .1.\n");
    usleep(30000);
    printf("\n\t\t\t-> Add several new products             .2.\n");
    usleep(30000);
    printf("\n\t\t\t-> List all products                    .3.\n");
    usleep(30000);
    printf("\n\t\t\t-> Buy a product                        .4.\n");
    usleep(30000);
    printf("\n\t\t\t-> Products search                      .5.\n");
    usleep(30000);
    printf("\n\t\t\t-> Stock status                         .6.\n");
    usleep(30000);
    printf("\n\t\t\t-> Replenish the stock                  .7.\n");
    usleep(30000);
    printf("\n\t\t\t-> Delete products                      .8.\n");
    usleep(30000);
    printf("\n\t\t\t-> Sales statistics                     .9.\n");
    usleep(30000);
    printf("\n\t\t\t-> Choose an option:\t\t");
    scanf("%d",&op);
    system("cls");
    switch (op)
    {
    case 1:
        Add();
        break;
    case 2:
        AddSev();
        break;
    case 3:
        List();
        break;
    case 4:
        Buy();
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    default:
        break;
    }
    system("cls");
    
    return 0;
}
