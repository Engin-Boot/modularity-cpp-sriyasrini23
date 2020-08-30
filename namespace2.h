#pragma once

namespace TelCoColorCoder
{
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
    
        ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
        }
        int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
        }
}
