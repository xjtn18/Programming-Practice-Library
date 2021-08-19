//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>


#define IN(x,y) 		y.find(x) != y.end()
#define NOT_IN(x,y) 	y.find(x) == y.end()

template <typename T>
using vec2D = std::vector<std::vector<T>>;


enum Axis {
	ROWS,
	COLS
};


bool valid_lines(vec2D<char>& grid, Axis axis){
	std::set<char> line;
	for (int i = 0; i < grid.size(); ++i){
		line.clear();
		for (int j = 0; j < grid.size(); ++j){
			char c = (axis == ROWS) ? grid[i][j] : grid[j][i];
			if (c != '.'){
				if (IN(c, line)){
					return false;
				}
				line.insert(c);
			}
		}
	}
	return true;
}


bool valid_subsquares(vec2D<char>& grid){
	vec2D<std::set<char>> sets(3, std::vector<std::set<char>>(3));

	for (int i = 0; i < grid.size(); ++i){
		for (int j = 0; j < grid.size(); ++j){
			char c = grid[i][j];
			std::set<char>& square = sets[int(i/3)][int(j/3)];
			if (c != '.'){
				if (IN(c, square)){
					return false;
				}
				square.insert(c);
			}
		}
	}
	return true;
}


bool sudoku2(vec2D<char> grid){
    return valid_lines(grid, ROWS) && valid_lines(grid, COLS) && valid_subsquares(grid);
}



int main(){
	vec2D<char> test;
	test = {
		{'2','3','4','5','6','7','8','9','1'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','1','.','.','7'},
		{'.','.','.','.','.','.','1','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'8','.','.','.','.','.','.','.','.'}
	};
	assert(sudoku2(test) == true);
	return 0;
}



