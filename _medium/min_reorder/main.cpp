//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created: 9/14/21
//	File type: C++ source file
//	Description: Given a tree of n nodes with n-1 unidirectional roads connecting them, return the 
//						the minimum number roads we need to switch directions so that every node
//						can reach the base node (node 0).
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



int minReorder(int n, vector<vector<int>>& connections) {
	unordered_map<int, unordered_set<int>> roadto;
	unordered_map<int, unordered_set<int>> roadfrom;
	
	for (auto& road : connections){ // fill the map
		roadto[road[0]].insert(road[1]);
		roadfrom[road[1]].insert(road[0]);
	}

	int reorders = 0;
	int city;

	// The stack is just so we can do this iteratively.
	stack<int> stk({0}); // NOTE: stack or queue, doesnt matter as order doesnt matter
	
	while (!stk.empty()){
		city = stk.top(); stk.pop();

		for (auto& next_city : roadto[city]){
			roadfrom[next_city].erase(city);
			stk.push(next_city);
			reorders++;
		}

		for (auto& last_city : roadfrom[city]){
			roadto[last_city].erase(city);
			stk.push(last_city);
		}
	}

	return reorders;
}




int main(){
	vector<vector<int>> connects;

	connects = {{0,1},{1,3},{2,3},{4,0},{4,5}}; // 3
	dlog( minReorder(6, connects) );

	connects = {{1,0},{1,2},{3,2},{3,4}}; // 2
	dlog( minReorder(5, connects) );

	connects = {{0,3},{2,3},{1,3}}; // 1
	dlog( minReorder(4, connects) );

	connects = {{0,1}}; // 1
	dlog( minReorder(2, connects) );

	connects = {{1,0},{2,1},{3,2}}; // 0
	dlog( minReorder(2, connects) );



	return 0;
}



