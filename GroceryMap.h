#pragma once
#include "Item.h"
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class GroceryMap
{
private:
    map<int, vector<Item*>> grocery;
public:
    void addEdge(int aisle, string name, string category, string brand);
    void organizeList();
};

