#include <stdio.h>

// Function to count the number of set bits in a number
int countSetBits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;  // Check if the least significant bit is set
        num >>= 1;        // Right-shift the number to move to the next bit
    }
    return count;
}

// Function to calculate the total number of set bits in an array
int totalSetBits(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += countSetBits(arr[i]);
    }
    return total;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int totalBits = totalSetBits(arr, size);
    printf("The total number of set bits in the array is: %d\n", totalBits);

    return 0;
}
