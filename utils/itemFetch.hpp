#ifndef F_ITEM_FETCH
#define F_ITEM_FETCH

#include <string>

typedef struct item{
    std::string itemRarity;
    std::string itemName;
    std::string imageDirectLink;
    std::string levelRequirement;
    bool isGoodShit;
    std::string itemComments;
} Item;

Item itemAttributesFetch();
void prompt(std::string);

#endif