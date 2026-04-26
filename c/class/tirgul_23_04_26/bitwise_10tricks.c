#include <stdio.h>
/* bitwise tricks ^ is power, 2^2=4*/
/*
      check if a number is even or odd, instead of number%2==0 ? true : false
                         V -> LSB
               bin(9)  1001          1->odd number     9&1=1
               bin(10) 1010          0->even number   10&1=0

               for check : number & 1
*/

int check_odd_even(void){
   int number;
   printf("Enter a number:");
   scanf("%d",&number);
   if ((number & 1)==0){
      printf("an Even number\n");
   } else {
      printf("an Odd number\n");
   }
   return 0;
}

/*
     check if number is power of 2 

         x    bin(10)  1010
                        & 
         x-1  bin(9).  1001
                       ----
                       1000   (not power of 2) larger then 0

         x     bin(16) 00010000
                          &
         x-1   bin(15) 00001111
                       ---------
                       00000000    (power of 2) equal to 0
     for check : x & (x-1)  where x>0 (0 is an error, and we need to check it)
*/

int check_power_of_two (void){
   int x;
   printf("Enter a number:");
   scanf("%d",&x);   
   // Logic: A power of 2 in binary is 100...0. 
   // x-1 is 011...1. Their AND is always 0.
   // also check that the user not enterd 0
    if (x > 0 && (x & (x - 1)) == 0) {
        printf("%d is a power of 2\n", x);
    } else {
        printf("%d is NOT a power of 2\n", x);
    }
   return 0;
}

/*
      playing with Nth bit
      check if Nth bit is set : x & (1<<n) (and)
      (for example 4 bit) 
      place (k) = ...987654321
      x(bin)    = 100000
                     &
      x(bin)    = 001000
                  ------
                  101000          result is set bit
      (for example 3 bit) 
      place (k) = ...987654321
      x(bin)    = 100000
                     &
      x(bin)    = 0000100
                  -------
                  0000100         result is set bit
      ==========================================================
      toggle the Nth bit      : x ^ (1<<n) (xor)
      (for example 4 bit) 
      place (k) = 654321
      x(bin)    = 101000
                    ^ (xor)
      x(bin)    = 001000
                  ------
                  100000    (result is toglled bit)

      (for example 3 bit) 
      place (k) = ...987654321
      x(bin)    = 101000
                     ^ (xor)
      x(bin)    = 000100
                  ------
                  101100    (result is toggled bit)
      =========================================================
      set the Nth bit         : x | (1<<n) (or)
      (for example 4 bit) 
      place (k) = 654321
      x(bin)    = 101000
                    |        (or)
      x(bin)    = 001000
                  ------
                  101000    (result is toglled bit)

      (for example 3 bit) 
      place (k) = ...987654321
      x(bin)    = 101000
                     ^ (xor)
      x(bin)    = 000100
                  ------
                  101100    (result is toggled bit)
      ========================================================
      unset the Nth bit       : x & ~(1<<n) (and & not)
      (for example 4 bit) 
      place (k) = 654321
      x(bin)    = 101000
                    &        (or)
      x(bin)    = 110111
                  ------
                  100000    (result is toglled bit)

      (for example 3 bit) 
      place (k) = ...987654321
      x(bin)    = 101000
                     & (xor)
      x(bin)    = 111011   (we  use not on the number)
                  ------
                  101000    (result is toggled bit)

*/

int playing_with_n_bit(void){
   int n,         //bit index
       number=40; //which number

   // 1. CHECK if Nth bit is set
    n = 3; // Checking the 4th bit (index 3)
    printf("--- CHECKING BIT %d ---\n", n);
    if (number & (1 << n)) {
        printf("Bit %d is SET (1)\n", n);
    } else {
        printf("Bit %d is NOT SET (0)\n", n);
    }

    // 2. TOGGLE the Nth bit
    number = 5; // Toggling bit index 5
    printf("\n--- TOGGLING BIT %d ---\n", n);
    printf("Before: %d\n", number);
    number ^= (1 << n);
    printf("After %d\n",number);

    // 3. SET the Nth bit
    n = 4; // Setting bit index 4
    printf("\n--- SETTING BIT %d ---\n", n);
    printf("Before: %d\n", number);
    number |= (1 << n);
    printf("After : %d\n", number);

    // 4. UNSET (CLEAR) the Nth bit
    n = 3; // Clearing bit index 3
    printf("\n--- UNSETTING BIT %d ---\n", n);
    printf("Before: %d\n" ,number);
    number &= ~(1 << n);
    printf("After : %d\n", number);

    return 0;
}


