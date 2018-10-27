#include <iostream>
#include <string>
#include <algorithm>

#include "itemFetch.hpp"

void prompt(std::string message){
    std::cout << message;
}

Item itemAttributesFetch(){
    Item i;
    
    // Talk about being stupid!
    std::string hasComments;
    std::string isGoodShit;

    prompt("\t- Item's rarity: ");
    std::getline(std::cin >> std::ws, i.itemRarity);
    // Transforms given item rarity to lower case for simplicity
    std::transform(i.itemRarity.begin(), i.itemRarity.end(), i.itemRarity.begin(), ::tolower);

    prompt("\t- Item's name: ");
    std::getline(std::cin >> std::ws, i.itemName);

    prompt("\t- Direct link to image: ");
    std::getline(std::cin >> std::ws, i.imageDirectLink);
    
    prompt("\t- Item's level requirement: ");
    std::getline(std::cin >> std::ws, i.levelRequirement);

    prompt("\t- Item name: ");
    std::getline(std::cin >> std::ws, i.itemName);

    prompt("\t- Do you wish to add comments (Y/N)? ");
    std::getline(std::cin >> std::ws, hasComments);

    // Transform "hasComments" to lower case
    std::transform(hasComments.begin(), hasComments.end(), hasComments.begin(), ::tolower);
    
    if(hasComments == "yes" || hasComments == "y"){
        prompt("\t- Additional comments: ");
        std::getline(std::cin >> std::ws, i.itemComments);
    } else {
        i.itemComments = "NULL";
    }

    prompt("\t- Is item [GOOD SHIT] (Y/N)? ");
    std::getline(std::cin >> std::ws, isGoodShit);
    std::transform(isGoodShit.begin(), isGoodShit.end(), isGoodShit.begin(), ::tolower);

    if(isGoodShit == "y" || isGoodShit == "yes")
        i.isGoodShit = true;
    else
        i.isGoodShit = false;

    return i;
}