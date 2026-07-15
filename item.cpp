#include "item.h"

Item::Item(string itemName, string itemType)
{
    name = itemName;
    type = itemType;
}


string Item::getName()
{
    return name;
}


string Item::getType()
{
    return type;
}