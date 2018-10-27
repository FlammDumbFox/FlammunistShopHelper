#include <iostream>
#include <fstream>
#include <string>

#include "itemFetch.hpp"
#include "output.hpp"

ColorStruct setColors(){
    ColorStruct cs;

    cs.colorUnique = "";
    cs.colorSet = "00ff00";
    cs.colorRare = "ff0080";
    cs.colorLegendary = "00b3b3";
    cs.colorMythic = "";

    cs.colorComments = "000000";
    cs.colorGoodShit = "ff00000";
}

void doOutput(Item i){
    std::ofstream outputFile;
    outputFile.open("Output_BBCode.txt");
    
}