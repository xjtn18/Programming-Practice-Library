#pragma once

#include <iostream>
#include <fstream>
#include <mystd.h>



void parse_cases(std::vector<std::vector<std::string>>& inputs, std::vector<std::string>& expects);


template <typename T1>
void run_tests(std::function<T1> f){
	std::vector<std::vector<std::string>> inputs;
	std::vector<std::string> expects;
	parse_cases(inputs, expects);
	hlog(inputs);
	c_log(expects);

	for (int i = 0; i < inputs.size(); ++i){
		if (inputs[0].size() == 2){
			//std::string
			//assert(f(, inputs[i][1]) == expects[i]);
		}
	}
}



