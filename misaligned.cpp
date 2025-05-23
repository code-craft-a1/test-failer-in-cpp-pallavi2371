#include <iostream>
#include <assert.h>

// Returns a unique color code based on major and minor indices
int colorCount(int major, int minor) {
    return (major * 5 + minor);
}

// Prints the color map and returns the total number of combinations
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    int totalCombinations = 0;

    // Loop through all combinations of major and minor colors
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << colorCount(i, j) << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
            totalCombinations++;
        }
    }

    return totalCombinations;
}

// Test the color map logic
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    
    int result = printColorMap();

    // Check if the color count and result are as expected
    assert(colorCount(0, 0) == 0);
    assert(result == 25);

    std::cout << "All is well (maybe!)\n";
}