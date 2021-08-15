#include <iostream>
#include <algorithm>
#include "../../Debug.hpp"


int safe_at(const std::vector<int>& v, unsigned int index){
	try {
		return v.at(index);
	} catch (const std::out_of_range& e){
		return 0;
	}
}


int rob(std::vector<int> cash){
	int n = cash.size();
	if (n==0) return 0; // when there are no houses to rob
	std::vector<int> memo(n);
	for (int i = 0; i < n; ++i){
		memo[i] = std::max(safe_at(memo, i-2) + cash[i], safe_at(memo, i-1));
	}
	return memo[n-1];
}



int main(){
	std::cout << rob(std::vector<int>{2,1,1,2,3,2,3,2}) << std::endl;
	std::cout << rob(std::vector<int>{2,1,1,2}) << std::endl;
	std::cout << rob(std::vector<int>{2}) << std::endl;
	std::cout << rob(std::vector<int>{}) << std::endl;
	return 0;
}

