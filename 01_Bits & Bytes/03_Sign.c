#include <stdio.h>

int checkSign(int num) {

    if(num==0)return 0;
    // Right shift the sign bit to the rightmost bit
    int signBit = (num >> (sizeof(int) * 8 - 1)) & 1;

    return (signBit ^ 1) - signBit;
    // If signBit => 1 -> Number -> Negative
    // If signBit => 0 -> Number -> Positive
    // If signBit => 0 -> Number -> Zero
}

int main() {
    int num1 = 10;  // Positive
    int num2 = 0;   // Zero
    int num3 = -5;  // Negative

    printf("Sign of %d: %d\n", num1, checkSign(num1));
    printf("Sign of %d: %d\n", num2, checkSign(num2));
    printf("Sign of %d: %d\n", num3, checkSign(num3));

    return 0;
}
