#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    // Convert the number to an array of digits
    int digits[4];
    digits[0] = num / 1000;         // thousands place
    digits[1] = (num / 100) % 10;   // hundreds place
    digits[2] = (num / 10) % 10;    // tens place
    digits[3] = num % 10;           // ones place

    // Loop through each digit and find the largest number by deleting it
    for (int i = 0; i < 4; i++) {
        int currentNum = 0;
        
        // Construct the number by excluding the current digit
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                currentNum = currentNum * 10 + digits[j];
            }
        }
        
        // Update the largest number if necessary
        if (currentNum > largest) {
            largest = currentNum;
        }
    }
    
    return largest;
}

int main() {
    int number = 5872;
    int largestNumber = findLargestNumber(number);
    printf("Largest number by deleting a single digit from %d: %d\n", number, largestNumber);
    
    number = 9856;
    largestNumber = findLargestNumber(number);
    printf("Largest number by deleting a single digit from %d: %d\n", number, largestNumber);
    
    return 0;
}
