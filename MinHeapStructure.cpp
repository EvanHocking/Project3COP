//Plan is to implement a min heap that stores each item in the aisle 
//that corresponds to it and then print all of the aisles in order
//in the Database: B sores the brand and D stores the description
//E stores the aisle
//so given a vector of vectors is the list of items and each vector
//contains all five pieces of data, we sort the list based on the aisle number
//so create nodes that have all three pieces of data we need
//ie A, C and D

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <string> 
using namespace std;

//the function to read the database
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

	while (file >> temp) {

		row.clear();
		//read a row
		getline(file, line);
		stringstream s(line);
		//read column data and store in word
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		storage.push_back(row);

	}
	return storage;
}


//so the original list is stored in vector<vector<string>>
//and there are 15 aisles
//we know the amount of items in the list -> size
//this function take in a vector<vector<string>> which is the generagted list
//a pointer to the array for the heap
int theHeap[];
//a pointer to the array for the corresponding heap which has the data
vector<vector<string>> theHeap2[];

void makeHeap(int size, vector<vector<string>> list, int* theHeap, vector<vector<string>>* theHeap2) {
	for (int i = 0; i < size; i++) {
		int input = stoi(vector[i][3]);//which will change the aisle data string to number
		//making the vector of data from the list
		vector<string> temp;
		temp.push_back(list[i][0]); //the brand name
		temp.push_back(list[i][2]); //the food item
		if (theHeap[].size() > 0) { //if arr is nonempty we have to see if input is already in the array
			for (int j = 0; j < theHeap[].size(); j++) {
				if (theHeap[j] == input) {
					//if the aisle is already in the heap then we
					//add the temp vector to Heap2
					theHeap2[j].push_back(temp);
					temp.clear();
				}
				else {
					if (j == theHeap[].size()) {
						//if aisle already not in heap we add to heap
						//then add corresponding data (temp vector)
						//into heap2
						theHeap[i] = input;
						theHeap2[i].push_back(temp);
						temp.clear();
					}
				}
			}
		}
	}
}

//now we have an array of the aisle numbers and an array
//that has the data of the items of the list at each aisle
//aka for ex heap[0] = aisle 3
//then heap2[0] will have all the things in aisle 3
//now we need heapify the heap and heap2 to create min heap
//and thus optimized route from start to finish of store
void heapify(int* theHeap, vector<vector<string>>* theHeap2, int n, int size) {
	int largest = size;
	int l = 2 * size + 1;
	int r = 2 * size + 2;

	if (l < n && theHeap[l] > theHeap[largest]) {
		largest = l;
	}
	if (r < n && theHeap[r] > theHeap[largest]) {
		largest = r;
	}

	if (largest != size) {
		int temp = theHeap[size];
		vector<vector<string>> tempVec = theHeap2[size];
		theHeap[size] = theHeap[largest];
		theHeap2[size] = theHeap2[largest];
		theHeap[largest] = temp;
		theHeap2[largest] = tempVec;

		heapify(theHeap, theHeap2, n, largest);
	}
}

void printHeap(int* theHeap, vector<vector<string>>* theHeap2) {
	for (int i = 0; i < theHeap.size(); i++) {
		cout << "==========	AISLE " << theHeap[i] << "	==========" << endl;
		for (int j = 0; j < theHeap2[i].size(); j++) {
			cout << theHeap2[i][j][0] << "	|	" << theHeap2[i][j][2] << endl;
		}
	}
}


int main() {
	vector<vector<string>> list = Read_Database();
	makeHeap(list.size(), list, theHeap, theHeap2);
	heapify(theHeap, theHeap2, theHeap.size(), theHeap.size());
	printHeap(theHeap, theHeap2);
	return 0;
}
