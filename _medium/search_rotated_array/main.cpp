//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/8/22
//  File type: C++ source file
//  Description: Given a sorted array that was rotated by some unknown degree,
//  	give an algorithm that returns the index of some value in the array
//  	(if it exists) in log(N) time.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;




int search(vector<int> &nums, int target){
	int low = 0, high = nums.size()-1;

	while (low <= high){
		int mid = (high-low)/2 + low;
		if (target < nums[mid]){
			if (target >= nums[low] || nums[low] > nums[mid]){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else if (target > nums[mid]){
			if (target <= nums[high] || nums[mid] > nums[high]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		} else {
			return mid;
		}
	}

	return -1;
}



int main(){
	vector<int> nums;

	nums = {4,5,6,7,0,1,2};
	dlog(search(nums, 5));



	return 0;
}



