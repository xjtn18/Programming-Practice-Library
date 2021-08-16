#include <iostream>
#include <algorithm>

#include <mystd.h>

// Same as house robber 1 except the houses are arranged in a circle.
//
// Idea:
// Compute the max amount of cash from house [1 -> n] and then from [0 -> n-1].
// Whichever one yeilds more cash is our answer.
//
// TC
// 2 runs of rob utitilty on vector length n-1, so basical O(2n), which is still linear.
//
// SC
// Using start and end indexes to avoid having to make copies of the cash vector; O(2n);



int rob_utility(const std::vector<int>& cash, const int& start, const int& end){
	int memo[end];
	memo[start] = cash[start];
	memo[start+1] = std::max(cash[start], cash[start+1]);
	for (int i = start+2; i < end; ++i){
		memo[i] = std::max(memo[i-2] + cash[i], memo[i-1]);
	}
	return memo[end-1];
}


int rob(std::vector<int> cash){
	if (cash.size() == 0) return 0;
	if (cash.size() == 1) return cash[0];
	if (cash.size() == 2) return std::max(cash[0], cash[1]);
	return std::max(rob_utility(cash, 1, cash.size()), rob_utility(cash, 0, cash.size()-1));
}



int main(){
	assert(rob(std::vector<int>{2,3,2}) == 3);
	assert(rob(std::vector<int>{2,1,1}) == 2);
	assert(rob(std::vector<int>{1,2,1}) == 2);
	assert(rob(std::vector<int>{2,1,1,2}) == 3);
	assert(rob(std::vector<int>{2}) == 2);
	assert(rob(std::vector<int>{}) == 0);
	assert(rob(std::vector<int>{1,2}) == 2);
	assert(rob(std::vector<int>{0,0}) == 0);
	return 0;
}


