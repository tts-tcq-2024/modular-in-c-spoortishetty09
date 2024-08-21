#include <stdio.h>
#include "Color_Code.h"

// Enum arrays
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

// Convert ColorPair to a string
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

// Convert pair number to ColorPair
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

// Convert ColorPair to pair number
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

// Print color coding mapping as a reference manual
void printColorCodingManual() {
    printf("Color Coding Reference Manual\n");
    printf("-----------------------------\n");
    printf("| Pair Number | Major Color | Minor Color |\n");
    printf("|-------------|-------------|-------------|\n");

    for (int major = 0; major < numberOfMajorColors; ++major) {
        for (int minor = 0; minor < numberOfMinorColors; ++minor) {
            ColorPair colorPair = { (enum MajorColor)major, (enum MinorColor)minor };
            int pairNumber = GetPairNumberFromColor(&colorPair);
            printf("| %11d | %11s | %11s |\n", pairNumber,
                   MajorColorNames[colorPair.majorColor],
                   MinorColorNames[colorPair.minorColor]);
        }
    }

    printf("-----------------------------\n");
}
