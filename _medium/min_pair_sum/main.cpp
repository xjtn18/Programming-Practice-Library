//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/14/21
//  File type: C++ source file
//  Description: Given an array of intergers, return the minimum sum of possible
//  					element pairs.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

// NOTE: If we know the problem constraints, we can use bucket sort to sort the list
// 		in linear time.
// 		.. See 'bucket sort' in the 'concept' folder.

int arrayPairSum(vector<int>& nums){
	int sigma = 0;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i+=2){
		sigma += nums[i];
	}

	return sigma;
}



int main(){
	vector<int> nums;

	nums = {1,4,3,2};
	cout << arrayPairSum(nums) << endl;

	return 0;
}



