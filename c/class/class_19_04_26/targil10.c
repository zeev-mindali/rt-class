#include <stdio.h>

int main(void) {
    int day, month, year;

    printf("Enter day, month, and year (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    
    printf("Your Zodiac Sign is: ");

    switch (month) {
        case 1: // January
            printf((day <= 19) ? "Capricorn\n" : "Aquarius\n");
            break;
        case 2: // February
            printf((day <= 18) ? "Aquarius\n" : "Pisces\n");
            break;
        case 3: // March
            printf((day <= 20) ? "Pisces\n" : "Aries\n");
            break;
        case 4: // April
            printf((day <= 19) ? "Aries\n" : "Taurus\n");
            break;
        case 5: // May
            printf((day <= 20) ? "Taurus\n" : "Gemini\n");
            break;
        case 6: // June
            printf((day <= 20) ? "Gemini\n" : "Cancer\n");
            break;
        case 7: // July
            printf((day <= 22) ? "Cancer\n" : "Leo\n");
            break;
        case 8: // August
            printf((day <= 22) ? "Leo\n" : "Virgo\n");
            break;
        case 9: // September
            printf((day <= 22) ? "Virgo\n" : "Libra\n");
            break;
        case 10: // October
            printf((day <= 22) ? "Libra\n" : "Scorpio\n");
            break;
        case 11: // November
            printf((day <= 21) ? "Scorpio\n" : "Sagittarius\n");
            break;
        case 12: // December
            printf((day <= 21) ? "Sagittarius\n" : "Capricorn\n");
            break;
    }
    return 0;
}