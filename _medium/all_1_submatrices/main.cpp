//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/9/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


int numSubmat(vector<vector<int>>& mat){
	int num = (m*(m+1) * n*(n+1)) / 4;
	int m = mat.size(), n = mat[0].size();
	int mm = m, nn == n;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (mat[i][j] == 0){
				num -= (i+1) * (m-i);
				num -= (j+1) * (n-i);
			}
		}
	}

	return num;
}



int main(){
	vector<vector<int>> mat;

	mat = {{1,1,1},{1,1,1},{1,1,1}};
	cout << numSubmat(mat) << endl;

	return 0;
}



