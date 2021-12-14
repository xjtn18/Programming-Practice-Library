//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/9/21
//  File type: C++ source file
//  Description: Given an array of distinct integers and a target value, return a list of 
//  					all combinations of values in the list (repeats allowed) that
//  					sum to the target value.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



void findCombos(vector<int> &c, vector<vector<int>> &all, vector<int> &combo, int j, int target){
	if (target == 0){
		all.push_back(combo);
	} else {
		for (int i = j; i < c.size() && c[i] <= target; ++i){
			combo.push_back(c[i]);
			findCombos(c, all, combo, i, target - c[i]);
			combo.pop_back();
		}
	}
  
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
	vector<vector<int>> all;
	vector<int> combo;
	combo.reserve(target); // 1 + 1 + 1 + ...
	sort(candidates.begin(), candidates.end());
	findCombos(candidates, all, combo, 0, target);

	return all;
}





int main(){
	vector<int> input;

	input = {2};
	hlog( combinationSum(input, 3) );

	input = {2,3,5};
	hlog( combinationSum(input, 8) );


	return 0;
}





