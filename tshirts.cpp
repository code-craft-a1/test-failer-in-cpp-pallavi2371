#include <iostream>
#include <assert.h>

// Returns the size category based on the chest measurement in centimeters
char size(int cms) {
    if (cms <= 38) {
        return 'S';  // Small
    } else if (cms <= 42) {
        return 'M';  // Medium
    } else {
        return 'L';  // Large
    }
}

// Test cases for the size function
void testTshirtSize() {
    std::cout << "\nTshirt size test\n";

    assert(size(37) == 'S'); // Edge case: under lower limit
    assert(size(38) == 'S'); // Boundary condition for 'S'
    assert(size(40) == 'M'); // Normal case for 'M'
    assert(size(42) == 'M'); // Boundary condition for 'M'
    assert(size(43) == 'L'); // Case above 'M'

    std::cout << "All is well (maybe!)\n";
}
