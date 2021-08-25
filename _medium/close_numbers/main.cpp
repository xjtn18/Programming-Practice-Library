//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/22/21
//  File type: C++ source file
//  Description: Given a list of integers, return boolean of whether or not there exists
//  					the same number k or less spaces apart anywhere in the list.
//////////////////////////////////////////////////////


// 
// Idea
// Do one loop through the numbers
// Keep a map that maps integers in the list to their indexes in the list
// If we get a number that has a key in the map and abs(i - map[nums[i]]) <= k), return true
// Else if the distance is greater, then update map[nums[i]] to the new current i
// If we loop through the whole list, then return false
//



#include <mystd.h>


bool containsCloseNums(std::vector<int> nums, int k) {
	std::map<int, int> m;

	for (int i = 0; i < nums.size(); ++i){
		int number = nums[i];
		if (is_in(number, m) && abs(m[number] - i) <= k){
			return true;
		} else { // if number isnt in the list or the distance is too large
			m[number] = i;
		}
	}

	return false;
}
 



int main(){
	std::vector<int> nums;
	assert( containsCloseNums(nums, 2) == false );

	nums = {1,1,3};
	assert( containsCloseNums(nums, 1) == true );

	nums = {1,3,1};
	assert( containsCloseNums(nums, 1) == false );

	nums = {1,3,1};
	assert( containsCloseNums(nums, 2) == true );

	nums = {1,1,1};
	assert( containsCloseNums(nums, 2) == true );

	nums = {1,2,3,4,5,6,1};
	assert( containsCloseNums(nums, 5) == false );

	nums = {1,2,3,4,5,6,1};
	assert( containsCloseNums(nums, 6) == true );

	nums = {1,2,3,4,5,6,1};
	assert( containsCloseNums(nums, 0) == false );

	return 0;
}



