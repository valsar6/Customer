#include <stdio.h>

int main() {
    struct Customer c, *p_c;
    //struct Customer *p_c;
    float price, finalPrice;
    const float shipping=10;
    p_c=&c;
    printf("** INSERT CUSTOMER **\n");
    p_c= newCustomer(p_c);

    printf("INSERT PRICE:\n");
    scanf("%f",&price);
    printf("COMPUTE FINAL PRICE (discount, shipping, etc):\n");
    finalPrice=computePrice(&c,price, shipping);

    // OUTPUT

    printf("customer:\n");
    printf("%s -> %s customer \n", p_c->name, p_c->typeOfCustomer);
    printf("Initial price: %.2f\n",price);
    printf("Final price: %.2f\n",finalPrice);

    greetings(p_c);

    getchar();
    getchar();

    return 0;
}