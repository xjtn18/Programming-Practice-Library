//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/19/21
//  File type: C++ source file
//  Description: Given a graph, return the edges that if removed would split the graph.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



// the graph representation
vector<vector<int>> adj;
vector<int> dfs_index;
vector<int> lowlink;

vector<vector<int>> answer;



void tarjan(int v, int predecessor = -1){
	static int index = 0;

	dfs_index[v] = index;
	lowlink[v] = index;
	index++;

	for (auto &neighbor : adj[v]){
		if (dfs_index[neighbor] == -1){
			tarjan(neighbor, v);
			if (lowlink[neighbor] > dfs_index[v]){ // this neighbor is part of a different component
				answer.push_back( std::move(vector<int>({v, neighbor}) ));
			}
			lowlink[v] = min(lowlink[neighbor], lowlink[v]);

		} else if (neighbor != predecessor){
			// Second condition must be true because the graph is undirected,
			// and we dont want to link leaf nodes to the components they stem from.
			lowlink[v] = min(dfs_index[neighbor], lowlink[v]);
		}
	}

}



vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
	answer = vector<vector<int>>();
	adj = vector<vector<int>>(n);
	dfs_index = vector<int>(n, -1);
	lowlink = vector<int>(n,0);

	for (auto& edge : connections){
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]); // undirected
	}

	// run tarjan's to assign vertices to SCC's (strongly connected components)
	tarjan(0);
	//NOTE: Because we know this graph is connected undirected network,
	// we only need to call tarjan once on any arbitrary vertex,
	// it will traverse every vertex in the graph and assign in
	// a lowlink value, a.k.a. the root vertex id that represents
	// which SCC that vertex is a part of.

	return answer;
}






int main(){
	int n;
	vector<vector<int>> connections;
	vector<vector<int>> answer;

	n = 4;
	connections = {{0,1},{1,2},{2,0},{1,3}};
	hlog( criticalConnections(n, connections) );

	n = 6;
	connections = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}};
	hlog( criticalConnections(n, connections) );

	n = 4;
	connections = {{0,1},{2,3},{3,1}};
	hlog(criticalConnections(n, connections));

	n = 3;
	connections = {{0,1},{1,2}};
	hlog(criticalConnections(n, connections));

	n = 3;
	connections = {{0,1}, {1,2}, {2,0}};
	hlog(criticalConnections(n, connections));

	dlog("here");
	connections = {{1,0},{0,2},{2,1},{1,3},{3,4},{4,5},{5,3}};
	hlog(criticalConnections(6, connections));


	return 0;
}



