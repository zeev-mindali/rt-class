#include <stdio.h>

//for getting array length in the program, instead of repating myself
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

// --- FUNCTION PROTOTYPES ---
/**
 * Swaps the content of two memory locations of a given size.
 * @param p_var  Pointer to the first variable
 * @param p_var2 Pointer to the second variable
 * @param size   The size (in bytes) of the data type being swapped
 */
void swap_any(void *p_var, void *p_var2, size_t size);
void arr_mix(int *arr, int n);
void print_array(int *arr, size_t size);

int main(void) {
    // Testing the method with double precision floating point numbers
    double num1 = 5.2;
    double num2 = 7.9;

    printf("before swap: num1 = %f, num2 = %f\n", num1, num2);
    
    // Pass the addresses and the size of the double 
    swap_any(&num1, &num2, sizeof(num1));
    
    printf("after swap: num1 = %f, num2 = %f\n", num1, num2);
    
    printf("---------------------------------------\n");

    int my_arr[]={5,23,9,78,45,92,32,100,33,50};
    printf("before arr_mix: \n");
    print_array(my_arr, ARRAY_LENGTH(my_arr));
    arr_mix(my_arr, ARRAY_LENGTH(my_arr));
    printf("after arr_mix: \n");
    print_array(my_arr, ARRAY_LENGTH(my_arr));
    return 0;
}

/**
 * Logic: Treats the generic memory as an array of bytes (unsigned char)
 * and performs a swap on each byte individually.
 */
void swap_any(void *p_var, void *p_var2, size_t size){
    // Cast the void pointers to unsigned char* to allow byte-level manipulation
    unsigned char *num1 = (unsigned char *)p_var;
    unsigned char *num2 = (unsigned char *)p_var2;
    unsigned char temp;

    // Iterate through every byte of the memory block
    for (size_t counter = 0; counter < size; counter++){
        // Classic swap algorithm applied to the current byte
        temp = num1[counter];
        num1[counter] = num2[counter];
        num2[counter] = temp;
    }
}

void arr_mix(int *arr, int n) {
    if (n <= 1) return;

    // Allocate on the stack 
    int temp[n]; 

    // 1. Lower half -> Even indexes
    for (size_t counter = 0; counter < n/2; counter++) {
        temp[counter * 2] = arr[counter];
    }

    // 2. Upper half -> Odd indexes (reversed)
    for (size_t counter = 0; counter < (n - n/2); counter++) {
        temp[counter * 2 + 1] = arr[n - 1 - counter];
    }

    // 3. Cyclic shift left while copying back to original array
    // The element at temp[0] moves to arr[n-1]
    // The element at temp[i] moves to arr[i-1]
    for (size_t counter = 1; counter < n; counter++) {
        arr[counter - 1] = temp[counter];
    }
    arr[n - 1] = temp[0];
}

void print_array(int *arr, size_t size) {
    for (size_t counter = 0; counter < size; counter++) {
        printf("%d ", arr[counter]);
    }
    printf("\n");
}