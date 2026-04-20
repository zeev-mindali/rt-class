#include <stdio.h>

int main(void) {
    int num1,num2;
    printf("Please enter first number:");
    scanf("%d",&num1);
    printf("Please enter second number:");
    scanf("%d",&num2);
    if (num1%2==0 && num2%2==0 && num1%num2==0){
        printf("Valid numbers");
    } else {
        printf("Invalid numbers");
    }
    return 0;
}