#include <stdio.h>

typedef struct{
    int number1;
    int number2;
} My_numbers;

// --- FUNCTION PROTOTYPES ---
My_numbers replace_two_numbers_with_temp(My_numbers nums);
My_numbers replace_two_numbers_without_temp(My_numbers nums);
My_numbers replace_two_numbers_with_bitwise(My_numbers nums);

int main(void) {
    //since we can not return two variables, we will use strucy for returning them.
    //create new variable from struct
    My_numbers nums; 
    printf("Please enter two numbers (Integer):");
    //get input from user and enter into struct.
    scanf("%d %d",&nums.number1, &nums.number2); 
    printf("Before swap - number1: %d, number2: %d\n", nums.number1, nums.number2);
    
    nums = replace_two_numbers_with_temp(nums);
    printf("After swap  with temp - number1: %d, number2: %d\n", nums.number1, nums.number2);

    nums = replace_two_numbers_without_temp(nums);
    printf("After swap  without temp - number1: %d, number2: %d\n", nums.number1, nums.number2);

    nums = replace_two_numbers_with_bitwise(nums);
    printf("After swap  with bitwise - number1: %d, number2: %d\n", nums.number1, nums.number2);
    //
    return 0;
}

My_numbers replace_two_numbers_with_temp(My_numbers nums){
    int temp;
    temp = nums.number2;
    nums.number2 = nums.number1;
    nums.number1 = temp;
    return nums;
}

My_numbers replace_two_numbers_without_temp(My_numbers nums){
    nums.number1 += nums.number2;  //num1+num2 -> 5 + 7 -> 12
    nums.number2 = nums.number1 - nums.number2;  //num2-num1 -> 12 - 7 -> 5 (first swap)
    nums.number1 -= nums.number2;  //num1-num2 -> 12 - 5 -> 7 (second swap)
    return nums;
}

My_numbers replace_two_numbers_with_bitwise(My_numbers nums){
   // Standard XOR swap algorithm
    nums.number1 = nums.number1 ^ nums.number2; // Step 1
    nums.number2 = nums.number1 ^ nums.number2; // Step 2: Now number2 becomes original number1
    nums.number1 = nums.number1 ^ nums.number2; // Step 3: Now number1 becomes original number2
    
    return nums;
}

