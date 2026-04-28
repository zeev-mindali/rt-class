#include <stdio.h>

// --- FUNCTION PROTOTYPES ---
int calc(int num1,int num2,char opr);

int main(void) {
    int num1,num2;
    unsigned char opr;
    printf("Please enter exp e.g. 5 + 2 (result -1 means error):");
    scanf("%d %c %d",&num1,&opr,&num2);
    printf ("result of %d %c %d = %d\n",num1,opr,num2,calc(num1,num2,opr));
    return 0;
}

int calc(int num1,int num2,char opr){
    switch (opr){
        case '+':
            return num1+num2;
            break;
        case '-':
            return num1-num2>=0?num1-num2:(num1-num2)*-1;
        case '*':
            return num1*num2;
        case '/':
            return num2!=0?num1/num2:-1;
        default:
            return -1;
    }
}