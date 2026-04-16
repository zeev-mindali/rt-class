#include <stdio.h>

int main(void){
    int a,b=0;
    printf("input a number for a:");
    scanf("%d", &a);
    printf("input a number for b (not zero):");
    scanf("%d", &b);
    printf("---------------------\n");
    printf("a=%d , b=%d\n", a, b);
    printf("a+b=%d\n", a+b);
    printf("a-b=%d\n", a-b);
    printf("a*b=%d\n", a*b);
    printf("a/b=%d\n", a/b);
    printf("a%%b=%d\n", a%b);
    return 0;
}