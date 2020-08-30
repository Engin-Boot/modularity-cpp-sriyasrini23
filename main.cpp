#include <iostream>
#include <assert.h>
#include "namespace.h"
#include "namespace2.h"

void ToString()
{   int majorcolorindex = 0; int minorcolorindex = 0;
    std::string colors = "";
    for(int i = 0; i<25 ; i++)
    {   minorcolorindex = (i%TelCoColorCoder::numberOfMinorColors);
        majorcolorindex = (i/TelCoColorCoder::numberOfMajorColors);
        colors +=  (std::string)(i)+" "+(std::string)(TelCoColorCoder::MajorColorNames[majorcolorindex])+" "+                  
                  (std::string)(TelCoColorCoder::MinorColorNames[minorcolorindex])+"\n";
    }
    std::cout << colors << std::endl;
}
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}
void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    ToString();
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    return 0;
}
