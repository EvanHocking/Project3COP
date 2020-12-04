#pragma once
#include <string>
using namespace std;

class Item
{
public:

    int aisleNum;
    string itemName;
    string itemCategory;
    string brandName;

    Item(int aisle, string name, string category, string brand);
};

