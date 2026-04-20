#include <stdio.h>

int main(void) {
    int day, month, year;

    printf("Enter day, month, and year (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    switch (month){
        //months ends in 31
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day<31){
                printf("Next day:%02d %02d %02d",day+1,month,year);
            } else {
                printf("next day:%02d/%02d/%02d",1,month+1,year);
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day<30){
                printf("Next day:%02d %02d %02d",day+1,month,year);
            } else {
                printf("next day:%02d/%02d/%02d",1,month+1,year);
            }
            break;
        case 2:
            //check if the year is leaped or not.....
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                //leaped year
                if (day<29){
                    printf("Next day:%02d %02d %02d",day+1,month,year);
                } else {
                    printf("next day:%02d/%02d/%02d",1,month+1,year);
                }
            } else {
                //leaped year
                if (day<28){
                    printf("Next day:%02d %02d %02d",day+1,month,year);
                } else {
                    printf("next day:%02d/%02d/%02d",1,month+1,year);
                }
            }
            break;
        default:
            printf ("Invalid input");
    }
    return 0;
}