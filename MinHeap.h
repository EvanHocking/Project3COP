#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <string> 
using namespace std;

class MinHeap {
public:

	//a vector storing the heap
	vector<int> theHeap;
	//a vector storing corresponding heap which has the data
	vector<vector<vector<string>>> theHeap2;

	void makeHeap(int size, vector<vector<string>> list, vector<int>& theHeap, vector<vector<vector<string>>>& theHeap2);
	void heapify(vector<int>& theHeap, vector<vector<vector<string>>>& theHeap2);
	void printHeap(vector<int> theHeap, vector<vector<vector<string>>> theHeap2);
	void clear();
};
