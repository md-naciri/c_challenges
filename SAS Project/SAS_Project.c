#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
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

typedef struct ProductID //The product Structure
{
    char code[20];
    char name[20];
    int quantity;
    float price;
}Product;

typedef struct Save //The statistics structure
{
    char name[20];
    char code[20];
    int quan;
    float TTTCprice;
    float UTTCprice;
    char date[50];
}Save;

Product pro[200]; 
Save S[200];
char B; //B for back
char Y; //To do sth again
int i=0; //a counter for pro[]
int s=0; //a counter for S[]
float snb=0;// Total number of items sold
int op; //op for option
int j;

//Return to the main menu
void return_menu(){
    printf("\n\tEnter a capital B to return to the main menu\t\t");
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

//Adding a new product Function:
void Add(){
    char codeCompare[20];
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
    i++;
    return_menu();
}

//Adding several products Function:
void AddSev(){
    int n, count =1;
    char codeCompare[20];
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
                printf("\n\tThis product already exists, you can add more items of this product by typing 1, \n\tor 0 to add another new product :\t");
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
    return_menu();
}

//Listing products Function:
void List(){
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
    printf("\n\n\tBefore");
    for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f",pro[j].name,pro[j].price,pro[j].price*1.15);
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
        printf("\n\n\tAfter:");
        for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f",pro[j].name,pro[j].price,pro[j].price*1.15);
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
        printf("\n\n\tAfter:");
        for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tPrice: %.2f\t\t\tTTC Price: %.2f",pro[j].name,pro[j].price,pro[j].price*1.15);
        }
        break;
    default: goto NO1;
        break;
    }
    printf("\n\n\tType a capital Y if you want to list products again:\t");
    scanf("%s",&Y);
    if (Y == 'Y') goto NO1;
    else return_menu();
}

//Buy a product Function:
void Buy(){
    char nameCompare[20];
    int nb; //number of items to buy 
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Buying a product ||-----------------------------||\n\n");
    NO:
    printf("\033[1;36m"); //Cyan Color
    for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f",pro[j].name,pro[j].quantity,pro[j].price*1.15);
        }
    printf("\n\tEnter the name of the product you want to buy:\t");
  	scanf("%s",nameCompare);
    make_toupper(nameCompare);
    int c=0; //check if there is a product
    for (j=0;j<i;j++){
        if (strcmp(pro[j].name,nameCompare)==0){
            NO2:
            printf("\n\tEnter how many item you want to buy:\t");
            scanf("%d",&nb);
            if(nb>pro[j].quantity){
                printf("\n\tThere are just %d items left of this product",pro[j].quantity);
                goto NO2;
            }
            if (nb<0) {
                printf("\n\tYou cannot enter a negative number");
                goto NO2;
            }
            printf("\n\tQuantity before buying: ");
            printf("\n\tName: %s\t\t\tTTC Price: %.2f\t\t\tQuantity: %d\n",pro[j].name,pro[j].price*1.15,pro[j].quantity);
            pro[j].quantity=pro[j].quantity-nb;
            strcpy(S[s].name,pro[j].name);
            strcpy(S[s].code,pro[j].code);
            S[s].quan=nb;
            S[s].UTTCprice=pro[j].price*1.15;
            S[s].TTTCprice=pro[j].price*1.15*nb;
            time_t t = time(NULL);
            strcpy(S[s].date,ctime(&t));
            s++;
            snb += nb;
            c++;
            break;
        }
    }
    if (c==0) {
        printf("\n\tThere is no such product");
        goto NO;
    }
    printf("\n\tQuantity after buying: ");
    printf("\n\tName: %s\t\t\tTTC Price: %.2f\t\t\tQuantity: %d\n",pro[j].name,pro[j].price*1.15,pro[j].quantity);
    sleep(1);
    printf("\n\n\tEnter a capital Y to buy again, or a capital B to return to the main menu:\t\t");
    scanf("%s",&B);
    while((B != 'B') && (B != 'Y')){
        printf("\033[0;33m"); //Yellow Color
  	    printf("\tPlease enter a capital A to buy again, or a capital B to return to the main menu:\t");
  		scanf("%s",&B);
	}
    if (B == 'Y') goto NO;
    else{
        system("cls");
        printf("\033[0;37m"); //White color
        main();
    }
}

//Products search Function:
void Search(){
    char codeCompare[20];
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
                    printf("\tCode: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                    break;
                }
            }
            if (count==0) {
                printf("\n\tThere is no such product");
                goto NO1;
            }
            else {
                printf("\n\n\tType a capital Y if you want to search again:\t");
                scanf("%s",&Y);
                if (Y == 'Y') goto NO1;
                else return_menu();
            };
        break;

        case 2:
            printf("\n\tPlease enter the quantity:\t");
  	        scanf("%d",&q);
            for (j=0;j<i;j++){
                if (q==pro[j].quantity){
                    printf("\tCode: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                }
            }
            if (count==0) {
                printf("\n\tThere is no such product with this quantity");
                goto NO1;
            }
            else {
                printf("\n\n\tType a capital Y if you want to search again:\t");
                scanf("%s",&Y);
                if (Y == 'Y') goto NO1;
                else return_menu();
            };
        break;

        case 3:
            for (j=0;j<i;j++){
                if (pro[j].quantity<3){
                    printf("\tStock status:\n");
                    printf("\tCode: %s\t\t\tName: %s\t\t\tQuantity: %d\t\t\tTTC Price: %.2f\n",pro[j].code,pro[j].name,pro[j].quantity,pro[j].price*1.15);
                    count++;
                }
            }
            if (count==0) {
                printf("\n\tThere is no product with a quantity less than 3\n\n");
                goto NO1;
            }
            else {
                printf("\n\n\tType a capital Y if you want to search again:\t");
                scanf("%s",&Y);
                if (Y == 'Y') goto NO1;
                else return_menu();
            };
        break;

        default: goto NO1;
        break;
        }

}

