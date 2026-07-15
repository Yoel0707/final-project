#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item {

private:

    string name;
    string type;

public:

    Item(string itemName, string itemType);

    string getName();
    string getType();

};

#endif