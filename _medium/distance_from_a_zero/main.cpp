//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/30/21
//  File type: C++ source file
//  Description: Given a matrix of 1's and zeroes, return a matrix where the value
//  					at i,j is the shortest distance to a zero from the 1 at i,j in
//  					the given matrix.
//////////////////////////////////////////////////////


// TC
// O(m * n), number of elements in the matrix.
//
// SC
// O(1), you can use the matrix passed in to store the new updated values
// at every stage of the process. My original solution uses 2 extra matrices
// of size (m*n) and the answer matrix, but they are all unecessary. Unless 
// you need the original matrix intact, you can just use the optimal version 
// with constant space.




#include <mystd.h>
using namespace std;



vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	int range = mat.size() * mat[0].size(); 
		// use range rather than INT_MAX because taking INT_MAX + 1
		// overflows goes to INT_MIN, -2147483648.
		// Range will never be INT_MAX because problem constrains
		// m and n to be 10,000, and 10000**2 = 100,000,000 < int_max;
	// SE
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (mat[i][j]){
				int a = (j == 0) ? range : mat[i][j-1];
				int b = (i == 0) ? range : mat[i-1][j];
				mat[i][j] = min(a, b) + 1;
			}
		}
	}


	// NW
	for (int i = m-1; i >= 0; --i){
		for (int j = n-1; j >= 0; --j){
			if (mat[i][j]){
				int a = (j == n-1) ? range : mat[i][j+1];
				int b = (i == m-1) ? range : mat[i+1][j];
				mat[i][j] = min(mat[i][j], min(a, b) + 1);
					// This last line isn't as intuitive, but heres why its works:
					// If we found a valid distance to 0 at cell [i,j] during our first
					// search down the matrix, then min that value with whatever
					// distance we get from searching up the matrix. Even if you stored
					// 2 separate matrices for SE and NW, and them minned every [i,j] to
					// fill your answer matrix, it still wouldnt be correct, because
					// you would miss paths to closest zeroes that fall on the opposite
					// axis (i.e. the SW + NE axis). One way to fix that problem is to use
					// 4 whole seperate matrices for each direction, but TC and SC suffers.
					// However, this can be done with linear SC and 2(m*n) TC like so.
			}
		}
	}

	return mat;
}



int main(){
	vector<vector<int>> mat;

	mat = {{1,1,1},{1,1,1},{1,0,1}};
	hlog(mat);
	hlog( updateMatrix(mat) );


	return 0;
}



