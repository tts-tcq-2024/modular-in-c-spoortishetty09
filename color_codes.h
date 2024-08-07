#ifndef COLOR_CODES_H
#define COLOR_CODES_H

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void PrintColorCodingReference();

#define MAX_COLORPAIR_NAME_CHARS 16  // Added constant definition

#endif // COLOR_CODES_H
