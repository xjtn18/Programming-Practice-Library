//////////////////////////////////
// Auther: Jacob Nardone
// Date: 3-18-2021
// File: C++ source file
// Description: Draws r rows of a half diamond to the shell, r given by user (takes odd inputs only)
//////////////////////////////////


#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** args){
	int rows;
	do {
		if (argc < 2){
			std::string input;
			std::cin >> input;
			rows = std::stoi(input);
		} else {
			rows = std::stoi(args[1]);
		}

		if (rows % 2 == 0){
			if (argc >= 2){
				std::cout << "Error: provided input argument not odd, try again" << std::endl;
				exit(1);
			}
			std::cout << "Error: input not odd, try again" << std::endl;
		} else {
			break;
		}
	} while (true);

	int w = ceil(rows / 2.0);
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < w; ++j){
			// the amount of white space in front of this row is a function of how far we are from the diamonds center
			(j >= abs(w - i - 1)) ? std::cout << "*" : std::cout << " ";
		}
		std::cout << "\n";
	}

	return 0;

}
