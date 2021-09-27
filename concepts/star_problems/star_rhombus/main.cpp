#include <iostream>

int main(){
	std::string input;
	std::cin >> input;
	int rows = std::stoi(input);

	for (int i = 0; i < rows; ++i){
		for (int k = 0; k < i; ++k){
			std::cout << " ";
		}
		for (int j = 0; j < rows; ++j){
			std::cout << "*";
		}
		std::cout << "\n";
	}


	return 0;
}
