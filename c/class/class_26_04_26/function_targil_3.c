#include <stdio.h>

// --- FUNCTION PROTOTYPES ---
int get_nth_fibonaci(int nth);

int main(void) {
    int nth;
    printf("Please enter nth place: ");
    scanf("%d",&nth);
    printf("%dnth place: %d\n",nth,get_nth_fibonaci(nth));
    return 0;
}

int get_nth_fibonaci(int nth){
    int counter=0;
    int num1=0; //first number
    int num2=1; //second number
    //while we didn't reach our number, countinue calculate
    while (counter < nth) {
        num2 += num1;       // num2 becomes the next number
        num1 = num2 - num1; // num1 becomes the previous num2
        counter++;
    }
    return num2;
}