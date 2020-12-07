#include "MinHeap.h"

//this function take in a vector<vector<string>> which is the generagted list
void MinHeap::makeHeap(int size, vector<vector<string>> list, vector<int>& theHeap, vector<vector<vector<string>>>& theHeap2) {
	for (int i = 1; i < size; i++) {
		int input = stoi(list[i][3]);//which will change the aisle data string to number
		//making the vector of data from the list
		vector<string> temp;
		vector<vector<string>> out;
		temp.push_back(list[i][0]); //the brand name
		temp.push_back(list[i][2]); //the food item
		 //if arr is nonempty we have to see if input is already in the array
		if (theHeap.size() > 0) {
			for (int j = 0; j < theHeap.size(); j++) {
				if (theHeap[j] == input) {
					//if the aisle is already in the heap then we
					//add the temp vector to Heap2
					theHeap2[j].push_back(temp);
					temp.clear();
					break;
				}
				else {
					if (j == theHeap.size() - 1) {
						//if aisle already not in heap we add to heap
						//then add corresponding data (temp vector)
						//into heap2
						theHeap.push_back(input);
						out.push_back(temp);
						theHeap2.push_back(out);
						temp.clear();
						out.clear();
						break;
					}
				}
			}
		}
		else {
			//if aisle already not in heap we add to heap
			//then add corresponding data (temp vector)
			//into heap2
			theHeap.push_back(input);
			out.push_back(temp);
			theHeap2.push_back(out);
			out.clear();
			temp.clear();
		}
	}
}

void MinHeap::heapify(vector<int>& theHeap, vector<vector<vector<string>>>& theHeap2) {
	int first;
	for (int i = 0; i < theHeap.size(); i++) {
		first = i;
		for (int j = i + 1; j < theHeap.size(); j++) {
			if (theHeap[first] < theHeap[j]) {
				first = j;
			}
		}
		int temp = theHeap[first];
		vector<vector<string>> tempVec = theHeap2[first];
		theHeap[first] = theHeap[i];
		theHeap2[first] = theHeap2[i];
		theHeap[i] = temp;
		theHeap2[i] = tempVec;
	}
}

void MinHeap::printHeap(vector<int> theHeap, vector<vector<vector<string>>> theHeap2) {
	for (int i = theHeap.size() - 1; i >= 0; i--) {
		cout << "========== AISLE " << theHeap[i] << " ==========" << endl;
		for (int j = 0; j < theHeap2[i].size(); j++) {
			cout << theHeap2[i][j][0] << " | " << theHeap2[i][j][1] << endl;
		}
	}
}

void MinHeap::clear()
{
	theHeap.clear();
	theHeap2.clear();
}
