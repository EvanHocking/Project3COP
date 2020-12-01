#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Item
{
public:
    int aisleNum;
    string itemName;
    string itemCategory;

    Item(int aisle, string name, string category)
    {
        aisleNum = aisle;
        itemName = name;
        itemCategory = category;
    }
}

class GroceryMap
{
private:
    map<int, vector<Item>> grocery;
public:
    void addEdge(int aisle, string name, string category);
}

void GroceryMap::addEdge(int aisle, string name, string category)
{
    Item newItem = new Item(aisle,name,category);
    grocery[aisle].push_back(newItem);
}


void GroceryMap::organizeList()
{
    for(int i = 0; i < randomList.size; i++)
    {
        //search in each aisle and each category to find item,
        //create a new map of the new items and each aisle
        //return map
    }
}
