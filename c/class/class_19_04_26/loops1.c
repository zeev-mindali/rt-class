#include <stdio.h>

int main(void) {
    int width, height;

    // Prompt the user for dimensions
    printf("Please enter width and height: ");
    
    // Read user input for width and height
    scanf("%d %d", &width, &height);

    // Outer loop handles the rows (vertical height)
    for (size_t counter_height = 0; counter_height < height; counter_height++) {
        
        // Inner loop handles the columns (horizontal width)
        for (size_t counter_width = 0; counter_width < width; counter_width++) {
            // Print a single star for each column in the current row
            printf("*");
        }
        
        // Move to a new line after finishing a full row of stars
        printf("\n");
    }

    return 0;
}