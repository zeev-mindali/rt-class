#include <stdio.h>

// --- FUNCTION PROTOTYPES ---
int modulu_num(int num,int modulu);


int main(void) {
    for (size_t counter=10;counter<100;counter++){
        //check divided by 3
        if (modulu_num(counter,3)==0){
            printf("divided by 3: %d\n",(int)counter);
        }
        if (modulu_num(counter,5)==0 && modulu_num(counter,7)==0){
            printf("divided by 5 and 7:%d\n", (int)counter);
        }
    }
    return 0;
}

/*
    num integer nums to modulu
    modulu integer nums represent modulu
*/
int modulu_num(int num,int modulu){
    return num%modulu;
}
