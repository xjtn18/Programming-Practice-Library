//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>

void rotate_square(std::vector<std::vector<int>>& a, int i, int j){
	int n = a.size(); // n x n matrix
	for (int _ = 0; _ < 3; ++_){ // 3 swaps to cycle a square's points
		std::swap(a[i][j], a[n-j-1][i]); // formula for clockwise rotation means swapping through the counterclockwise points.
		j = std::exchange(i, n-j-1);
	}
}


std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
	for (int i = 0; i < a.size()/2; ++i){
		for (int j = i; j < a.size()-i-1; ++j){
			rotate_square(a,i,j);
		}
	}
	return a;
}



int main(){
	std::vector<std::vector<int>> ans;

	ans = {{7,4,1},{8,5,2},{9,6,3}};
	assert(rotateImage({{1,2,3},{4,5,6},{7,8,9}}) == ans);

	ans = {{3,1},{4,2}};
	assert(rotateImage({{1,2},{3,4}}) == ans);

	ans = {{2}};
	assert(rotateImage({{2}}) == ans);
	return 0;
}



