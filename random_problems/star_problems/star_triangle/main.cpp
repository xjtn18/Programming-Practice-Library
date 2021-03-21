//////////////////////////////////
// Auther: Jacob Nardone
// Date: 3-18-2021
// File: C++ source file
// Description: Cleaner implementation of printing triangle to shell (not flipped)
//////////////////////////////////


#include <iostream>

int main(int argc, char** args){
	int rows;
	if (argc < 2){
		std::string input;
		std::cin >> input;
		rows = std::stoi(input);
	} else {
		rows = std::stoi(args[1]);
	}

	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < rows+i; ++j){
			// if the row is the base of the triangle, if its the left side, or if its the right side, print star
			if (i == rows-1 || j == rows-i-1 || j == rows+i-1){
				std::cout << "*";
			} else { // else print whitespace
				std::cout << " ";
			}
		}

		std::cout << "\n";
	}

	return 0;

}