/*
      adding two numbers without using + sign
      num1 = 5, num2 = 3

       explain:
       Think of this logic like adding numbers the way you did in primary school, but instead of working with base-10, 
       we are working with bits (0 and 1).

      To add numbers without the + button, we break the process into two parts: adding and carrying.
      1. Adding without carrying (The XOR logic)
         In binary, adding bits looks like this:
         0+0=0
         0+1=1
         1+0=1
         1+1=0
         (with a carry)

         Notice that the first three results are exactly what the XOR (^) operator does. It only gives a 1
         if the bits are different. So, temp1 ^ temp2 gives us the sum, but it "forgets" the carries.

         2. Finding the carries (The AND logic)
            A carry is only created when you have 1+1. 
            The AND (&) operator is perfect for this because it only results in 1 if both inputs are 1.

            However, a carry doesn't stay in the same column where it was created. 
            it moves to the left. 
            That is why we use << 1. 
            This prepares the carries to be added to the next column in the next step.                      
               
*/

   
int add_numbers_without_plus_sign(void) {
   int num1, num2;

   printf("Enter two integers: ");
   if (scanf("%d %d", &num1, &num2) != 2) {
      return 1;
   }

   // Assigning original values to temporary variables to preserve num1 and num2
   int temp1 = num1;
   int temp2 = num2;

   while (temp2 != 0) {
      // Identify the carry bits
      unsigned int carry = (unsigned int)(temp1 & temp2);

      // Sum without carry using XOR
      temp1 = temp1 ^ temp2;

      // Shift carry to the left to be added in the next iteration
      temp2 = carry << 1;
   }

   // temp1 now holds the final sum
   printf("%d + %d = %d\n", num1, num2, temp1);
   return 0;
}

/*
   Subtraction two numbers -> num3=num1-num2;

   Subtraction using bitwise operators is a two-step mental jump: 
   first, you have to understand how to make a number negative without a minus sign, 
   and second, you use the addition logic we already built.

   1. The "Magic" of Two's Complement

   In binary systems, computers don't have a "negative" symbol. 
   Instead, they use a system called Two’s Complement. 
   To turn a positive number into its negative version, you:      
   Flip all the bits (Turn 1s to 0s and 0s to 1s).

   Add 1.
      For example, if you have the number 3, and you flip its bits and add 1, 
      the computer literally reads that new bit pattern as −3.

   2. Turning Subtraction into Addition
      Mathematically, 10−3 is exactly the same as 10+(−3).
      Because we already know how to "Add" using XOR and AND, we just apply that same logic to our negative number.
*/
#include <stdio.h>

int subtraction(void) {
   int num1, num2;

   printf("Enter two integers (num1 - num2): ");
   if (scanf("%d %d", &num1, &num2) != 2) {
      return 1;
   }

   int temp1 = num1;
   
   // Step 1 & 2: Turn num2 into its negative version (-num2)
   // We do this by calculating (~num2 + 1) bitwise.
   int negative_num2 = ~num2;
   int add_one = 1;
   
   // Small loop to add 1 to ~num2 without using '+'
   while (add_one != 0) {
      unsigned int carry = (unsigned int)(negative_num2 & add_one);
      negative_num2 = negative_num2 ^ add_one;
      add_one = carry << 1;
   }

   // Now we add num1 and negative_num2
   int temp2 = negative_num2;
   while (temp2 != 0) {
      unsigned int carry = (unsigned int)(temp1 & temp2);
      temp1 = temp1 ^ temp2;
      temp2 = carry << 1;
   }

   printf("%d - %d = %d\n", num1, num2, temp1);
   return 0;
}

/*
         multiplay (*) or divide (/)  

         //divide
         x    bin(10)  1010

              x>>1     0101 = 5(dec)

         x    bin(9)   1001
              x>>1     0100 = 4(dec)

         x/2 -> x>>1
         x/4 -> x>>2
         x/8 -> x>>3

         x/2^k -> x>>k


         //multiplay
         for exaple (3*2) (number^place) 2=2^1

         x   bin(3)   0011
         x<<1         0110  = 6(dec)       
*/ 

int divide_multiplay(void){
   int number=10;

   int number1 = 10;
   int number2 = 9;
   int number3 = 3;

   printf("--- Division Logic (Right Shift) ---\n");
   // number1 = 10 (bin: 1010)
   // number1 >> 1 = 5 (bin: 0101)
   printf("number1 (10) >> 1 = %d\n", number1 >> 1);

   // number2 = 9 (bin: 1001)
   // number2 >> 1 = 4 (bin: 0100) -> Note: 4.5 is floored to 4
   printf("number2 (9)  >> 1 = %d\n", number2 >> 1);

   // Formula: x / 2^k -> x >> k
   printf("number1 / 4 (10 >> 2) = %d\n", number1 >> 2);
   printf("number1 / 8 (10 >> 3) = %d\n", number1 >> 3);

   printf("\n--- Multiplication Logic (Left Shift) ---\n");
   // number3 = 3 (bin: 0011)
   // number3 << 1 = 6 (bin: 0110) -> (3 * 2^1)
   printf("number3 (3) << 1 = %d\n", number3 << 1);

   // Formula: x * 2^k -> x << k
   printf("number3 * 4 (3 << 2) = %d\n", number3 << 2);
   printf("number3 * 8 (3 << 3) = %d\n", number3 << 3);

   return 0;
}

