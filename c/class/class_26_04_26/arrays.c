#include <stdio.h>

//for getting array length in the program, instead of repating myself
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

// --- FUNCTION PROTOTYPES ---
void find_number(int arr[], size_t size, int target);
void print_stats(int arr[], size_t size);
void bubble_sort(int arr[], size_t size);

int main(void) {
    int my_array[] = {5, 8, 10, 7, 6, 4};
    size_t n = ARRAY_LENGTH(my_array);

    // 1. Search
    find_number(my_array, n, 10);

    // 2. Statistics (Min, Max, Avg)
    print_stats(my_array, n);

    // 3. Sorting
    printf("array before sort: [");
    for (size_t counter=0;counter<ARRAY_LENGTH(my_array);counter++){
        printf(" %d ",my_array[counter]);
    }
    printf("]\n");

    bubble_sort(my_array, n);
    
    printf("array before sort: [");
    for (size_t counter=0;counter<ARRAY_LENGTH(my_array);counter++){
        printf(" %d ",my_array[counter]);
    }
    printf("]\n");

    return 0;
}

/**
 * Searches for a specific integer within an array and prints the result.
 * @param arr    The integer array to search through.
 * @param size   The number of elements in the array.
 * @param target The integer value we are looking for.
 */
void find_number(int arr[], size_t size, int target) {
    // Flag to track if the target has been located (0 = false, 1 = true)
    int found = 0;

    // Iterate through each element of the array using a linear search
    for (size_t counter = 0; counter < size; counter++) {
        // Check if the current element matches the target value
        if (arr[counter] == target) {
            printf("Found the number: %d\n", arr[counter]);
            
            // Update the flag and exit the loop early since we found it
            found = 1;
            break;
        }
    }

    // If the loop finished without the 'found' flag being set to 1
    if (found == 0) {
        printf("didn't find the number :(\n");
    }
}

/**
 * Calculates and prints the minimum, maximum, and average values of an integer array.
 * @param arr  Pointer to the integer array.
 * @param size The number of elements in the array.
 */
void print_stats(int arr[], size_t size) {
    // Edge case: Handle empty arrays to avoid division by zero or invalid memory access
    if (size == 0) return;

    // Initialize trackers with the first element of the array
    int min = arr[0];
    int max = arr[0];
    int sum = 0;

    // Iterate through the array once (O(n) complexity)
    for (size_t counter = 0; counter < size; counter++) {
        // Update minimum if current element is smaller
        if (arr[counter] < min) min = arr[counter];
        
        // Update maximum if current element is larger
        if (arr[counter] > max) max = arr[counter];
        
        // Accumulate the total sum for the average calculation
        sum += arr[counter];
    }

    // Output the results to the console
    printf("minimum number: %d\n", min);
    printf("maximum number: %d\n", max);
    
    /* * Cast 'sum' to double before division to ensure floating-point precision.
     * Otherwise, integer division would truncate the decimal part.
     */
    printf("average: %.2f\n", (double)sum / size);
}

void bubble_sort(int arr[], size_t size) {
    // Outer loop: Controls how many passes we make through the array.
    // After each pass, the largest remaining element is guaranteed to be in its correct place.
    for (size_t index = 0; index < size - 1; index++) {
        
        // Inner loop: Compares adjacent elements.
        // We subtract 'index' because the last 'index' elements are already sorted.
        for (size_t counter = 0; counter < size - index - 1; counter++) {
            
            // If the current element is greater than the next one, they are out of order.
            if (arr[counter] > arr[counter + 1]) {
                
                // Swap the elements using a temporary variable
                int temp = arr[counter];
                arr[counter] = arr[counter + 1];
                arr[counter + 1] = temp;
            }
        }
    }
}