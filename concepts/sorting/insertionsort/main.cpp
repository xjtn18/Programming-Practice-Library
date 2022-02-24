//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: C++ source file
//  Description: Insertion sort implementation
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template <typename T>
void insertionsort(vector<T> &arr){
	for (int i = 1; i < arr.size(); ++i){
		T temp = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = temp;
	}
}


int main(){
	vector<int> arr;

	arr = {7,1,4,2,3,6,3,5};
	insertionsort(arr);
	c_log(arr);

	arr = {1,2,3};
	insertionsort(arr);
	c_log(arr);

	arr = {1,1,1};
	insertionsort(arr);
	c_log(arr);

	arr = {2,1};
	insertionsort(arr);
	c_log(arr);

	arr = {1};
	insertionsort(arr);
	c_log(arr);

	vector<std::string> arrs = {"hello", "matey", "burger", "pop", "pizza", ":)"};
	insertionsort(arrs);
	c_log(arrs);
	
	return 0;
}


