#include <stdio.h>

int main(void){
    typedef int LONG;
    LONG a=4;
    LONG b=68;
    float c=0;
    c=b;
    b=a+b;
    printf("%d,", b);
    printf("%f\n", c);
    return 0;
}