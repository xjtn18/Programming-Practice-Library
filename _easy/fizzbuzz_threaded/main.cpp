#include <vector>
#include <iostream>
#include <string>
#include "../../debug.h"

class Solution {
public:
	std::vector<std::string> fizzBuzz(int n){
		std::vector<std::string> res;
		for (int i = 1; i <= n; ++i){
			if (i % 3 == 0 && i % 5 == 0){
				res.push_back("FizzBuzz");
			} else if (i % 3 == 0){
				res.push_back("Fizz");
			} else if (i % 5 == 0){
				res.push_back("Buzz");
			} else {
				res.push_back(std::to_string(i));
			}
		}
		return res;
	}
};
				




int main(int argc, char** argv){
	Solution sol{};
	dlog(sol.fizzBuzz(15));

	return 0;
}
