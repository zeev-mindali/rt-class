#include <stdio.h>

int main(void) {
    int width,height;
    printf("please enter width and height:");
    scanf("%d %d",&width,&height);
    for (size_t counter_width=0;counter_width<width;counter_width++){
        printf("*");
    }
    printf("\n");
    for (size_t counter_height=0;counter_height<height-2;counter_height++){
        printf("*");
        for (size_t counter_width_spaces=0;counter_width_spaces<width-2;counter_width_spaces++){
            printf(" ");
        }
        printf("*\n");
    }
    for (size_t counter_width=0;counter_width<width;counter_width++){
        printf("*");
    }
    return 0;
}