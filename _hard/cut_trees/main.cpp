//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/12/21
//  File type: C++ source file
//  Description: Given a 2d array of ints, where 0 means you cannot cross, 1 means you can, and > 1 means there
//  					is a tree here of this height, find the minimum number of steps needed to traverse the array
//  					and cut down all of the trees is ascending order of their height...
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



template <typename T>
using vec2D = vector<vector<T>>;


//const vector<pair<int, int>> START = {{0,1}, {1,0}, {0,-1}, {-1,0}};
//const vector<pair<int, int>> FROM_NORTH = {{0,1}, {0,-1}, {-1,0}};
//const vector<pair<int, int>> FROM_SOUTH = {{0,1}, {1,0}, {0,-1}};
//const vector<pair<int, int>> FROM_EAST = {{1,0}, {0,-1}, {-1,0}};
//const vector<pair<int, int>> FROM_WEST = {{0,1}, {1,0}, {-1,0}};

    
void explore(vec2D<int>& forest, int i, int j, int steps, int& ntrees, int& min_steps){
	dlog("exploration!");
	if (forest[i][j] > 1){ // if theres a tree here, cut it down
		ntrees--;
	}

	if (ntrees == 0){ // no more trees left to cut down, stop exploring
		dlog("oops!");
		min_steps = min(steps, min_steps);

	} else { // keep exploring this branch
		int nexti;
		int nextj;
		static const vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		for (auto& [di,dj] : dirs){
			nexti = i + di;
			nextj = j + dj;
			if (nexti >= forest.size() || 
					nextj >= forest[0].size() || 
					forest[nexti][nextj] == 0)
			{ // if out of bounds or blocked, skip it
				continue;
			}

			steps++;
			int height = std::exchange(forest[i][j], 1);

			explore(forest, nexti, nextj, steps, ntrees, min_steps);

			steps--;
			forest[i][j] = height;
		}

	}

	if (forest[i][j] > 1){ // if there was a tree here, pretend you never cut it
		ntrees++;
	}
}


int cutOffTree(vec2D<int>& forest) {
	int min_steps = forest.size() * forest[0].size(); // initialize to the maximum (m*n steps)

	// count the number of trees
	int ntrees = 0;
	for (int i = 0; i < forest.size(); ++i){
		for (int j = 0; j < forest[0].size(); ++j){
			 if (forest[i][j] > 1){
				  ntrees++;
			 }
		}
	}

	explore(forest, 0, 0, 0, ntrees, min_steps);
	return min_steps;
}




int main(){
	vector<vector<int>> forest;


	forest = {{1,2,3},{0,4,0},{7,6,5}};
	hlog(forest);
	dlog( cutOffTree(forest) );


	return 0;
}



