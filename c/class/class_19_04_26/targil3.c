#include <stdio.h>

#define MIN_LIMIT 100
#define MAX_LIMIT 999

int main(void) {
   int number;

    printf("Please enter a 3-digit number: ");

    // 1. Robust input checking
    if (scanf("%d", &number) != 1) {
        printf("Error: Please enter a valid integer.\n");
        return 1; 
    }

    // 2. Validate range (including negative values)
    if (number < MIN_LIMIT || number > MAX_LIMIT) {
        printf("Invalid input: Number must be between %d and %d.\n", MIN_LIMIT, MAX_LIMIT);
        return 1;
    }

    // 3. Separation logic
    int d1 = number / 100;       // Hundreds
    int d2 = (number / 10) % 10; // Tens
    int d3 = number % 10;        // Units

    printf("Separated digits: %d, %d, %d\n", d1, d2, d3);
    
    // 4. Logical Checks
    if (d1 < d2 && d2 < d3) {
        printf("Trend: Very ascending\n");
    } 
    else if ((d1 <= d2 && d2 < d3) || (d1 < d2 && d2 <= d3)) {
        printf("Trend: Ascending\n");
    } 
    else if (d1 > d2 && d2 > d3) {
        printf("Trend: Very descending\n");
    } 
    else if ((d1 >= d2 && d2 > d3) || (d1 > d2 && d2 >= d3)) {
        printf("Trend: Descending\n");
    } 
    else {
        printf("Trend: Digits neither ascending nor descending\n");
    } 
    
}