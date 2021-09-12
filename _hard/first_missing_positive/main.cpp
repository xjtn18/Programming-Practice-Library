//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/29/31
//  File type: C++ source file
//  Description: Given a list of unsorted nums, return the first missing
//  					positive integer in linear time and constant space.
//////////////////////////////////////////////////////


//
// After giving it plenty of thought, I could not devise a way to do this in linear time on my own.
// The solution I ended up with was the fairly trivial one where you sort the array and
// then iterate all positive ints until there is a gap between arr[i] and arr[i+1], in which
// case arr[i] + 1 is your answer.
// This would yeild a time complexity of N log N because of the sort, but is still performant none the less,
// and is accepted by LeetCode.
//
// I knew that in order to reach linear time, there would have to be some way we could swap indices
// to produce an array that we can iterate over once more and have a clear answer, but I couldnt formalize it.
// It the leetcode discussion, there is a nice linear implementation that makes sense but isn't that easy
// to intuitively come by.
//
// The idea is that we place all positive integers in the array position that corresponds to their value, for example
// [1,2,3], in this array, every value corresponds to their index in the array + 1, meaning they are in the correct position since all we want it positive numbers, and so for this case we would return n + 1 as our answer, where n is the size of the array. In the example of [1,2,3,5], as we iterate throught the array, we see that 5 is in the 4th index, and 4 should be there, so the answer must be 4, as it is the first position in the array that does not contain its expected value.
// This algorithm doesnt not do any sorting, it simply puts the values into their corresponding positions in the array,
// and all duplicates and non-positive numbers will be shoved to the end of the array in the process, which works
// perfectly for us, as we can then loop over once more and the read the positive incrementing integers at the front
// of the array until we inevitiably reach our answer.
//
// This solution may not look linear because of the nested loops, but the inner while loop is gauranteed to run at most N times, because every time it loops, it places a value in its correct location, and you will only ever need to do that at most N times if all N indices contain incorrect values from the start. If an inner loop will only ever run its body N times, throughout the entire function call, then that function runs the same as O(N) + O(N), which is always linear.
// 




#include <mystd.h>
#include <random>
using namespace std;



int firstMissingPositive(vector<int>& nums){
	if (!nums.size()) return 1;
	sort(nums.begin(), nums.end());
	int i = 0;
	for (; i < nums.size() && nums[i] <= 0; ++i){} // skip all non-positives
	if (i == nums.size() || nums[i] != 1) return 1; // if there are no positive numbers or 1 is not in the list
	for (; i < nums.size() - 1; ++i){
		if (nums[i+1] - nums[i] > 1){
			 return nums[i] + 1;
		}
	}

	return nums[i] + 1;
}




int optimal(vector<int>& nums){
	int i;
	for (i = 0; i < nums.size(); ++i){
		while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]){
			swap(nums[i], nums[nums[i]-1]);
		}
	}
	for (i = 0; i < nums.size(); ++i){
		if (nums[i] != i+1){
			return i + 1;
		}
	}

	return nums.size() + 1;
}





int main(){
	vector<int> input;

	input = {1,4,6,2,5};
	assert( firstMissingPositive(input) == 3 );
	assert( optimal(input) == 3 );

	input = {1,3,2};
	assert( firstMissingPositive(input) == 4 );
	assert( optimal(input) == 4 );

	input = {0};
	assert( firstMissingPositive(input) == 1 );
	assert( optimal(input) == 1 );

	input = {1,1};
	assert( optimal(input) == 2 );


	input = {1,2,3,4,5,6,7,9,10,8};

	random_device rd;
	mt19937 g(rd());
	shuffle(input.begin(), input.end(), g);
	c_log(input);
	optimal(input);
	c_log(input);

	return 0;
}



