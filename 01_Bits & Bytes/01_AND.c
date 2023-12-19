#include <stdio.h>

int bitwiseAND(int a, int b) {
    return a & b;
}

int main() {

    int num1 = 12;   // Binary: 1100
    int num2 = 25;   // Binary: 11001

    int result = bitwiseAND(num1, num2); // 12 & 25 -> 1100 & 11001

    
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, result);

    return 0;
}

// & =>

// 1 & 1 -> 1
// 1 & 0 -> 0
// 0 & 1 -> 0
// 0 & 0 -> 0


// 12 -> 01100
// 15 -> 11001
// &  -> 01000 -> 8 (Output)
