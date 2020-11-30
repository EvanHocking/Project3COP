//Plan is to implement a min heap that stores each item in the aisle 
//that corresponds to it and then print all of the aisles in order
//in the Database: B sores the brand and D stores the description
//E stores the aisle
//so given a vector of vectors is the list of items and each vector
//contains all five pieces of data, we sort the list based on the aisle number
//so create nodes that have all three pieces of data we need
//ie B, D and E

#include <iostream>
#include <vector>
#include <array>
#include <string> 
using namespace std;

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
		int input = stoi(vector[i][4]);//which will change the aisle data string to number
		//making the vector of data from the list
		vector<string> temp;
		temp.push_back(list[i][1]); //the brand name
		temp.push_back(list[i][3]); //the food item
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
void heapify(int* theHeap, vector<vector<string>>* theHeap2[], int n, int size) {

}
