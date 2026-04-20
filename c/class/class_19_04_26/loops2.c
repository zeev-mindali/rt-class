#include <stdio.h>

int main(void) {
    int width, height;

    // Prompt user for dimensions
    printf("please enter width and height:");
    scanf("%d %d", &width, &height);

    // --- Draw the Top Border ---
    // Prints a solid line of asterisks based on the specified width
    for (size_t counter_width = 0; counter_width < width; counter_width++) {
        printf("*");
    }
    printf("\n");

    // --- Draw the Hollow Middle Section ---
    // We subtract 2 from the height because the top and bottom rows are handled separately
    for (size_t counter_height = 0; counter_height < height - 2; counter_height++) {
        // Print the left-side vertical boundary
        printf("*");

        // Print the internal spaces (Width minus the two boundary asterisks)
        for (size_t counter_width_spaces = 0; counter_width_spaces < width - 2; counter_width_spaces++) {
            printf(" ");
        }

        // Print the right-side vertical boundary and move to the next line
        printf("*\n");
    }

    // --- Draw the Bottom Border ---
    // Only execute if height is greater than 1 to avoid duplicating the top row
    if (height > 1) {
        for (size_t counter_width = 0; counter_width < width; counter_width++) {
            printf("*");
        }
    }

    return 0;
}