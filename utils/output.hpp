#ifndef F_OUTPUT
#define F_OUTPUT

#include <string>

typedef struct colorStruct{
    // Rarities
    std::string colorUnique;
    std::string colorSet;
    std::string colorRare;
    std::string colorLegendary;
    std::string colorMythic;

    // Miscelaneous colors
    std::string colorComments;
    std::string colorGoodShit;
} ColorStruct;

ColorStruct setColors();

#endif