//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/6/21
//  File type: C++ source file
//  Description: Given an integer N, return all valid orientations of N queens
//  					on an NxN chess board such that none of the queens are attacking
//  					each other.
//////////////////////////////////////////////////////


//
// My approach:
// I wanted to store a set of integers that represented which lines in the board
// were attacked by a queen so that I could have an O(1) validity check for adding
// a queen in any position, but apparently calling insert and erase for every recursive
// call on a set (or an unordered_set) to update and reset the board state is just too slow. 
// For and n-value of 13, my set solution ran 21 seconds, while the brute force column and
// diagonal check ran only 14 seconds, which is very surprising to me, and I don't fully
// know why that would run so much faster as it seems like a much higher complexity
// from my understanding.
//



#include <mystd.h>
using namespace std;


template <typename T>
using vec2D = vector<vector<T>>;


// OPTIMAL SOLUTION FROM LC DISCUSSION


class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }

    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};




// MY SOLUTION


bool valid_board(unordered_set<int>& lines, int n, int row, int col){
	// takes a board and determines if it meets the problem constraints
	// NOTE: does not need to check for rows, since we are adding queens row by row.

	return ! (lines.count(col + n * 2) || lines.count(row + col) || lines.count(col - row - n));
}



void solve_util(vec2D<string>& res, unordered_set<int>& lines, vector<string>& queens, int n, int row){
	if (row == n){
		res.push_back(queens);
		return;
	}

	for (int col = 0; col < n; ++col){ // for each place in this row where we can place a queen
		if (valid_board(lines, n, row, col)){ // if a queen here is valid, add it and search branches for this choice.
			// update search state
			lines.insert(col + n * 2); // column
			lines.insert(row + col); // negative diagonal
			lines.insert(col - row - n); // positive diagonal
			queens[row][col] = 'Q';

			// search branches after this queen placement
			solve_util(res, lines, queens, n, row + 1);

			// reset search state
			lines.erase(col + n * 2); // column
			lines.erase(row + col); // negative diagonal
			lines.erase(col - row - n); // positive diagonal
			queens[row][col] = '.';
		}

	}

}



vec2D<string> solveNQueens(int n) {
	vec2D<string> solutions;
	vector<string> queens(n, string(n, '.'));
	unordered_set<int> lines;

	solve_util(solutions, lines, queens, n, 0);
	return solutions;
}



int main(){
	
	int n = 11;
	Timer t;
	solveNQueens(n);
	//dlog(valid_board(queens_pos, 10));
	dlog(t.elapsed());
	

	t.reset();
	Solution().solveNQueens(n);
	//Solution().isValid(queens, 9, 8, n);
	dlog(t.elapsed());
	
	return 0;
}



