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

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};




void compute_combos(vector<vector<int>> &all_combos, vector<int> &combo, int index, vector<int> &candidates, int target){
	if (target > 0){
		for (int i = index; i < candidates.size() && target >= candidates[i]; ++i){
			combo.push_back(candidates[i]);
			compute_combos(all_combos, combo, i, candidates, target - candidates[i]);
			combo.pop_back();
		}

	} else if (target == 0){
		all_combos.push_back(combo);
		
	}
}



vector<vector<int>> combinationSum(vector<int>& candidates, int target){
	vector<vector<int>> all_combos;
	vector<int> combo; 
	combo.reserve(target); // at most there can be 'target' number of values in any single combo (1+1+1.. etc)

	sort(candidates.begin(), candidates.end());
	compute_combos(all_combos, combo, 0, candidates, target);
	return all_combos;
}



int main(){
	
	Timer t;
	vector<int> input;

	input = {2};
	hlog( combinationSum(input, 3) );

	input = {2,3,5};
	hlog( combinationSum(input, 8) );

	input = {55, 40, 31, 37, 52, 51, 28, 17, 34, 32, 59, 13, 20, 4, 9, 1, 26, 8, 16, 23, 41, 12, 3, 50, 22, 42, 44, 19, 39, 48};

	t.reset();
	combinationSum(input, 57);
	dlog(t.elapsed());

	Solution sol;
	t.reset();
	sol.combinationSum(input, 57);
	dlog(t.elapsed());


	input = {137, 53, 60, 119, 39, 12, 186, 143, 151, 147, 173, 124, 166, 193, 122, 140, 112, 164, 199, 4, 167, 44, 117, 85, 185, 77, 195, 25, 28, 26, 16, 101, 1, 70, 55, 106, 155, 192};

	dlog("------");
	t.reset();
	combinationSum(input, 216);
	dlog(t.elapsed());

	t.reset();
	sol.combinationSum(input, 216);
	dlog(t.elapsed());



	return 0;
}





