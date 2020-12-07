#include "GroceryMap.h"

void GroceryMap::addEdge(int aisle, string name, string category, string brand)
{
	Item* newItem = new Item(aisle, name, category, brand);
	grocery[aisle].push_back(newItem);
}

void GroceryMap::organizeList()
{
    //organize and print list in format:
    // Optimized List: Map
    //========== AISLE 1 ==========
    //brand name   |   item name
    cout << "Optimized List: MAP" << endl;
    for (map<int, vector<Item*>>::iterator it = grocery.begin(); it != grocery.end(); ++it)
    {
        cout << "========== AISLE " << it->first << " ==========" << endl;
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i]->brandName << " | " << it->second[i]->itemName << endl;
        }
    }
}

void GroceryMap::clear()
{
    grocery.clear();
}
