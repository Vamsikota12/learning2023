#include <stdio.h>

void findSmallestLargestDigits(int n, ...) {
    int smallestDigit = 9;
    int largestDigit = 0;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        int tempNum = num;

        while (tempNum != 0) {
            int digit = tempNum % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            tempNum /= 10;
        }
    }

    va_end(args);

    if (smallestDigit == largestDigit) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallestDigit);
        printf("Largest digit: %d\n", largestDigit);
    }
}

int main() {
    findSmallestLargestDigits(3, 8, 156, 123450);

    return 0;
}
