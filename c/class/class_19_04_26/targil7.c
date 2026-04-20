#include <stdio.h>
#include <math.h>

int main(void) {
    int x1,x2,y1,y2;
    double distance;
    printf("Please enter coordinates x1 y1 x2 y2:");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    printf ("\nDistance is :%lf",distance);
    return 0;
}