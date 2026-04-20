#include <stdio.h>

int main(void) {
    //int a variable
    int user_time;
    // Prompt the user for input
    printf("Please enter a number in seconds:");
    // Store the input value into user_time
    scanf("%d",&user_time);
    // Calculate hours: total seconds divided by 3600 (60 * 60)
    int hours = user_time/3600;
    // Calculate minutes: total seconds divided by 60, 
    // then take the remainder to get the minutes within the current hour
    int minutes = user_time/60%60;
    // Calculate seconds: the remainder of total seconds divided by 60
    int seconds = user_time%60%60;
    // Print the result in HH:MM:SS format
    // %02d ensures a leading zero if the number is a single digit
    printf("user formatted time:%02d:%02d:%02d\n",hours,minutes,seconds);
    return 0;
}