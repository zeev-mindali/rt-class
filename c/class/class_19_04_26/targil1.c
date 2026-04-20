#include <stdio.h>

int main(void) {
    int num1,num2,num3; //
    printf("Please enter first number:");
    scanf("%d",&num1);
    printf("Please enter second number:");
    scanf("%d",&num2);
    printf("Please enter third number:");       
    scanf("%d",&num3);
    if (num1>num2 && num1>num3)
        printf("The largest number is: %d\n",num1);
    else if (num2>num1 && num2>num3)
        printf("The largest number is: %d\n",num2);
    else
        printf("The largest number is: %d\n",num3);
    return 0;
}