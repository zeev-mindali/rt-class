#include <stdio.h>

int main(void) {
    int x,y;
    int qurater;
    printf ("Please enter x and y coordinates:");
    scanf ("%d %d",&x,&y);

    if (x>=0 && y>=0){
        qurater=1;
    } else if (x<0 && y>=0){
        qurater=2;
    } else if (x<0 && y<0){
        qurater=3;
    } else {
        qurater=4;
    }

    printf("the point located in qurater:%d",qurater);

    return 0;
}