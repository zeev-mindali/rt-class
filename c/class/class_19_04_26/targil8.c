#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, c;
    double delta, x1, x2;

    // Input coefficients from the user
    printf("Enter coefficients a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    // --- Validation: Check if it's a quadratic equation ---
    // Edge case: if a is 0, it's not a quadratic equation
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero in a quadratic equation.\n");
        return 1;
    }

    // Calculate the discriminant: b^2 - 4ac
    delta = b * b - 4 * a * c;

    // Check if real solutions exist
    if (delta > 0) {
        // Two distinct real solutions
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("The solutions are: x1 = %.2f, x2 = %.2f\n", x1, x2);
    } 
    else if (delta == 0) {
        // One (double) real solution
        x1 = -b / (2 * a);
        printf("There is one real solution: x1 = %.2f\n", x1);
    } 
    else {
        // Discriminant is negative - no real solutions
        printf("There are no real solutions for this equation.\n");
    }
    return 0;
}