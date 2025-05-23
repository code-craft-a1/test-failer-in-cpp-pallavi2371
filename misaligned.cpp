#include <iostream>
#include <assert.h>
#include <string>

// Represents a color pair of major and minor colors
class ColorPair {
public:
    ColorPair(int majorIndex, int minorIndex)
        : majorIndex(majorIndex), minorIndex(minorIndex) {}

    std::string ToString() const {
        return std::to_string(GetPairNumber()) + " | " + majorColors[majorIndex] + " | " + minorColors[minorIndex];
    }

    static int GetPairNumber(int major, int minor) {
        return major * minorColorCount + minor;
    }

    int GetPairNumber() const {
        return GetPairNumber(majorIndex, minorIndex);
    }

    static int PrintAllPairs() {
        int totalPairs = 0;
        for (int i = 0; i < majorColorCount; ++i) {
            for (int j = 0; j < minorColorCount; ++j) {
                ColorPair pair(i, j);
                std::cout << pair.ToString() << "\n";
                ++totalPairs;
            }
        }
        return totalPairs;
    }

private:
    int majorIndex;
    int minorIndex;

    static constexpr const char* majorColors[5] = {"White", "Red", "Black", "Yellow", "Violet"};
    static constexpr const char* minorColors[5] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    static constexpr int majorColorCount = 5;
    static constexpr int minorColorCount = 5;
};

// Entry-point test
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    int result = ColorPair::PrintAllPairs();
    assert(ColorPair::GetPairNumber(0, 0) == 0);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}