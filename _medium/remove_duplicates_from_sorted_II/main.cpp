//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 7/28/22
//  File type: C++ source file
//  Description: Given a non-decreasing list of integers, remove duplicates such
//  	that each unique element appears at most twice.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
 * Solution
 *
 * We're going to use 
 *
 */



int removeDuplicates(vector<int>& nums){
	int wwrite = 0;
	int ssearch = 0;
	int dup_count = 0;

	while (ssearch < nums.size()){
		if (nums[wwrite] == nums[ssearch]){
			dup_count++;
		} else {
			dup_count = 0;
		}
		if (dup_count > 2){
			while (ssearch < nums.size() && nums[ssearch] == nums[wwrite]
		} else {
			ssearch++;
			wwrite++;
		}
	}

}



int main(){
	vector<int> nums;


	nums = {1,1,1,2,2,3};
	removeDuplicates(nums);
	c_log(nums);

	return 0;
}



