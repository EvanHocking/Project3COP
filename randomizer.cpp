#include <vector>
#include <string>
#include <time.h>
using namespace std;

// data base structure, randomized list size, seeded?, seed number
vector<vector<string>> randomizeList(vector<vector<string>>& _dataBase, int _listSize, bool _isSeeded, unsigned int _seed)
{
	vector<vector<string>> list;

	//Set the seed if needed
	if(_isSeeded)		
		srand(_seed); 
	else				
		srand((unsigned)time(0)); 

	for (int i = 0; i < _listSize; i++)
	{
		//generates a random number with a upperlimit of the size of the data base
		//using the random number, index list and add it to randomized list
		int randomNumber = rand() % _dataBase.size();		
		list.push_back(_dataBase.at(randomNumber));			
	}

	return list;
}