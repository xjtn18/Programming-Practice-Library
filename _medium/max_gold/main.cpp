//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created: 12/26/21
//	File type: C++ source file
//	Description: Given a grid where grid[i][j] reps the amount of gold in that cell,
//						return the maximum amount of gold you can collect by not walking
//						in cells with zero gold and not backtracking. You can choose the
//						starting cell.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template <typename T>
using V2 = vector<vector<T>>;
static int dirs[] = {0,1,0,-1,0};
 
 
int maxGold(V2<int> &grid, int i, int j){
	static auto valid = [&](int x, int y){ return x >= 0 && x < grid.size() && 
		y >= 0 && y < grid[0].size() && grid[x][y] != 0; };

	int original = std::exchange(grid[i][j], 0);
	int maxg = 0;

	for (int d = 0; d < 4; ++d){
		int ni = i + dirs[d];
		int nj = j + dirs[d+1];
		if (valid(ni, nj)){
			 maxg = max(maxg, maxGold(grid, ni, nj));
		}
	}

	grid[i][j] = original;

	return grid[i][j] + maxg;
}


int getMaximumGold(V2<int>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	int ans = 0;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (grid[i][j] != 0){
				ans = max(ans, maxGold(grid, i, j));
			}
		}
	}

	return ans;
}




int main(){
	V2<int> grid;

	grid = {{0,6,0},{5,8,7},{0,9,0}};
	cout << getMaximumGold(grid) << endl; // 24


	grid = {{1,0,7}, {2,0,6}, {3,4,5}, {0,3,0}, {9,0,20}};
	cout << getMaximumGold(grid) << endl; // 28

	grid = {{0}};
	cout << getMaximumGold(grid) << endl; // 0

	grid = {{14, 0}, {0,16}};
	cout << getMaximumGold(grid) << endl; // 16

	grid ={{1,0,7,0,0,0},
			 {2,0,6,0,1,0},
			 {3,5,6,7,4,2},
			 {4,3,1,0,2,0},
			 {3,0,5,0,20,0}};
	cout << getMaximumGold(grid) << endl; // 60

	return 0;
}



