//
// Created by zioto on 20/06/2018.
//

#ifndef CUSTOMER_CUSTOMER_H
#define CUSTOMER_CUSTOMER_H

typedef struct  Customer * cPtr;

float computePrice(struct Customer *p_c, float amount,float shipping);
float bronzePriceStrategy(float amount, float shipping);
float silverPriceStrategy(float amount, float shipping);
float goldPriceStrategy(float amount, float shipping);

void greetings(struct Customer  *p_c);
void goldGreetingsStrategy();
void silverGreetingsStrategy();
void bronzeGreetingsStrategy();

#endif //CUSTOMER_CUSTOMER_H
