#include <speed.hpp>

using namespace std;


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




vector<int> dijkstras(vector<Vertex> &vertices, int start){
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


bool traversable(vector<vector<char>> &G, char current, char next){
	char true_next = next;

	if (next == 'S'){
		true_next = 'a';
	} else if (next == 'E'){
		true_next = 'z';
	}

	return current - true_next < 2;
}



int shortest_path_to_end(vector<vector<char>> G, int R, int C){
	// declare variables
	int start, end;
	const int range = R*C;
	vector<Vertex> vertices(range);
	
	// create our graph
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			char value = G[i][j];
			int index = i*C+j;
			if (value == 'E'){
				end = index;
				value = 'z';
			} else if (value == 'S'){
				start = index;
				value = 'a';
			}

			// set vertex attributes
			vertices[index].id = index;

			if (i-1 >= 0 && traversable(G, value, G[i-1][j])){
				int up = (i-1) * C + j;
				vertices[index].neighbors.push_back(up);
			}
			if (i+1 < R && traversable(G, value, G[i+1][j])){
				int down = (i+1) * C + j;
				vertices[index].neighbors.push_back(down);
			}
			if (j-1 >= 0 && traversable(G, value, G[i][j-1])){
				int left = i * C + (j-1);
				vertices[index].neighbors.push_back(left);
			}
			if (j+1 < C && traversable(G, value, G[i][j+1])){
				int right = i * C + (j+1);
				vertices[index].neighbors.push_back(right);
			}
		}
	}
	
	// run dijkstras to get SSSP
	vector<int> dist = dijkstras(vertices, start);
	c_log(dist);
	
	return dist[end];
}




int shortest_path_to_end_2(vector<vector<char>> G, int R, int C){
	// declare variables
	int start, end;
	const int range = R*C;
	vector<Vertex> vertices(range);
	vector<int> starts;
	
	// create our graph
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			char value = G[i][j];
			int index = i*C+j;
			if (value == 'E'){
				start = index;
				value = 'z';
			} else if (value == 'S'){
				value = 'a';
				starts.push_back(index);
			} else if (value == 'a'){
				starts.push_back(index);
			}

			// set vertex attributes
			vertices[index].id = index;

			if (i-1 >= 0 && traversable(G, value, G[i-1][j])){
				int up = (i-1) * C + j;
				vertices[index].neighbors.push_back(up);
			}
			if (i+1 < R && traversable(G, value, G[i+1][j])){
				int down = (i+1) * C + j;
				vertices[index].neighbors.push_back(down);
			}
			if (j-1 >= 0 && traversable(G, value, G[i][j-1])){
				int left = i * C + (j-1);
				vertices[index].neighbors.push_back(left);
			}
			if (j+1 < C && traversable(G, value, G[i][j+1])){
				int right = i * C + (j+1);
				vertices[index].neighbors.push_back(right);
			}
		}
	}
	
	// run dijkstras to get SSSP
	vector<int> dist = dijkstras(vertices, start);
	
	int shortest = range;
	for (int index : starts){
		shortest = min(shortest, dist[index]);
	}
	return shortest;
}



int main(int argc, char *argv[]) {
	vector<vector<char>> grid;

	string input_path = "input/12.input";
	auto lines = read_lines(input_path);

	char ch;
	int i = 0;

	for (auto line : lines){
		auto l = vector<char>();
		for (char c : line){
			l.push_back(c);
		}
		grid.push_back(l);
	}


	cout << shortest_path_to_end(grid, grid.size(), grid[0].size()) << endl; // expect -1
	cout << shortest_path_to_end_2(grid, grid.size(), grid[0].size()) << endl; // expect -1
	
	return 0;
}


