#pragma once
namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor, MinorColor);
            MajorColor getMajor();
            MinorColor getMinor();
            std::string ToString();
    };

          ColorPair::ColorPair(MajorColor major, MinorColor minor):
          majorColor(major), minorColor(minor)
          {}
          MajorColor ColorPair::getMajor() {
                return majorColor;
          }
          MinorColor ColorPair::getMinor() {
                return minorColor;
            }
          std::string ColorPair::ToString() {
                std::string colorPairStr = MajorColorNames[majorColor];
                colorPairStr += " ";
                colorPairStr += MinorColorNames[minorColor];
                return colorPairStr;
            }

}
