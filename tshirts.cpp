#include <iostream>
#include <assert.h>

// Class to encapsulate logic for determining t-shirt size
class TShirtSizer {
public:
    static char GetSize(int cms) {
        if (cms <= 38) return 'S';
        if (cms <= 42) return 'M';
        return 'L';
    }
};

// Tests for size classification
void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    assert(TShirtSizer::GetSize(37) == 'S');
    assert(TShirtSizer::GetSize(38) == 'S');
    assert(TShirtSizer::GetSize(40) == 'M');
    assert(TShirtSizer::GetSize(42) == 'M');
    assert(TShirtSizer::GetSize(43) == 'L');
    std::cout << "All is well (maybe!)\n";
}
