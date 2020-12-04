// Final Project COP3530
/*
===CONTRIBUTORS===
	Evan Hocking
	Toni Earle
	Katrina Beaucage

===DESCRIPTION===
TODO: make a description of the program
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <random>
#include "DataBase.h"
#include "GroceryMap.h"

#undef RAND_MAX 
#define RAND_MAX 400,000


using namespace std;

void clearScreen();
void displayList(vector<vector<string>> _randomList);
vector<vector<string>> randomizeList(vector<vector<string>>& _dataBase, int _listSize, bool _isSeeded, unsigned int _seed);

int main()
{
	//Primatives
	int menuSelect = 0;
	int seed = 0;
	int listSize = 0;
	bool isSeeded = false;
	bool exitFlag = true;

	//Objects
	DataBase data;
	GroceryMap map;
	vector<vector<string>> randomList;

	data.Read_Database("newDatabase.csv");
	randomList = randomizeList(data.getData(), 10, isSeeded, seed);

	while (exitFlag)
	{
		cout << "=== Menu ===" << endl
			<< "| 1. Generate a random list" << endl
			<< "| 2. Display Random List" << endl
			<< "| 3. Save Random List" << endl
			<< "| 4. Load Random List" << endl
			<< "| 5. Optimize List (Map)" << endl
			<< "| 6. Optimize List (Heap)" << endl
			<< "| 7. Set Seed" << endl
			<< "| 8. Exit" << endl
			<< "====================" << endl;


		cout << "Select an option: ";
		cin >> menuSelect;

		clearScreen();

		switch (menuSelect)
		{
			case 1:
				cout << "Enter the list size: ";
				cin >> listSize;
				randomList = randomizeList(data.getData(), listSize, isSeeded, seed);
				cout << "Random List Generated!" << endl;
				if (isSeeded)
					cout << "Using seed: " << seed << endl;
				break;
			case 2:
				displayList(randomList);
				break;
			case 3:
				//Save to txt
			case 4:
				//Load from txt
			case 5:
				//Map Org.
				for (int i = 0; i < randomList.size(); i++)
					map.addEdge(stoi(randomList.at(i).at(3)), randomList.at(i).at(2), randomList.at(i).at(1), randomList.at(i).at(0));
				map.organizeList();
				break;
			case 6:
				//Heap Org.
			case 7:
				cout << "Enter an unsigned integer, or a -1 to not use a seed." << endl
					<< "Seed: ";
				cin >> seed;
				if (seed == -1)
					isSeeded = false;
				else
					isSeeded = true;
				break;
			case 8:
				exitFlag = false;
				break;
		}
	}

	return 0;
}

void clearScreen() { cout << "\x1B[2J\x1B[H"; }
vector<vector<string>> randomizeList(vector<vector<string>>& _dataBase, int _listSize, bool _isSeeded, unsigned int _seed)
{
	vector<vector<string>> list;
	set<string> itemTracker;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, _dataBase.size()); //set the range of number generation

	//Set the seed if needed
	if (_isSeeded)
		srand(_seed);
	else
		srand((unsigned)time(0));

	for (int i = 0; i < _listSize; i++)
	{
		//generates a random number with a upperlimit of the size of the data base
		//using the random number, index list and add it to randomized list
		int randomNumber = distribution(generator);
		if (itemTracker.find(_dataBase.at(i).at(2)) == itemTracker.end())
		{
			list.push_back(_dataBase.at(randomNumber));
			itemTracker.insert(_dataBase.at(i).at(2));
		}
			
	}

	return list;
}
void displayList(vector<vector<string>> _randomList)
{
	//Prints out the random list! (format)
	//========== Random List ==========
	//brand name   |   item name

	cout << "========== Random List ==========" << endl;
	for (int i = 0; i < _randomList.size(); i++)
		cout<< _randomList.at(i).at(0) << " | " << _randomList.at(i).at(2) << endl;
}