#pragma once
#include <vector>
#include <string>
using namespace std;

class DataBase
{
public:
	vector<vector<string>> Read_Database(string _fileName);
	vector<vector<string>>& getData();

private:
	vector<vector<string>> storage;
};

