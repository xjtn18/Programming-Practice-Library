//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/24/22
//  File type: C++ source file
//  Description: Merge sort implementation
//////////////////////////////////////////////////////

#include <mystd.h>


/*
Basic idea behind merge sort:
We will create a helper functions that takes to index range of the container to sort.
Sublists will be represented as index ranges into the original list.

We will have a function that takes the list to sort and the range to sort (at first,
this will be the entire range). We will form the sorted list by recursively calling
the same function to sort the first half or the list, and we will do the same for the
second half. Once we have these 2 sorted lists, we will merge them together, which is 
trivial. The base case is when the halves of the arrays are of length 1. In this case,
we will choose to either swap to values if they aren't in order, or leave them as is
if they are. We can now assume each sub-call will recursively sort each sublist, and
our final return when the call stack finished popping will contain the sorted version
of the entire original list.

TC: O(NlogN), there are logN half splits, and it takes N time to merge each of them.
SC: O(N), to build the temporary arrays that store the result of the merged sublists.
*/

template <typename T>
std::vector<T> merge(const std::vector<T> &arr, int lo, int mid, int hi){
	// Takes 2 sorted lists and merges them together
	std::vector<T> combined;
	combined.reserve(hi - lo);

	int i = lo, j = mid;
	for (; i < mid; ++i){
		for (; j < hi && arr[j] < arr[i]; ++j) combined.push_back(arr[j]);
		combined.push_back(arr[i]);
	}
	for (; j < hi; ++j) combined.push_back(arr[j]); // add any remaining max elements from the j-range.

	return combined;
}


template <typename T>
void msort(std::vector<T> &arr, int lo, int hi){
	// base case
	if (hi - lo == 1) return;

	int mid = lo+((hi-lo)/2); // calculate the middle index

	msort(arr, lo, mid);
	msort(arr, mid, hi);
	std::vector<T> combined = merge(arr, lo, mid, hi);

	// copy contents from combined into range [start-stop) in the original arr
	for (int i = lo; i < hi; ++i){
		arr[i] = combined[i-lo];
	}
}


template <typename T>
void mergesort(std::vector<T> &arr){
	msort(arr, 0, arr.size());
}



int main(){
	std::vector<int> arr;

	arr = {7,1,4,2,6,3,5,3};
	mergesort(arr);
	c_log(arr);

	arr = {1,5,2,3,4,4,0,-10,7,8,5,2,13,4,8,3,4,10,-3,-6,3};
	mergesort(arr);
	c_log(arr);

	arr = {1,2,3};
	mergesort(arr);
	c_log(arr);

	arr = {1,1,1};
	mergesort(arr);
	c_log(arr);

	arr = {2,1};
	mergesort(arr);
	c_log(arr);

	arr = {1};
	mergesort(arr);
	c_log(arr);

	std::vector<std::string> arrs = {"hello", "matey", "burger", "pop", "pizza", ":)"};
	mergesort(arrs);
	c_log(arrs);

	return 0;
}


