#include "DataBase.h"
#include <fstream>
#include <sstream>

vector<vector<string>> DataBase::Read_Database(string _fileName)
{
	//File pointer
	fstream file;

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

vector<vector<string>>& DataBase::getData()
{
	return storage;
}