//Replenish stock Function:
void Replenish(){
    char codeCompare[20];
    int q; //q for the quantity
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------------|| Replenish/Supplying ||-----------------------------||\n\n");
    for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tCode: %s\t\t\tQuantity: %d",pro[j].name,pro[j].code,pro[j].quantity);
    }
    NO:
    printf("\n\tEnter the code of the product:\t");
  	scanf("%s",codeCompare);
    make_toupper(codeCompare);
    int c=0; //check if there is a product
    for (j=0;j<i;j++){
        if (strcmp(pro[j].code,codeCompare)==0){
            NO1:
            printf("\n\tEnter the quantity please:\t");
            scanf("%d",&q);
            if (q<0){
                printf("\n\tYou cannot enter a negative number");
                goto NO1;
            }
            printf("\n\tQuantity before supplying: ");
            printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
            pro[j].quantity=pro[j].quantity+q;
            c++;
            break;
        }
    }
    if (c==0) {
        printf("\n\tThere is no such product");
        NO2:
        printf("\n\tTo reenter a correct code enter Y, to return to the menu enter B:\t");
        scanf("%s",&Y);
        if (Y == 'B') return_menu();
        else if (Y == 'Y') goto NO;
        else goto NO2;
    }
    printf("\n\n\tQuantity after suppling: ");
    printf("\n\tName: %s\t\t\tQuantity: %d\n",pro[j].name,pro[j].quantity);
    printf("\n\n\tType a capital Y if you want to replenish again:\t");
    scanf("%s",&Y);
    if (Y == 'Y') goto NO;
    else return_menu();
}

//Delete products Function:
void Delete(){
    int c=0;
    int k;
    char codeCompare[20];
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------|| Delete a product ||-----------------------||\n\n");
    sleep(1);
    for (j=0;j<i;j++){
        printf("\n\tName: %s\t\t\tCode: %s",pro[j].name,pro[j].code);
    }
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
        NO2:
        printf("\n\tTo reenter a correct code enter Y, to return to the menu enter B:\t");
        scanf("%s",&Y);
        if (Y == 'B') return_menu();     
        else if (Y == 'Y') goto NO;   
        else goto NO2;
        goto NO;
    }
    else{
        for (k=j;k<i;k++){
            pro[k]=pro[k+1];
        }
        i--;
    }
    printf("\n\tProduct deleted\n");
    sleep(1);
    printf("\n\n\tType a capital Y if you want to search again:\t");
    scanf("%s",&Y);
    if (Y == 'Y') goto NO;
    else return_menu();
}

//Sales statistics Function:
void Statistics(){
    float total=0;
    int k;
    struct Save temp;
    
    printf("\033[1;36m"); //Cyan Color
    printf("\n\t||-----------------------|| Sales statistics ||-----------------------||\n\n");
    sleep(1);
    
    printf("\n\tProducts sold: \n");
    for(j=0;j<s;j++){
        printf("\n\tDate:%.24s",S[j].date);
        printf("\n\tName:%s\t\t\tCode:%s\t\t\tNb of Items:%d\t\t\tTTC Price:%.2f\n",S[j].name,S[j].code,S[j].quan,S[j].TTTCprice);
    }
    
    for (j=0;j<s;j++){
        total+=S[j].TTTCprice;
    }
    printf("\n\n\tThe total price of the products sold:\t%.2f",total);
    printf("\n\n\tthe average price of the products sold:\t%.2f",total/snb);

    for (j=0;j<s-1;j++){
            for(k=j+1;k<s;k++){
                if(S[j].UTTCprice > S[k].UTTCprice){
                    temp=S[j];
                    S[j]=S[k];
                    S[k]=temp;
                }
            }
        }
    // for (j=0;j<s-1;j++){
    //     for(k=j+1;k<s;k++){
    //         if(S[j].TTTCprice > S[k].TTTCprice){
    //             temp=S[j];
    //             S[j]=S[k];
    //             S[k]=temp;
    //         }
    //     }
    // }    
    printf("\n\n\tThe Min of the prices of the products sold is:");
    printf("\n\tName: %s\t\tUnit TTC Price: %.2f",S[0].name,S[0].UTTCprice);
    printf("\n\n\tThe Max of the prices of the products sold is:");
    printf("\n\tName: %s\t\tUnit TTC Price: %.2f\n",S[s-1].name,S[s-1].UTTCprice);
    sleep(1);
    return_menu();
}

//The main function
int main () {
    printf("\n\t||-----------------------------|| Hello & Welcome ||-----------------------------||\n\n");
    NO:
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
    printf("\n\t\t\t-> Exit the app                         .9.\n");
    usleep(30000);
    printf("\n\n\t\t\t-> Choose an option:\t\t");
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
    case 9: exit(0);
        break;
    default: printf("\n\tPlease enter a number between 1 & 9:\t\n\n");
             goto NO;
        break;
    }
    system("cls");
    return 0;
}