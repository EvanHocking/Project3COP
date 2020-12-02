#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> Read_Database() {
	//File pointer
	fstream file;

	//open existing file
	//just note the name of the file has to be database
	file.open("DatabasePseudo.csv", ios::in);

	//read data from file
	//store it in a vector of vectors
	vector<vector<string>> storage;
	vector<string> row;

	string line, word, temp;

	while (getline(file, temp, '\n')) {

		row.clear();
		//read a row
		stringstream s(temp);
		//read column data and store in word
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		storage.push_back(row);

	}

	//cout << "WE DID THE STORE" << endl;
	return storage;
}