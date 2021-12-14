//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
	int m = mat.size();
	int n = mat[0].size();
	int ndiags = m + n - 1;
	vector<int> row, col;
	// calculate left column indices
	for (int i = 0; i < m; ++i){
		row.push_back(i);
		col.push_back(0);
	}
	// calculate top row indices
	for (int i = 1; i < n; ++i){
		row.push_back(0);
		col.push_back(i);
	}

	vector<vector<int>> ans(m, vector<int>(n));
	
	for (int d = 0; d < ndiags; ++d){ // for each diagonal
		vector<int> diag;
		int i = row[d];
		int j = col[d];
		for (; i < m && j < n; i++, j++){
			diag.push_back(mat[i][j]);
		}

		sort(diag.begin(), diag.end());

		i = row[d];
		j = col[d];
		for (int &val : diag){
			ans[i++][j++] = val;
		}
	}

	return ans;

}


int main(){
	vector<vector<int>> mat;

	mat = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
	hlog(diagonalSort(mat));

	return 0;
}



