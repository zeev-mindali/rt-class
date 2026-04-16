#include <stdio.h>

typedef double distance;

int main(void){ 
    printf("enter distance in miles:");
    double distance=0.0;
    scanf("%lf", &distance);
    printf("distance in kilometers: %lf\n", distance*1.60934);
    return 0;
}