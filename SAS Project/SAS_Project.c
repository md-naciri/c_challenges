#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<conio.h>
#include <ctype.h>
#include<time.h>

void make_toupper(char s[])
{
  int length = strlen(s);
  for (int i=0;i<length;i++)
    {
      s[i]=toupper(s[i]);
    }
}

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

void Replenish();

//The product Structure
typedef struct ProductID
{
    char code[20];
    char name[20];
    int quantity;
    float price;
}Product;

typedef struct Save
{
    char name[20];
    char code[20];
    int quan;
    float UTTCprice;
    float TTTCprice;
    char date[50];
}Save;


Save S[200];
Product pro[200];
int i=0;
int s=0;
int j;



//Adding a new product Function:
void Add(){
    char B;
    char codeCompare[20];
    int op; //op for option.
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------|| Adding a new product ||-----------------------||\n\n");
    sleep(1);
    NO1:
    printf("\n\tPlease Enter your product code:\t");
    scanf("%s",codeCompare);
    make_toupper(codeCompare);



    for (j=0;j<i;j++){
        if (strcmp(pro[j].code,codeCompare)==0){
            NO2:
            printf("\n\tThis product already exists, you can add more quantity of this product by typing 1, \n\tor 0 to add another new product :\t");
            scanf("%d",&op);
            if (op==1) Replenish();
            else if (op==0) goto NO1;
            else goto NO2;
        }
    }
    strcpy(pro[i].code,codeCompare);

  	printf("\tPlease Enter your product name:\t");
  	scanf("%s",pro[i].name);
    make_toupper(pro[i].name);
  	printf("\tEnter the quantity please:\t");
  	scanf("%d",&pro[i].quantity);
  	printf("\tPlease Enter the price:\t");
  	scanf("%f",&pro[i].price);
    printf("\tEnter a capital B to return to the main menu\t\t");
    scanf("%s",&B);
    i++;
    while(B != 'B'){
        printf("\033[0;33m"); //Yellow Color
  		printf("\tPlease enter a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    system("cls");
    printf("\033[0;37m"); //White color
    main();
}



//Adding several products Function:
void AddSev(){
    int n;
    int count =1;
    char B; //B for back
    char codeCompare[20];
    int op; //op for option.
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Adding several products ||-----------------------------||\n\n");
    sleep(1);
    printf("\n\tHow many products you want to add:\t");
  	scanf("%d",&n);
    n=n+i;
    for(i; i<n; i++){
        
        NO1:
        printf("\n\tPlease Enter your product N%d code:\t",count);
  	    scanf("%s",codeCompare);
        make_toupper(codeCompare);
        

        for (j=0;j<i;j++){
            if (strcmp(pro[j].code,codeCompare)==0){
                NO2:
                printf("\n\tThis product already exists, you can add more quantity of this product by typing 1, \n\tor 0 to add another new product :\t");
                scanf("%d",&op);
                if (op==1) Replenish();
                else if (op==0) goto NO1;
                else goto NO2;
         }
        }
        strcpy(pro[i].code,codeCompare);
    

        printf("\tPlease Enter your product N%d name:\t",count);
        scanf("%s",pro[i].name);
        make_toupper(pro[i].name);
        printf("\tEnter the quantity please:\t");
        scanf("%d",&pro[i].quantity);
        printf("\tPlease Enter the price:\t");
        scanf("%f",&pro[i].price);
        printf("\n");
        count++;
    }
    printf("\tEnter a capital B to return to the main menu\t\t");
    scanf("%s",&B);
    while(B != 'B'){
        printf("\033[0;33m"); //Yellow Color
  	    printf("\tPlease enter a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    system("cls");
    printf("\033[0;37m"); //White color
    main();
}



//Listing products Function:
void List(){
    int op; //op for option.
    char B; //B for back
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
    printf("\tEnter a capital B to return to the main menu\t\t");
    scanf("%s",&B);
    while(B != 'B'){
        printf("\033[0;33m"); //Yellow Color
  	    printf("\tPlease enter a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    system("cls");
    printf("\033[0;37m"); //White color
    main();

}



//Buy a product Function:
void Buy(){
char B; //B for back
char nameCompare[20];
int nb; //number of items to buy 

    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Buying a product ||-----------------------------||\n\n");
    NO:
    printf("\n\tEnter the name of the product you want to buy:\t");
  	scanf("%s",nameCompare);
    make_toupper(nameCompare);
    int c=0; //check if there is a product
    for (j=0;j<i;j++){
        if (strcmp(pro[j].name,nameCompare)==0){
            printf("\n\tEnter how many item you want to buy:\t");
            scanf("%d",&nb);
            printf("\n\tQuantity before buying: ");
            printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
            pro[j].quantity=pro[j].quantity-nb;
            /*
            S[s].name=pro[j].name;
            S[s].code=pro[j].code;
            S[s].quan=nb;
            S[s].UTTCprice=pro[j].price*1.15;
            S[s].TTTCprice=pro[j].price*1.15*nb;
            time_t t = time(NULL);
            S[s].date=ctime(&t);
            s++;
            */
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
  
    printf("\tEnter a capital B to return to the main menu\t\t");
    scanf("%s",&B);
    while(B != 'B'){
        printf("\033[0;33m"); //Yellow Color
  	    printf("\tPlease enter a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    system("cls");
    printf("\033[0;37m"); //White color
    main();
    
}



//Products search Function:
void Search(){
    int op; //op for option.
    char codeCompare[20];
    char B; //B for back
    int q; //q for quantity
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Searching... ||-----------------------------||\n\n");
    sleep(1);
    NO1:
    int count=0;
    usleep(30000);
  	printf("\n\t-> Search for a product by its code                .1.");
    usleep(30000);
    printf("\n\t-> Search for a product by its quantity            .2.");
    usleep(30000);
    printf("\n\t-> list products whose quantity is less than 3     .3.\n");
    usleep(30000);
    printf("\n\t\t-> Choose an option:\t\t");
    scanf("%d",&op);
    printf("\n\n");
        switch (op)
        {
        case 1:
            printf("\n\tPlease enter your product code:\t");
  	        scanf("%s",codeCompare);
            make_toupper(codeCompare);
            for (j=0;j<i;j++){
                if (strcmp(pro[j].code,codeCompare)==0){
                    printf("Code: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                    break;
                }
            }
            if (count==0) {
                printf("\n\tThere is no such product");
                goto NO1;
            }
            else{
                printf("\tEnter a capital B to return to the main menu\t\t");
                scanf("%s",&B);
                while(B != 'B'){
                    printf("\033[0;33m"); //Yellow Color
  	                printf("\tPlease enter a capital B to return to the main menu:\t");
  		            scanf("%s",&B);
	            }
                    system("cls");
                    printf("\033[0;37m"); //White color
                    main();
            }
        break;

        case 2:
            printf("\n\tPlease enter the quantity:\t");
  	        scanf("%d",&q);
            for (j=0;j<i;j++){
                if (q==pro[j].quantity){
                    printf("Code: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                }
            }
            if (count==0) {
                printf("\n\tThere is no such product with this quantity");
                goto NO1;
            }
            else{
                printf("\tEnter a capital B to return to the main menu\t\t");
                scanf("%s",&B);
                while(B != 'B'){
                    printf("\033[0;33m"); //Yellow Color
  	                printf("\tPlease enter a capital B to return to the main menu:\t");
  		            scanf("%s",&B);
	            }
                    system("cls");
                    printf("\033[0;37m"); //White color
                    main();
            }
        break;

        case 3:
            for (j=0;j<i;j++){
                if (pro[j].quantity<3){
                    printf("Stock status:\n");
                    printf("Code: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                }
            }
            if (count==0) {
                printf("\n\tThere is no product with a quantity less than 3\n\n");
                goto NO1;
            }
            else{
                printf("\tEnter a capital B to return to the main menu\t\t");
                scanf("%s",&B);
                while(B != 'B'){
                    printf("\033[0;33m"); //Yellow Color
  	                printf("\tPlease enter a capital B to return to the main menu:\t");
  		            scanf("%s",&B);
	            }
                    system("cls");
                    printf("\033[0;37m"); //White color
                    main();
            }
        break;

        default: goto NO1;
        break;
        }

}



//Replenish stock Function:
void Replenish(){
    char B; //B for back
    char codeCompare[20];
    int q; //q for the quantity

    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Replenish/Supplying ||-----------------------------||\n\n");
    NO:
    printf("\n\tEnter the code of the product:\t");
  	scanf("%s",codeCompare);
    make_toupper(codeCompare);
    int c=0; //check if there is a product
    for (j=0;j<i;j++){
        if (strcmp(pro[j].code,codeCompare)==0){
            printf("\n\tEnter the quantity please:\t");
            scanf("%d",&q);
            printf("\n\tQuantity before supplying: ");
            printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
            pro[j].quantity=pro[j].quantity+q;
            c++;
            break;
        }
    }
    if (c==0) {
        printf("\n\tThere is no such product");
        goto NO;
    }
    printf("\n\n\tQuantity after suppling: ");
    printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
    printf("\tEnter a capital B to return to the main menu\t\t");
    scanf("%s",&B);
    while(B != 'B'){
        printf("\033[0;33m"); //Yellow Color
  	    printf("\tPlease enter a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    system("cls");
    printf("\033[0;37m"); //White color
    main();
    
}



//Delete products Function:
void Delete(){
    int c=0;
    int k;
    char codeCompare[20];
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------|| Delete a product ||-----------------------||\n\n");
    sleep(1);
    NO:
    printf("\n\tPlease Enter your product code:\t");
    scanf("%s",codeCompare);
    make_toupper(codeCompare);
    for (j=0;j<i;j++){
        if (strcmp(pro[j].code,codeCompare)==0){
           c++;
           break;
        }
    }
    if (c==0) {
        printf("\n\tThere is no such product");
        goto NO;
    }
    else{
        for (k=j;k<i;k++){
            pro[k]=pro[k+1];
        }
        i--;
    }
}



//Sales statistics Function:
void Statistics(){
    int TTTC=0;
    int m;
    for (j=0;j<i;j++){
        TTTC+=S[j].TTTCprice;
    }
    for (j=0;j<i;j++){
        m=TTTC
    }
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
    printf("\n\t\t\t-> Replenish the stock                  .6.\n");
    usleep(30000);
    printf("\n\t\t\t-> Delete products                      .7.\n");
    usleep(30000);
    printf("\n\t\t\t-> Sales statistics                     .8.\n");
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
        Search();
        break;
    case 6:
        Replenish();
        break;
    case 7:
        Delete();
        break;
    case 8:
        Statistics();
        break;
    default:
        break;
    }
    system("cls");
    return 0;
}
