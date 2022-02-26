//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/25/22
//  File type: C++ source file
//  Description: Quick sort implementation
//////////////////////////////////////////////////////

#include <mystd.h>


/*
Idea behind quick sort:
	Quick sort is a lot like merge sort, but rather than simply splitting the array in half
	and merging the sorted halves, quicksort calls a (ideally linear time) function to compute
	a pivot point, which will also place the pivot into its sorted position before returning its
	final index. Using that pivot point, it will recursively sort the partition of the array
	behind the pivot and then do the same for the partition in front of the pivot, until the
	entire array is sorted.

	@NOTE: In the worst case, the pivot that is chosen is the smallest or largest element in the sub-
	array, and this mean s the recursive call only makes a recursive call on the the same list
	sans the pivot element, which represent near linear branching factor, making the algorithm
	potentially run at O(N^2). There is no perfect pivot selection algorithm, however, there is one
	that performs the best most of the time and prevents the quadratic runtime when sorting arrays
	that are already sorted (either ascending or descending), and quite easy to implement. The
	method is called 'median of three'; rather than choosing the first element, we will always choose
	the median of the the first, middle, and last element in the range. For already sorted lists,
	this means our partitions will be exactly the same size, which means optimal runtime for those
	cases.

	@NOTE: Insertion tends to run faster than quicksort under a certain threshold of N.
	Many efficient quicksort algorithms check the length of the array it is sorting and makes
	a decision to either call quicksort or insertion sort. This is because the overhead of
	finding a partion in quicksort can sometimes takes more time than is saved by the logarithmic
	aspect of it for low N.
	
	@NOTE: While I used size_t to represent the indices in heap sort and merge sort, I've decided
	to use int here for quicksort for the sake of keeping the code clean and adding extra 'if'
	blocks. The reason for this because sometimes quicksort will make a recursive call with a
	negative value for hi (meaning partition chose the first index as the pivot). Size_t's are
	unsigned, and you start getting segfaults because when they dip into the negative, they
	wrap around to their max value limit (super large number), which obviously means you start
	getting bad memory access. You can use size_t here, you just need to make sure check when
	the partition is 0 to accomodate for it...
	

TC: O(NlogN), assuming 'partition' is linear, and has a O(N^2) worst case depending on the
		strength of the pivot.
SC: O(logN), because of space taken up by the recursive call stack.
*/


/// Naive basic implementation shown first

template <typename T>
int partition_1(std::vector<T> &arr, int lo, int hi){
	// This function returns the index to our chosen pivot.
	// For this naive partition algorithm, we will choose the first element in our range to be
	// our pivot (lo). We'll then iterate through the range, shift the element to the left of
	// the pivot if it is smaller, else leave it on the right side and swap it with another
	// element from the right to compare with the pivot, and decrement hi. Once the pivot is
	// equal to hi, our placement is finished.
	// Time complexity of this is O(N).

	while (lo < hi){
		if (arr[lo] > arr[lo+1]){
			std::swap(arr[lo], arr[lo+1]);
			lo += 1;
		} else if (arr[lo] < arr[lo+1]){
			std::swap(arr[lo+1], arr[hi]);
			--hi;
		} else { // they are equal
			lo += 1;
		}
	}

	return lo;
}


template <typename T>
void qsort_1(std::vector<T> &arr, int lo, int hi){
	if (lo < hi){
		int pivot = partition_1(arr, lo, hi);
		// @NOTE: partion places the pivot in its sorted position.
		// So we only call recursively on the ranges that dont include the pivot
		qsort_1(arr, lo, pivot-1);
		qsort_1(arr, pivot+1, hi);
	}
}


template <typename T>
void quicksort_1(std::vector<T> &arr){
	qsort_1(arr, 0, arr.size()-1);
}




////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////////////////
// A faster iteration of quicksort using cuttoff insertion sort and median-of-three pivot selection.

const inline int CUTOFF = 5; // @NOTE: Any value up to 20 tends to yield good results.


template <typename T>
void insertionsort(std::vector<T> &arr){
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


template <typename T>
int median_of_three(const std::vector<T> &arr, int lo, int hi){
	int middle = lo + (hi-lo)/2;
	if ((arr[lo] < arr[middle]) ^ (arr[lo] < arr[hi])) return lo;
	else if ((arr[middle] < arr[lo]) ^ (arr[middle] < arr[hi])) return middle;
	else return hi;
}


template <typename T>
int partition(std::vector<T> &arr, int lo, int hi){
	bool KPCL = true; // stands for "keep pivot clone left"
	while (lo < hi){
		if (arr[lo] > arr[lo+1]){
			std::swap(arr[lo], arr[lo+1]);
			lo += 1;
		} else if (arr[lo] < arr[lo+1]){
			std::swap(arr[lo+1], arr[hi]);
			--hi;
		} else { // they are equal
			if (KPCL){ // we want to evenly distribute elements equal to the pivot to both partitions.
				lo += 1; // -> to keep in the left partition
			} else { // -> to move to the right partition
				std::swap(arr[lo+1], arr[hi]);
				--hi;
			}
			KPCL = !KPCL; // flip partitions for the next pivot-like element.
		}
	}

	return lo;
}


template <typename T>
void qsort(std::vector<T> &arr, int lo, int hi){
	if (hi - lo > CUTOFF){ // (leave the tiny subbarray sorting for insertionsort later on)
		int pivot = median_of_three(arr, lo, hi);
		std::swap(arr[lo], arr[pivot]); // move the pivot to the front.
		pivot = partition(arr, lo, hi); // partition the array assuming the pivot is at the front.
		qsort(arr, lo, pivot-1);
		qsort(arr, pivot+1, hi);
	}
}


template <typename T>
void quicksort(std::vector<T> &arr){
	qsort(arr, 0, arr.size()-1); // gets the array very close to being sorted.
	insertionsort(arr); // finalizes the sort relatively quickly (does very little of the work).
}




int main(){
	std::vector<int> arr;

	arr = {7,1,4,2,6,3,5,3};
	quicksort(arr);
	c_log(arr);

	arr = {1,5,2,3,4,4,0,-10,7,8,5,2,13,4,8,3,4,10,-3,-6,3};
	quicksort(arr);
	c_log(arr);

	arr = {1,5,2,3,4,4,0,-10,7,8,5,2,13,4,8,3,4,10,-3,-6,3,2,54,7,14,6,22,5,6,9,66,3,5,24,-45,5,2};
	quicksort(arr);
	c_log(arr);

	arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	quicksort(arr);
	c_log(arr);

	arr = {1,2,3};
	quicksort(arr);
	c_log(arr);

	arr = {1,1,1};
	quicksort(arr);
	c_log(arr);

	arr = {2,1};
	quicksort(arr);
	c_log(arr);

	arr = {1};
	quicksort(arr);
	c_log(arr);

	arr = {};
	quicksort(arr);
	c_log(arr);

	std::vector<std::string> arrs = {"hello", "matey", "burger", "pop", "pizza", ":)"};
	quicksort(arrs);
	c_log(arrs);

	return 0;
}



