#include <runner.hpp>


void parse_cases(std::vector<std::vector<std::string>>& inputs, std::vector<std::string>& expects){
	std::ifstream file("testcases.txt");
	std::string in_out_delim = " ::: ", line;

	std::getline(file, line);// type specifier

	while (std::getline(file, line)){
		std::cout << line << std::endl;
		size_t split = line.find(in_out_delim);
		std::string input = line.substr(0, split);
		std::vector<std::string> args;
		size_t arg_split, start = 0;
		while ((arg_split = input.find(",")) != std::string::npos){
			args.push_back(input.substr(start, arg_split));
			start = arg_split + 2; // 2 is length of ", "
			input.erase(0, arg_split+2);
		}
		args.push_back(input);
		inputs.push_back(args);
		expects.push_back( line.substr(split + in_out_delim.length()) );
	}
	file.close();
}


void cast_tokens(std::vector<std::string>& inputs, std::vector<std::string>& expects){
	c_log(inputs);
	c_log(expects);
}



