#include <iostream>
#include <string>
#include <algorithm>

#include "itemFetch.hpp"

void prompt(std::string message){
    std::cout << message;
}

std::string fetchUntilNotEmpty(std::string message){
    std::string input;

    prompt("\t" + message);
    std::getline(std::cin, input);

    while(input.length() == 0){
        std::cout << "[ERROR] Empty line!" << std::endl;
        prompt("\t" + message);
        std::getline(std::cin, input);
    }

    return input;
}

Item itemAttributesFetch(){
    Item i;
    
    std::cout << "[LOG] Fetching item's attributes" << std::endl;

    // Talk about being stupid!
    std::string hasComments;
    std::string isGoodShit;

    i.itemRarity = fetchUntilNotEmpty("- Rarity: ");
    i.itemName = fetchUntilNotEmpty("- Name: ");
    i.levelRequirement = fetchUntilNotEmpty("- Level requirement: ");
    i.imageDirectLink = fetchUntilNotEmpty("- Direct link to image: ");
    hasComments = fetchUntilNotEmpty("- Do you wish to add comments (Y/N)? ");
    std::transform(hasComments.begin(), hasComments.end(), hasComments.begin(), ::tolower);

    if(hasComments == "yes" || hasComments == "y")
        i.itemComments = fetchUntilNotEmpty("- Additional comments: ");
    else
        i.itemComments = "NULL";

    isGoodShit = fetchUntilNotEmpty("- Is item [GOOD SHIT] (Y/N)? ");
    std::transform(isGoodShit.begin(), isGoodShit.end(), isGoodShit.begin(), ::tolower);
    
    if(isGoodShit == "y" || isGoodShit == "yes")
        i.isGoodShit = true;
    else
        i.isGoodShit = false;

    std::transform(i.itemRarity.begin(), i.itemRarity.end(), i.itemRarity.begin(), ::tolower);
    std::cout << "[LOG] Item's attributes fetched successfully!" << std::endl;

    return i;
}