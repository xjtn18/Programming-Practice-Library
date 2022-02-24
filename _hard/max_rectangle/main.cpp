//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/1/22
//  File type: C++ source file
//  Description: Give a matrix of bits, find the area of
//  		the largest rectangle of set bits.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// original solution, 150ms on LC.

int _maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int area = 0;

	vector<vector<int>> right(m, vector<int>(n, 0));
	vector<vector<int>> down(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i){
		for (int j = n-1, count = 0; j >= 0; --j, ++count){
			if (matrix[i][j] == '1') right[i][j] = count + 1;
			else count = -1;
		}
	}

	for (int j = 0; j < n; ++j){
		for (int i = m-1, count = 0; i >= 0; --i, ++count){
			if (matrix[i][j] == '1') down[i][j] = count + 1;
			else count = -1;
		}
	}


	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			int height = down[i][j];
			int width = right[i][j];
			for (int z = 0; z < height; ++z){
				if (right[i+z][j] <= width){
					width = right[i+z][j];
				}
				area = max(area, width * (z+1));
			}
		}
	}

	return area;
}




// better solution, 36ms on LC.
// TC: O(m*n), where m is rows of the matrix and n is cols of the matrix.
// SC: O(n)

int maxRectangleHistogram(vector<int> &heights){
	stack<int> s;
	int maxSize = 0;
	for (int i = 0; i < heights.size(); i++){
		if (s.empty() || heights[i] >= heights[s.top()]){
			s.push(i);
      } else {
			int h = heights[s.top()];
			s.pop();
			maxSize = max(maxSize, h * (s.empty() ? i : i - 1 - s.top()));
			i--;
		}
	}
	return maxSize;
}

int maximalRectangle(vector<vector<char>> &matrix) {
	if (matrix.empty()) return 0;
	int maxRec = 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<int> heights(n+1, 0);

	for (int i = 0; i < m; i++){
		bool one = false;
		for (int j = 0; j < n; j++){
			if (matrix[i][j] == '0'){
				heights[j] = 0;
			} else {
				one = true;
				heights[j]++;
			}
		}
		if (one) maxRec = max(maxRec, maxRectangleHistogram(heights));
	}
	return maxRec;
}




int main(){
	vector<vector<char>> matrix;

	matrix = {
		{'1','0','0'},
		{'0','1','1'},
		{'0','1','1'},
	};
	dlog(maximalRectangle(matrix)); // 4

	matrix = {
		{'0'}
	};
	dlog(maximalRectangle(matrix)); // 0

	matrix = {
		{'1'}
	};
	dlog(maximalRectangle(matrix)); // 1

	matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'},
	};
	dlog(maximalRectangle(matrix)); // 6

	matrix = {
		{'1','1','1','1','1','1','1','1'},
		{'1','1','1','1','1','1','1','0'},
		{'1','1','1','1','1','1','1','0'},
		{'1','1','1','1','1','0','0','0'},
		{'0','1','1','1','1','0','0','0'},
	};
	dlog(maximalRectangle(matrix)); // 21

	matrix = {
		{'1','1','0','1'},
		{'1','1','0','1'},
		{'1','1','1','1'}
	};
	dlog(maximalRectangle(matrix)); // 6

	matrix = {
		{'1','0','1','1','0','1'},
		{'1','1','1','1','1','1'},
		{'0','1','1','0','1','1'},
		{'1','1','1','0','1','0'},
		{'0','1','1','1','1','1'},
		{'1','1','0','1','1','1'}
	};
	dlog(maximalRectangle(matrix)); // 8

	return 0;
}

