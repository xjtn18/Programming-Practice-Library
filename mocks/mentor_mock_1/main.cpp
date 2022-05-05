//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 3/24/22
//  File type: C++ source file
//  Description: 1st mock interview with Netflix mentor.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;
#include <vector>
#include <iostream>
#include <numeric>



bool search_rotated(vector<int> arr, int value){
	int high = arr.size()-1;
	int low = 0;
	while (low <= high){
		int middle = low + (high-low) / 2; // overflow safe
		if (value > arr[middle]){
			if (value <= arr[high] || arr[high] < arr[middle]){
				low = middle + 1;
			} else {
				high = middle - 1;
			}
		} else if (value < arr[middle]){
			if (value >= arr[low] || arr[low] > arr[middle]){
				high = middle - 1;
			} else {
				low = middle + 1;
			}
		} else {
			return true;
		}
	}

	return false;
}


int main(){
	cout << boolalpha << search_rotated({11, 15, 20, 1, 4, 6, 8, 9}, 6) << endl;
	cout << boolalpha << search_rotated({11, 15, 20, 1, 4, 6, 8, 9}, 2) << endl;
	cout << boolalpha << search_rotated({11, 15, 20, 1, 4, 6, 8, 9}, 10) << endl;
	cout << boolalpha << search_rotated({11, 15, 20, 1, 4, 6, 8, 9}, 9) << endl;
	cout << boolalpha << search_rotated({11, 15, 20, 1, 4, 6, 8, 9}, 11) << endl;
	cout << boolalpha << search_rotated({1, 2, 3, 4}, 3) << endl;
	cout << boolalpha << search_rotated({1, 2, 3, 4}, 2) << endl;
	cout << boolalpha << search_rotated({1}, 1) << endl;
	cout << boolalpha << search_rotated({1}, 0) << endl;
	cout << boolalpha << search_rotated({}, 0) << endl;
	cout << boolalpha << search_rotated({4, 5, 6, 7, 14, 3}, 14) << endl;
	cout << boolalpha << search_rotated({15, 3, 4, 5, 6, 7, 14}, 3) << endl;
	cout << boolalpha << search_rotated({7,7,7,8,2,7}, 2) << endl;

	return 0;
}


