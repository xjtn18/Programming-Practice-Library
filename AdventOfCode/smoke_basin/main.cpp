//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/27/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template<typename T>
using Matrix = vector<vector<T>>;

const int dirs[5] = {0,1,0,-1,0};



vector<pair<int,int>> get_lows(Matrix<int> &mat){
	int m = mat.size();
	int n = mat[0].size();
	static auto in_bounds = [&](int x, int y){
		return x >= 0 && x < m && y >= 0 && y < n;
	};

	vector<pair<int,int>> lows;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (mat[i][j] == -1) continue;
			bool is_low = true;
			for (int d = 0; d < 4; ++d){
				int u = i + dirs[d];
				int v = j + dirs[d+1];
				if (!in_bounds(u,v)) continue;
				if (mat[u][v] <= mat[i][j]){
					is_low = false;
					break;
				}
			}
			if (is_low) lows.push_back({i,j});
		}
	}

	return lows;
}



int dfs(Matrix<int> &mat, int i, int j){
	int m = mat.size();
	int n = mat[0].size();
	static auto in_bounds = [&](int x, int y){
		return x >= 0 && x < m && y >= 0 && y < n;
	};

	int sz = 1;
	int height = mat[i][j];
	mat[i][j] = 9; // mark as visited
	
	for (int d = 0; d < 4; ++d){
		int u = i + dirs[d];
		int v = j + dirs[d+1];
		if (!in_bounds(u,v) || mat[u][v] == 9 || mat[u][v] <= height) continue;
		sz += dfs(mat, u, v);
	}

	return sz;

}


vector<int> get_basins(vector<pair<int,int>> &lows, Matrix<int> &mat){
	vector<int> basins;
	basins.reserve(lows.size());

	for (auto &[i,j] : lows){
		basins.push_back(dfs(mat,i,j));
		std::push_heap(basins.begin(), basins.end()); // heapify the last element
	}

	return basins;
}




int main(){
	fstream file("input.txt");
	string line;
	Matrix<int> mat;

	while (getline(file,line)){
		mat.push_back(vector<int>());
		for (char &c : line){
			mat[mat.size()-1].push_back((int)(c-'0'));
		}
	}

	// Part 1
	vector<pair<int,int>> lows = get_lows(mat);
	int total_risk = 0;
	for (auto &[x,y] : lows) total_risk += mat[x][y] + 1;
	cout << total_risk << endl;


	// Part 2
	
	vector<int> basin_sizes = get_basins(lows, mat);
	cout << std::accumulate(basin_sizes.begin(), basin_sizes.begin()+3, 1,
			[](const int &a, const int &b){ return a * b; })
		<< endl;



	return 0;
}



