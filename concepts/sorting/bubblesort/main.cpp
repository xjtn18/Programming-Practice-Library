//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: C++ source file
//  Description: Bubble sort implementation
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



template <typename T>
void bubblesort(vector<T> &arr){
	for (int i = 0; i < arr.size()-1; ++i){
		bool done = true;
		for (int j = 0; j < arr.size()-1; ++j){
			if (arr[j] > arr[j+1]){
				std::swap(arr[j], arr[j+1]);
				done = false;
			}
		}
		if (done) break;
	}
}


int main(){
	vector<int> arr;

	arr = {7,1,4,2,3,6,3,5};
	bubblesort(arr);
	c_log(arr);

	arr = {1,2,3};
	bubblesort(arr);
	c_log(arr);

	arr = {1,1,1};
	bubblesort(arr);
	c_log(arr);

	arr = {2,1};
	bubblesort(arr);
	c_log(arr);

	arr = {1};
	bubblesort(arr);
	c_log(arr);

	return 0;
}


