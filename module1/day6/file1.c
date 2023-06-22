#include <stdio.h>

// Define the structure for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of a box
double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

// Function to calculate the total surface area of a box
double calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width +
                boxPtr->length * boxPtr->height +
                boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox;  // Create an instance of the Box structure
    struct Box* boxPtr = &myBox;  // Create a pointer to the Box structure and assign the address of myBox to it
    
    // Assign values to the members of the box using the structure pointer
    boxPtr->length = 5.0;
    boxPtr->width = 3.0;
    boxPtr->height = 2.0;
    
    // Calculate the volume and surface area using the structure pointer
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
    
    return 0;
}

