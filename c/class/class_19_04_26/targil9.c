#include <stdio.h>

int main() {
    double hypotenuse, height, area;

    // Input: Length of hypotenuse and height to it
    printf("Enter hypotenuse length: ");
    scanf("%lf", &hypotenuse);
    printf("Enter height to hypotenuse: ");
    scanf("%lf", &height);

    /* * Validation Logic:
     * In a right-angled triangle, the maximum height to the hypotenuse 
     * is half the length of the hypotenuse (h <= hypotenuse / 2).
     */
    if (height > hypotenuse / 2.0 || height <= 0 || hypotenuse <= 0) {
        // If the condition is not met, the triangle is invalid
        printf("Error: Invalid input. Such a triangle cannot exist.\n");
    } else {
        // Calculation: Area = (base * height) / 2
        // Here, the hypotenuse is the base.
        area = (hypotenuse * height) / 2.0;
        
        // Output the result
        printf("Area = %.1f\n", area);
    }

    return 0;
}