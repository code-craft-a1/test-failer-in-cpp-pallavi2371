#include "gtest/gtest.h"

// Declarations for the test functions implemented in other files
void testTshirtSize();
void testPrintColorMap();
void testWeatherReport();

// Unit test for T-shirt size functionality
TEST(TShirt, Size) {
    testTshirtSize();
}

// Unit test for color map printing
TEST(ColorMap, Print) {
    testPrintColorMap();
}

// Unit test for weather report logic
TEST(WeatherReport, Report) {
    testWeatherReport();
}