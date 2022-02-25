//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/24/22
//  File type: C++ source file
//  Description: Heap sort implementation
//////////////////////////////////////////////////////

#include <mystd.h>
using namespace std;

/*
Idea behind heap sort:
To get heap sort working we want to treat the array as a heap representation.
We want to iteratively 'sift' the greatest value to the front of the array.
We will do this using a 'sift up' method that will take a range of values (the
range will start at 2 increase to N) and will sift up the last element (if needed)
to its correct position in the heap. After having done this for all ranges, our
entire array will represent a valid heap. To then convert this into a sorted array,
we will swap the first (max) and last value in our heap, and then sift the new first
element down (using a sift down function) to re-heapify the array. Once we are done
with that, we effectively reduce the size of the unsorted part of our array by 1, and
repeat the sift down process. Once finished we will have a sorted array.

TC: O(NlogN) : Both for-loops inside of the mergesort function run a logN sift operation N times.
SC: O(1) : no temporary arrays needed.
*/

template <typename T>
void sift_up(vector<T> &arr, size_t i){
	size_t parent_idx = (i-1)/2;
	while (arr[parent_idx] < arr[i]){
		swap(arr[parent_idx], arr[i]);
		if (parent_idx == 0) break; // we've sifted up as far as we could.
		i = parent_idx;
		parent_idx = (i-1)/2;
	}
}


template <typename T>
size_t max_child(vector<T> &arr, size_t i, size_t heap_size){
	// returns the index of the larger child in a heap-based array.
	size_t left_idx = 2*i+1;
	size_t right_idx = 2*i+2;
	if (left_idx >= heap_size) return i; // no children
	else if (right_idx >= heap_size) return left_idx; // only a left child
	else return (arr[left_idx] > arr[right_idx]) ? left_idx : right_idx;
}


template <typename T>
void sift_down(vector<T> &arr, size_t heap_size){
	size_t i = 0, child;
	while (arr[child = max_child(arr, i, heap_size)] > arr[i]){ // while there are larger children
		swap(arr[i], arr[child]);
		i = child;
	}
}


template <typename T>
void heapsort(vector<T> &arr){
	for (int i = 1; i < arr.size(); ++i){
		sift_up(arr, i); // sift up the value at index i
	}
	for (int n = arr.size()-1; n > 0; --n){
		swap(arr[0], arr[n]); // place next largest element at the end of the heap.
		sift_down(arr, n); // sift down the new value at index 0 (re-heapify the array).

		// Here, 'n' represents the size of the heap portion of the array.
		//	We only let our sift-down function consider the first 'n' elements,
		//	otherwise we might be sift-up previously sorted values that are
		//	sitting at the back of the array.
	}
}



int main(){
	vector<int> arr;

	arr = {7,1,4,2,3,6,3,5};
	heapsort(arr);
	c_log(arr);

	arr = {1,2,3};
	heapsort(arr);
	c_log(arr);

	arr = {1,1,1};
	heapsort(arr);
	c_log(arr);

	arr = {2,1};
	heapsort(arr);
	c_log(arr);

	arr = {1};
	heapsort(arr);
	c_log(arr);

	vector<std::string> arrs = {"hello", "matey", "burger", "pop", "pizza", ":)"};
	heapsort(arrs);
	c_log(arrs);
	
	return 0;
}


