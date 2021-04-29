#include <iostream>


void right_triangle_increase(int rows){
	int counter = 1;
	for (int r = 0; r < rows; ++r){
		for (int j = 0; j < r+1; ++j){
			std::cout << counter;
			counter++;
		}
		std::cout << "\n";
	}
}
			
void right_triangle_increase_inv(int rows){
	int counter = (rows * rows + rows) / 2;
	for (int r = 0; r < rows; ++r){
		for (int j = 0; j < rows - r; ++j){
			std::cout << counter;
			counter--;
		}
		std::cout << "\n";
	}
}

int main(){
	int input;
	std::cin >> input;
	//right_triangle_increase(input);
	right_triangle_increase_inv(input);

	return 0;
}
