//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: C++ source file
//  Description: Shell sort implementation
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template <typename T>
void shellsort(vector<T> &arr){
	int gap = arr.size() / 2;
	while (gap > 0){ // log(n) gaps to iterate through
		for (int i = gap; i < arr.size(); ++i){
			int j = i - gap;
			while (j >= 0 && arr[j] > arr[j+gap]){
				std::swap(arr[j], arr[j+gap]);
				j -= gap;
			}
		}
		gap /= 2;
	}
}


int main(){
	vector<int> arr;

	arr = {7,1,4,2,3,6,3,5};
	shellsort(arr);
	c_log(arr);

	arr = {1,2,3};
	shellsort(arr);
	c_log(arr);

	arr = {1,1,1};
	shellsort(arr);
	c_log(arr);

	arr = {2,1};
	shellsort(arr);
	c_log(arr);

	arr = {1};
	shellsort(arr);
	c_log(arr);

	vector<std::string> arrs = {"hello", "matey", "burger", "pop", "pizza", ":)"};
	shellsort(arrs);
	c_log(arrs);
	
	return 0;
}


