#include <iostream>
#include <string>

#include "utils/itemFetch.hpp"
#include "utils/output.hpp"

int main(){
    std::cout << "This is some Flammunist shit that won't work. Blame Flamm should things not work." << std::endl;
    std::string k = "1";
    int itemAmount = 0;
    while(k == "1"){
        if(itemAmount == 0)
            std::cout << "[LOG] Fetching another item..." << std::endl;
        
        Item i = itemAttributesFetch();
        doOutput(i);

        std::cout << "Type '1' to add another item, anything (LITERALLY ANYTHING) else to exit: ";
        std::getline(std::cin >> std::ws, k);
    }
}