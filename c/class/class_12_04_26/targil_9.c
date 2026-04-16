#include <stdio.h>

int main (void){
    int a,b=0;
    printf("input a number for a:");
    scanf("%d", &a);
    printf("input a number for b (not zero):");
    scanf("%d", &b);
    printf("---------------------\n");
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a=%d , b=%d\n", a, b);
    return 0;
}