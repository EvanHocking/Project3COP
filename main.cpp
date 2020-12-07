// Final Project COP3530
/*
===CONTRIBUTORS===
	Evan Hocking
	Toni Earle
	Katrina Beaucage

===DESCRIPTION===
Simulates a grocery list and then organizes them into aisles according to
arbritrary catagorization. This is a simulated approach to the problem, given
that we could not get access to a grocery store database. Download the database
CSV file here

Database: https://drive.google.com/file/d/1l-DkWtg8r0ISoMBtF0Yt33K6ZwLzqk_E/view?usp=sharing
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
#include "MinHeap.h"

using namespace std;

void clearScreen();
void displayList(vector<vector<string>> _randomList);
vector<vector<string>> randomizeList(vector<vector<string>>& _dataBase, int _listSize, bool _isSeeded, unsigned int _seed);
vector<vector<string>> Read_Database(string _fileName);
void saveList(string _fileName, vector<vector<string>> _list);

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
	MinHeap heap;
	vector<vector<string>> randomList;
	string fileName;

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
				cout << "Please enter a list name to save: ";
				cin >> fileName;
				saveList(fileName, randomList);
				break;
			case 4:
				//Load from txt
				cout << "Please enter a list name to load: ";
				cin >> fileName;
				randomList = Read_Database(fileName + ".txt");
				cout << "Completed: Loaded list from file" << endl;
				break;
			case 5:
				//Map Org.
				map.clear();
				for (int i = 0; i < randomList.size(); i++)
					map.addEdge(stoi(randomList.at(i).at(3)), randomList.at(i).at(2), randomList.at(i).at(1), randomList.at(i).at(0));
				map.organizeList();
				break;
			case 6:
				//Heap Org.
				cout << "Optimized List: MINHEAP" << endl;
				heap.makeHeap(randomList.size(), randomList, heap.theHeap, heap.theHeap2);
				heap.heapify(heap.theHeap, heap.theHeap2);
				heap.printHeap(heap.theHeap, heap.theHeap2);
				break;
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
		generator.seed(_seed);
	else
		generator.seed((unsigned)time(0));

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
void saveList(string _fileName, vector<vector<string>> list)
{
	ofstream dataStream (_fileName + ".txt");
	for (int i = 0; i < list.size(); i++)
	{
		dataStream << list.at(i).at(0) << '\t'
			<< list.at(i).at(1) << '\t'
			<< list.at(i).at(2) << '\t'
			<< list.at(i).at(3) << '\t' << '\n';
	}
	dataStream.close();
}
vector<vector<string>> Read_Database(string _fileName)
{
	//File pointer
	fstream file;
	vector<vector<string>> storage;

	//open existing file
	//just note the name of the file has to be database
	file.open(_fileName, ios::in);

	//read data from file
	//store it in a vector of vectors
	vector<string> row;

	string line, word, temp;

	while (getline(file, temp, '\n')) {

		row.clear();
		//read a row
		stringstream s(temp);
		//read column data and store in word
		while (getline(s, word, '\t')) {
			row.push_back(word);
		}
		storage.push_back(row);

	}

	//cout << "WE DID THE STORE" << endl;
	return storage;
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
