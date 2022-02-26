//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: C++ source file
//  Description: Shell sort implementation
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
Shell sort:
	This algorithm is a lot like bubble sort in essence, but instead of making swaps between
	adjacent elements every run, it makes swaps between largely misordered elements first.
	It does this by keeping track of a gap. The gap starts off at half the size of the full array.
	We make swaps between all elements that are 'gap' elements apart, and then we cut the size of
	gap by another half, until eventually the gap is 1, where we swap all adjacent misordered values,
	after which the entire array is sorted.

TC: Complexity is difficult to analyze for shellsort, but it is approximately O(N^1.5), or
		equivalently O(N * N^0.5) ===> O(N*sqrt(N)), slightly worse than heap/merge/quick sort.
SC: O(1)
*/



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

	arr = {1,5,2,3,4,4,0,-10,7,8,5,2,13,4,8,3,4,10,-3,-6,3};
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


