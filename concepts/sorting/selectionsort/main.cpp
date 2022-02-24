//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: C++ source file
//  Description: Selection sort implementation
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template <typename T>
void selectionsort(vector<T> &arr){
	for (int i = 0; i < arr.size(); ++i){
		int min_index = i;
		for (int j = i+1; j < arr.size(); ++j){
			if (arr[j] < arr[min_index]) min_index = j;
		}
		std::swap(arr[i], arr[min_index]);
	}
}


int main(){
	vector<int> arr;

	arr = {7,1,4,2,3,6,3,5};
	selectionsort(arr);
	c_log(arr);

	arr = {1,2,3};
	selectionsort(arr);
	c_log(arr);

	arr = {1,1,1};
	selectionsort(arr);
	c_log(arr);

	arr = {2,1};
	selectionsort(arr);
	c_log(arr);

	arr = {1};
	selectionsort(arr);
	c_log(arr);

	return 0;
}


