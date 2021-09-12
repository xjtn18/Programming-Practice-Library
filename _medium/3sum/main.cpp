//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/26/21
//  File type: C++ source file
//  Description: Given a list of integers, return all unique triplet groupings of numbers that sum to 0.
//////////////////////////////////////////////////////


//
// Grab every pair of numbers in the list.
// Check to see if the negation of their sum is in the set.
// 



#include <mystd.h>
#include <unordered_set>
using namespace std;


#define in(x,y) y.find(x) != y.end()
#define not_in(x,y) y.find(x) == y.end()




vector<vector<int>> threeSum(vector<int> nums){
	//
	// Given a list of integers, return a list of 
	// all triplet groupings in that list that sum
	// a target value of 0.
	//
	vector<vector<int>> answer;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); ++i){
		int target = 0 - nums[i];
		int front = i + 1;
		int back = nums.size() - 1;
		while (front < back){
			if (nums[front] + nums[back] > target){
				back--;
			} else if (nums[front] + nums[back] < target){
				front++;
			} else {
				answer.push_back({nums[i], nums[front], nums[back]});
				front++;
				back--;
				for (; nums[front] == nums[front-1]; ++front);
				for (; nums[back] == nums[back+1]; --back);
			}
		}
		for (; i < nums.size()-1 && nums[i] == nums[i+1]; ++i);

	}

	return answer;
}




int main(){
	hlog( threeSum({-2,0,0,2,2}) );
	hlog( threeSum({-2,0,1,1,2}) );


	return 0;
}


