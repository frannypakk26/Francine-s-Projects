/*Fall 2021: Customer Billing System
Implemented a Program that is used to show the bill of customers at a department cafe
Displays the menu, list of items bought and the cost, tax, and tips
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int i, quantity[10], percentage, y, phone_number;
    float price, value, total_value, x = 0, m = 0, p = 0;
    char items[11][11], payment[22], name[20], phone[13];
    float Americano = 2.75, Chai_Latte = 4.80, Cappuccino = 3.45, Java_Frap = 5.70, Latte = 3.30,
    Croissant = 2.43, Cake_Pop = 1.28, Panini = 7.40, Bagel = 2.40, Mug = 10.00;

    printf("ACF Cafe Menu: \n Americano ............. $2.75 \n Chai_Latte ............ $4.80 \n Cappuccino ............ $3.45 \n Java_Frap ............. $5.70 \n Latte ................. $3.30 \n Croissant ............. $2.43 \n Cake_Pop .............. $1.28 \n Panini ................ $7.40 \n Bagel ................. $2.40 \n Mug ................... $10.00\n\n");
    
    printf("HOW MANY ITEMS: ");
    scanf("%d", &y);

    for(i=1; i<=y; i++){
        printf("ENTER PRODUCT ITEM NAMES: ");
        scanf("%s", items[i]);
        printf("ENTER PRODUCT QUANTITY: ");
        scanf("%d", &quantity[i]);


    }
    
    printf("\n");
    printf ("ENTER YOUR FIRST NAME ON THE ORDER: ");
    scanf("%s", name);
    printf ("ENTER YOUR PHONE NUMBER (XXX-XXX-XXXX): ");
    scanf("%s", phone);
    printf("ENTER PAYMENT TYPE (CASH OR CARD): ");
    scanf("%s", payment);

    //percentage for tip
    printf("ENTER TIP PERCENTAGE: ");
    scanf("%d", &percentage);

    printf("\n\n\n\n\n");
    printf("Order for %s. \n", name);
    printf("Your phone number is: %s\n\n ", phone);
    
    printf("                                     WELCOME TO ACF CAFE                                    \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("    ITEM                            QUANTITY             PRICE                    VALUE                \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    
    //searches for the item and price
    total_value = 0;
    i = 1;
    while(i<=y){
    //compares item index with string 
    if(strcmp(items[i], "Americano") == 0){
        price = Americano;
    }
    if(strcmp(items[i], "Chai_Latte") == 0){
        price = Chai_Latte;
    }
    if(strcmp(items[i], "Cappuccino") == 0){
        price = Cappuccino;
    }
    if(strcmp(items[i], "Java_Frap") == 0){
        price = Java_Frap;
    }
    if(strcmp(items[i], "Latte") == 0){
        price = Latte;
    }
    if(strcmp(items[i], "Croissant") == 0){
        price = Croissant;
    }
    if(strcmp(items[i], "Cake_Pop") == 0){
        price = Cake_Pop;
    }
    if(strcmp(items[i], "Panini") == 0){
        price = Panini;
    }
    if(strcmp(items[i], "Bagel") == 0){
        price = Bagel;
    }
    if(strcmp(items[i], "Mug") == 0){
        price = Mug;
    }

    
    //calculations 
    value = quantity[i]*price;
    printf("%10s\t                    %5d   \t         %5.2f   \t          %5.2f\n", items[i], quantity[i], price, value);
    total_value = total_value + value;
    i++;
    }

    p = total_value * percentage / 100;
    x = (total_value/100)*7;
    m = total_value + x + p;

    
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                             Total Value = %.2f Dollar \n", total_value);
    printf("                             (+) 7 percent tax = %.2f Dollar \n", x);
    printf("                             (+) Tip: %d percent = %.2f Dollar \n", percentage, p);
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                             Total = %.2f Dollar \n", m);
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    //overcase except the supporting 
    printf("                             YOUR PAYMENT TYPE IS: %s \n", payment);
    printf("                             YOUR PAYMENT IS SUCCESSFUL of %.2f Dollar \n", m);
    printf("                             YOUR MOBILE NUMBER IS: %s \n", phone);
    printf ("                             THANK YOU FOR SUPPORTING ACF CAFE! \n");
    printf("--------------------------------------------------------------------------------------------------\n");


    return 0;
}