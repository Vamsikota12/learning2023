#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31;  // Start with the most significant bit

    for (i = 0; i < 32; i++) {
        // Print 1 if the corresponding bit is set, otherwise print 0
        printf("%d", (num & mask) ? 1 : 0);

        // Shift the mask to the right by 1 bit
        mask >>= 1;
    }

    printf("\n");
}

int main() {
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
