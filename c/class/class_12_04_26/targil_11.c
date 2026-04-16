#include <stdio.h>

int main(void){
    int product_a_qty, product_b_qty=0;
    double product_a_price, product_b_price=0;
    printf("please enter the quantity of product A:");
    scanf("%d", &product_a_qty);
    printf("please enter the price of product A:");
    scanf("%lf", &product_a_price);
    printf("please enter the quantity of product B:");
    scanf("%d", &product_b_qty);
    printf("please enter the price of product B:");
    scanf("%lf", &product_b_price);
    double avg_price = (product_a_price*product_a_qty+product_b_price*product_b_qty)/(product_a_qty+product_b_qty); //get the average price of the two products
    printf("the average price of the two products is: %.5lf\n", avg_price);
    return 0;
}