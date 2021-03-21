//////////////////////////////////
// Auther: Jacob Nardone
// Date: 3-18-2021
// File: C++ source file
// Description: Asks user for integer input r, then prints r rows of a triangle to the shell flipped upside down.
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

	for (int i = rows-1; i >= 0; --i){
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