/*
         using bitwise to module a number
         number % n=2 -> number%n^2
         number & ((1<<n)-1)

         for example : 10%4=2 , 10%2^2=2
         number=10
         n=2

         number & ((1<<n)-1)
         10 & (2^2-1) = 10 & (4-1) = 10 & 3
            
         bin(10)     1010
                      &
         bin(3).     0011
                     -----
                     0010 = 2(dec)
*/ 

int module(void) {
   int number = 10;
    int n = 2; // We want to find: number % (2^n)

    // 1. Calculate the divisor (2 to the power of n)
    // 1 << n is equivalent to 2^n
    int divisor = 1 << n; 

    // 2. Standard Modulo
    int standard_mod = number % divisor;

    // 3. Bitwise Modulo Logic
    // (1 << n) - 1 creates a bitmask of n ones
    int bitwise_mask = (1 << n) - 1;
    int bitwise_mod = number & bitwise_mask;

    // Output Results
    printf("Number: %d, n: %d (Divisor: %d)\n", number, n, divisor);
    printf("-------------------------------\n");
    printf("Standard Modulo (%d %% %d): %d\n", number, divisor, standard_mod);
    printf("Bitwise Modulo (%d & %d):  %d\n", number, bitwise_mask, bitwise_mod);
   return 0;
}


/*
      swapping two numbers without using temporary variable
      number1 = 2
      number2 = 5

      steps:
      number1=number1^number2 
               2(dec)  0010
                         ^ (xor)
               5(dec)  0101
                       ----
                       0111 = 7   -> number1=7, number2=5 
               
      number2=number1^number2
               7(dec)  0111
                        ^ (xor)
               5(dec)  0101
                       ----
                       0010 = 2   -> number1=7, number2=2 (we swap the second number)

      number1=number1^number2
               7(dec)  0111
                        ^
               2(dec)  0010
                       ----
                       0101 = 5.  -> number1=5, number2=2 (swap the first number)
*/

#include <stdio.h>

int swapping_two_numbers(void) {
   int number1 = 2;
   int number2 = 5;

   printf("Before swap: number1 = %d, number2 = %d\n", number1, number2);

   // Step 1: number1 becomes a combination of both
   number1 = number1 ^ number2; 

   // Step 2: number2 XORed with the combination results in the original number1
   number2 = number1 ^ number2; 

   // Step 3: number1 XORed with the new number2 results in the original number2
   number1 = number1 ^ number2; 

   printf("After swap:  number1 = %d, number2 = %d\n", number1, number2);

   return 0;
}


/*
      toggle a number by two givven number , entering num2 to num if num==num1 else num==num2
      num = num1^num2^num

      for example num1=5, num2=10, num=5;
            
            5(dec)  0101
                      ^
           10(dec)  1010
                    ----
                    1111
                      ^
                    0101
                    ----
                    1010 (got the second number)
*/

#include <stdio.h>

int toggle_numbers(void) {
   int num1, num2, num;

   // Input the two toggle boundaries
   printf("Enter two numbers to toggle between (e.g., 5 10): ");
   scanf("%d %d", &num1, &num2);

   // Initialize 'num' to one of the values
   num = num1;
   printf("\nStarting value: %d\n", num);

   // Toggle 1: Change num1 to num2
   num = num1 ^ num2 ^ num;
   printf("First toggle:  %d\n", num);

   // Toggle 2: Change num2 back to num1
   num = num1 ^ num2 ^ num;
   printf("Second toggle: %d\n", num);

   return 0;
}

/*
      count the set bit in a number:

      1. Removing the 1st bit:

         temp is 101101 (45).

         temp - 1 is 101100 (44).

         The & operation keeps only the bits where both are 1. 
         This clears the bit at the 20 position.

         New temp: 44.

      2. Removing the 2nd bit:
         temp is 101100 (44).
         temp - 1 is 101011 (43).

         The & operation clears the bit at the 22 position.

         New temp: 40.

      3. Removing the 3rd bit:
         temp is 101000 (40).
         temp - 1 is 100111 (39).
         Notice how temp - 1 flipped all bits to the right of the 23 position. The & operation clears that bit.

         New temp: 32.

      4. Removing the 4th bit:
         temp is 100000 (32).
         temp - 1 is 011111 (31).

         The only remaining bit is cleared.
         New temp: 0.
      
      we had 4 iteration so there are 4 bits up.
*/

int main(void) {
   int original = 45;      // Binary: 101101
   int temp = original;    // Create a copy to manipulate
   int count = 0;

   while (temp > 0) {
      temp &= (temp - 1); // Clears the lowest set bit
      count++;
   }

   printf("Original variable: %d\n", original);
   printf("Number of set bits: %d\n", count);
   return 0;
}