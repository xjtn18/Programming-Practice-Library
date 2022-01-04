//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created: 11/17/21
//	File type: C++ source file
//	Description: Given a 2D array of portals and walls, find the distance of
//                  the shortest path from 'start' position to 'goal' position.
//////////////////////////////////////////////////////


#include <mystd.h>
#include <fstream>
using namespace std;


//
// Solution approach:
// We will loop through the grid once to find the Start node and the Exits.
// We will also set the portals while doing this.
// We will then run djikstras algorithm on the graph from the start node.
// Djikstras will the find the shortest path to every reachable node.
// By extension, this means we will have the shortest paths to all of the reachable exits.
// Whichever reachable exit has the shortest path to the start, the length of that path will be our answer.
//

struct Vertex {
	int id, distance;
	vector<int> neighbors;
	
	Vertex() : id(0), distance(0) {}
	Vertex(int _id) : id(_id) {}
	
	bool operator < (const Vertex &other) const {
		return distance < other.distance;
	}

	bool operator > (const Vertex &other) const {
		return distance > other.distance;
	}
};



vector<int> dijkstras(vector<Vertex> vertices, int start){
	vector<int> dist(vertices.size(), vertices.size()); // set all distances to max (vertices.size())
	priority_queue<Vertex, vector<Vertex>, std::greater<Vertex>> pq;
	unordered_set<int> visited;
	
	Vertex source = vertices[start];
	source.distance = 0;
	dist[start] = 0;
	pq.push(source);
	
	while (!pq.empty()){
		Vertex v = pq.top();
		pq.pop();
		if (!visited.count(v.id)){
			for (int uid : v.neighbors){
				if (!visited.count(uid)){
					int alt = dist[v.id] + 1;
					if (alt < dist[uid]){
						dist[uid] = alt;
						Vertex new_u(vertices[uid]);
						new_u.distance = alt;
						pq.push(new_u);
					}
				}
			}
			visited.insert(v.id);
		}
	}
	
	return dist;
}



int shortest_path_to_exit(vector<vector<char>> G, int R, int C){
	// declare variables
	int start;
	vector<int> exits;
	unordered_map<char, vector<int>> portals;
	const int range = R*C;
	vector<Vertex> vertices(range);
	
	
	// create our graph
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			char value = G[i][j];
			int index = i*C+j;
			if (value == 'E'){
				exits.push_back(index);
			} else if (value == 'S'){
				start = index;
			} else if (value >= 'a' && value <= 'z'){
				portals[value].push_back(index);
			} else if (value == '#'){ // a wall, ignore
				continue;
			}
			// set vertex attributes
			vertices[index].id = index;
			if (i-1 >= 0 && G[i-1][j] != '#'){
				int up = (i-1) * C + j;
				vertices[index].neighbors.push_back(up);
			}
			if (i+1 < R && G[i+1][j] != '#'){
				int down = (i+1) * C + j;
				vertices[index].neighbors.push_back(down);
			}
			if (j-1 >= 0 && G[i][j-1] != '#'){
				int left = i * C + (j-1);
				vertices[index].neighbors.push_back(left);
			}
			if (j+1 < C && G[i][j+1] != '#'){
				int right = i * C + (j+1);
				vertices[index].neighbors.push_back(right);
			}
		}
	}
	
	// connect the portals
	for (auto &channel : portals){
		vector<int> receivers = move(channel.second);
		for (int i = 0; i < receivers.size(); ++i){
			for (int j = i+1; j < receivers.size(); ++j){
				vertices[receivers[i]].neighbors.push_back(receivers[j]);
				vertices[receivers[j]].neighbors.push_back(receivers[i]);
			}
		}
	}
	
	// run dijkstras to get SSSP
	vector<int> dist = dijkstras(vertices, start);
	
	c_log(dist);
	
	// get our answer
	
	int shortest = range; // no path can be longer or equal to range
	for (int &e : exits){
		shortest = min(shortest, dist[e]);
	}
	
	return (shortest != range) ? shortest : -1;
}



int main()
{
	vector<vector<char>> grid = {{}};
	char ch;
	fstream fin("input.txt", fstream::in);
	int i = 0;
	while (fin >> noskipws >> ch) {
		if (fin.peek() == EOF) break;
		if (ch == '\n'){
			grid.push_back(vector<char>());
			i++;
		} else {
			grid[i].push_back(ch);
		}
	}
	cout << grid.size() << " by " << grid[0].size() << endl;
	cout << "opposite corners would be: " << grid.size() + grid[0].size() - 2 << endl;
	cout << shortest_path_to_exit(grid, grid.size(), grid[0].size()) << endl; // expect -1
	
	return 0;
}

