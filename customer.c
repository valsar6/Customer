//
// Created by zioto on 20/06/2018.
//

#include "customer.h"
#include <stdio.h>
#include <stdlib.h>



struct Customer {
    char name[DIM];
    char* typeOfCustomer; // gold, silver, bronze, etc
    /* Bind the strategy to Customer using pointers to functions */
    float (*p_priceStrategy)(float amount, float shipping) ;
    void (*p_greetingsStrategy)();
    // to implement:
    //      List orders; address; telephone number; etc
    //      ...
};


struct Customer * newCustomer(struct Customer *p_c){

    printf("Insert customer's name: ");
    fgets(p_c->name, DIM, stdin);

    printf("Choose customer type:\n");
    printf("a: GOLD\n");
    printf("b: SILVER\n");
    printf("c: BRONZE\n");

    switch (getchar()) {
        case 'a':
            p_c->typeOfCustomer = "gold";
            p_c->p_priceStrategy=goldPriceStrategy;
            p_c->p_greetingsStrategy=goldGreetingsStrategy;
            break;
        case 'b':
            p_c->typeOfCustomer = "silver";
            p_c->p_priceStrategy=silverPriceStrategy;
            p_c->p_greetingsStrategy=silverGreetingsStrategy;
            break;
        case 'c':
            p_c->typeOfCustomer = "bronze";
            p_c->p_priceStrategy=bronzePriceStrategy;
            p_c->p_greetingsStrategy=bronzeGreetingsStrategy;
            break;
        default:
            perror("Unknown customer type");
            exit(1);
    }
    return p_c;
}



float computePrice(struct Customer *p_c, float amount,float shipping) {
    /* compute the total price
     * depending on customer category. */
    float price;

    price=(p_c->p_priceStrategy)(amount, shipping);
    /* it will be
     * bronzePriceStrategy, silverPriceStrategy, goldPriceStrategy
     * or others
     * depending on the Customer*/
    return price;
}


float bronzePriceStrategy(float amount, float shipping){
    return amount+shipping;
}
float silverPriceStrategy(float amount, float shipping){
    return 0.9*amount+shipping;
}
float goldPriceStrategy(float amount, float shipping){
    return 0.8*amount; // free shipping;
}

/**
 *
 * This is the motherfucking greetings strategy
 */

void greetings(struct Customer  * p_c) {
    // Happy Birthday (and gift card for some categories)
    (p_c->p_greetingsStrategy)();
}

void goldGreetingsStrategy(){
    printf("Happy Birthday + gift card 20 euros!");
};
void silverGreetingsStrategy(){
    printf("Happy Birthday + gift card 10 euros!");
};
void bronzeGreetingsStrategy(){
    printf("Happy Birthday!");
};
