#include <iostream>
#include <fstream>
#include <string>

#include "itemFetch.hpp"
#include "output.hpp"

ColorStruct setColors(){
    ColorStruct cs;

    cs.colorUnique = "e9ff00";
    cs.colorSet = "00ff00";
    cs.colorRare = "ff0080";
    cs.colorLegendary = "00b3b3";
    cs.colorMythic = "660066";

    cs.colorComments = "000000";
    cs.colorGoodShit = "ff00000";

    return cs;
}

std::string returnColor(ColorStruct cs, std::string itemRarity){
    if(itemRarity == "u" || itemRarity == "unique"){
        return cs.colorUnique;
    } else if(itemRarity == "s" || itemRarity == "set"){
        return cs.colorSet;
    } else if(itemRarity == "r" || itemRarity == "rare" || itemRarity == "rawr"){
        return cs.colorRare;
    } else if(itemRarity == "l" || itemRarity == "leg" || itemRarity == "legendary"){
        return cs.colorLegendary;
    } else if(itemRarity == "m" || itemRarity == "mythic"){
        return cs.colorMythic;
    } else {
        // Failsafe: return default color should things go wrong (black)
        return "000000";
    }
}

void doOutput(Item i){
    std::cout << "[LOG] Writing item output..." << std::endl;

    // Sets the colors used
    ColorStruct cs = setColors();

    // Opening file
    std::ofstream outputFile;
    outputFile.open("Output_BBCode.txt");

    // Effectively 
    outputFile << "[URL='" << i.imageDirectLink << "'][COLOR=#" << returnColor(cs, i.itemRarity) << "]" << i.itemName << " (Lvl. " << i.levelRequirement << ")[/COLOR]";

    // Checks whether item has comments
    if(i.itemComments != "NULL"){
        outputFile << "[COLOR=#" << cs.colorComments << "]" << i.itemComments << "[/COLOR]";
    }
    
    // Checks whether item is good shit or not
    if(i.isGoodShit){
        outputFile << "[COLOR=#" << cs.colorGoodShit << "][GOOD SHIT]" << "[/COLOR]";
    }

    outputFile << "[/URL]" << std::endl;

    std::cout << "[LOG] BBCode for " << i.itemName << " has been output successfully." << std::endl;
}