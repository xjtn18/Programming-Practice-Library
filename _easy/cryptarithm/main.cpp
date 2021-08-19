//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given a mapping between chars and digits, determine if a 3-word message holds true with 'word1 + word2 = word3'.
//////////////////////////////////////////////////////


#include <mystd.h>

template <typename T>
using vec2D = std::vector<std::vector<T>>;



char translate(const char& c, const vec2D<char>& solution){
	for (const auto& p : solution){
		if (p[0] == c){
			return p[1];
		}
	}
	return '0'; // shouldnt happen given the problem constraints.
}



bool isCryptSolution(std::vector<std::string> crypt, vec2D<char> solution){
	std::vector<long> ops; // NOTE: Make sure to store longs, since the problems constraints says words can be up to 14 characters long.
	for (std::string& str : crypt){
		if (translate(str[0], solution) == '0' && str.length() > 1){
			return false; // no leading zeroes;
		}
		std::string int_str = "";
		for (int i = 0; i < str.length(); ++i){
			int_str += translate(str[i], solution);
		}
		ops.push_back(std::stol(int_str));
	}
	return ops[0] + ops[1] == ops[2];
}



int main(){
	vec2D<char> solution;

	solution =	{{'O', '0'},
					{'M', '1'},
					{'Y', '2'},
					{'E', '5'},
					{'N', '6'},
					{'D', '7'},
					{'R', '8'},
					{'S', '9'}};

	assert( isCryptSolution({"SEND", "MORE", "MONEY"}, solution)  == true ); // no leading zeroes and sum is correct

	solution = {{'O', '1'},
					{'T', '0'},
					{'W', '9'},
					{'E', '5'},
					{'N', '4'}};

	assert( isCryptSolution({"TEN", "TWO", "ONE"}, solution)  == false ); // leading zeroes

	return 0;
}



