#include "../../debug.h"
#include <unordered_set>
#include <queue>
#include <fstream>
#include <limits>
#include <algorithm>
#include <functional>


class Edge {
	int src;
	int dst;
	int weight;

public:
	// Time Complexity = O(1)
	Edge(int s, int d, int w)
		: src{s}, dst{d}, weight{w} { }


	// Time Complexity = O(1)
	Edge reverse(){
		return Edge(dst, src, weight);
	}

	// Time Complexity = O(1)
	void print(std::ostream& out){
		out << "[ " << src << "-" << dst << " ] ( " << weight << " )\n";
	}

	//getters

	// Time Complexity = O(1)
	int get_src() const {return src;}

	// Time Complexity = O(1)
	int get_dst() const {return dst;}

	// Time Complexity = O(1)
	int get_weight() const {return weight;}


};




class Vertex {
	int id;
	int total_weight;
	std::vector<Edge> edges;

public:
	// Time Complexity = O(1)
	Vertex(int i = 0)
		: id{i}, total_weight{(int)std::numeric_limits<int>::max()} { }
	

	// Time Complexity = O(1)
	void add_edge(const Edge& e){
		edges.push_back(e);
	}


	// Time Complexity = O(|E|)
		// E being the number of outgoing edges for this vertex
	void print(std::ostream& out){
		for (Edge e : edges)
			e.print(out);
	}

	// Time Complexity = O(1)
	bool operator < (Vertex& right){
		return this->id < right.id;
	}


	// Time Complexity = O(1)
	int getID() const {return id;}

	// Time Complexity = O(1)
	int getTotalWeight() const {return total_weight;}

	// Time Complexity = O(1)
	void setID(int x) {id = x;}

	// Time Complexity = O(1)
	void setTotalWeight(int x) {total_weight = x;}
	// This tracks the lowest weighted path so far from source to this vertex


	// Time Complexity = O(1)
	const std::vector<Edge>& get_edges() const {
		return edges;
	}

	bool operator < (const Vertex& other) const {
		return this->getTotalWeight() < other.getTotalWeight();
	}

	bool operator > (const Vertex& other) const {
		return this->getTotalWeight() > other.getTotalWeight();
	}

};






class Graph {

	Vertex* vertices;
	int num_vertex;
	int num_edge;
	bool undirected;

public:
	// Time Complexity = O(|V|)
	static void set_all_id(Vertex* v, int size){
		for (int x = 0; x < size; ++x){
			v[x].setID(x);
		}
	}

	// Time Complexity = O(N)
	Graph(std::string filename, bool _undirected = false) : undirected(_undirected){
		std::ifstream in(filename);
		std::string line;

		std::getline(in, line); //read amount of vertices
		num_vertex = std::stoi(line);
		num_edge = 0;
		vertices = new Vertex[num_vertex];
		Graph::set_all_id(vertices, num_vertex);

		int src, dst, wgt;
		std::string token;
		while (getline(in, line)){
			std::stringstream ss(line);
			std::getline(ss, token, ' '); src = std::stoi(token);
			std::getline(ss, token, ' '); dst = std::stoi(token);
			std::getline(ss, token, ' '); wgt = std::stoi(token);
			add_edge(src, dst, wgt);
		}
		in.close();
	}

	// Time Complexity = O(1)
	void add_edge(int s, int d, int w){
		Edge new_edge(s,d,w);
		vertices[s].add_edge(new_edge);
		if (undirected){
			vertices[d].add_edge(new_edge.reverse());
		}
		num_edge++;

	}
	

	// Time Complexity = O(|V| * |E|)
	void print(std::ostream& out){
		for (int i = 0; i < num_vertex; ++i){
			out << "\nNEXT V:\n";
			vertices[i].print(out);
		}
	}


	// Time Complexity = O(1)
	const Vertex* getVertices() const {return vertices;}

	// Time Complexity = O(1)
	int getNumVertex() const {return num_vertex;}

	// Time Complexity = O(1)
	~Graph(){
		delete[] vertices;
	}

};




template <typename C>
class MutablePQ {

	std::vector<Vertex> vec;
	int size;
	C comparator;

	/*
	void siftUp(int index){
		while (index > 0){
			int parent = (index - 1) / 2; // int vars always rounds down, so this is safe.
			if (this->comparator(vec[parent].getTotalWeight(), vec[index].getTotalWeight())){
				std::swap(vec[index], vec[parent]);
				std::swap(index, parent);
			} else { // we dont need to sift up anymore
				break;
			}
		}
	}
	*/



public:
	
	MutablePQ() : size(0) {}

	void push(const Vertex vtex){
		vec.push_back(vtex);
		std::push_heap(vec.begin(), vec.end(), this->comparator); // O(log n)
		size++;
	}

	const Vertex& top() const {
		return vec[0];
	}

	Vertex pop(){
		Vertex ret = vec[0]; // min element
		std::pop_heap(vec.begin(), vec.end(), this->comparator); // moves max to bottom and keeps heap invariant
		vec.pop_back(); // actually removes the max, which was just pushed to the back
		size--;
		return ret;
	}

	
	/*
	void update(int key, int newVal){
		int index = find(key);
		if (index == -1){
			return;
		}
		vec[index].setTotalWeight(newVal);
		siftUp(index);
	}
	*/

	bool empty() const {
		return vec.empty();
	}


	void print() const {
		for (const Vertex& v : vec){
			std::cout << v.getID() << " ";
		}
		std::cout << "\n";
	}

};






void dijkstras(Graph& g, int source, int* dist, int* pre){
	MutablePQ<std::greater<>> PQ; // greater as the comparator actually means this is a MIN HEAP.
	std::unordered_set<int> checked;
	int numv = g.getNumVertex();
	const Vertex *verts = g.getVertices();

	// Initialization
	for (int i = 0; i < numv; ++i){
		dist[i] = std::numeric_limits<int>::max();
		pre[i] = -1;
	}

	for (int i = 0; i < numv; ++i){
		std::cout << pre[i] << "  ";
		std::cout << dist[i] << "  ";
	}

	dist[source] = 0; // distance to source is 0
	Vertex start = verts[source];
	start.setTotalWeight(0);
	PQ.push(start);


	// main loop
	while (!PQ.empty()){
		Vertex minv = PQ.pop();
		int u = minv.getID();
		if (checked.find(u) == checked.end()){ // since we are adding updated nodes to the queue rather than changing old ones
			//checked.insert(u);
			for (Edge e : minv.get_edges()){
				log("yeeeee");
				int v = e.get_dst(); // get the neighboring vertex
				int alt = dist[u] + e.get_weight();
				if (checked.find(v) == checked.end() && alt < dist[v]){
					log("ummmm");
					// if the path to v from this node is shorter than our current shortest path v, update that.
					dist[v] = alt;
					pre[v] = u;
					//PQ.update(v, alt); // v's shortest weight (total_weight) has changed, 
										// so we need to sift it to the correct position in the PQ.
										// UPDATE: You dont need this update function. If you can make a copy of the node,
										// you can just add that vertex back to the priority queue. This prevents having
										// to search for the key in the priority queue (which would take linear time
										// without some kind of map to the index) and manually calling sift up.
										// Adding a duplicate to the PQ does not break the alg.
										// Just make sure to skip the old nodes by keeping the keys in a set for constant 'find' time.
					Vertex updated(verts[v]);
					updated.setTotalWeight(alt);
					PQ.push(updated);
				}
			}
		}
	}
}



std::vector<int> readSSP(int *dist, int *pre, int numv, int source, int target){
	std::vector<int> pth;
	int i = target;
	while (i != source){
		if (pre[i] == -1){ return pth; } // no path was found at all
		pth.push_back(i);
		i = pre[i];
	}

	pth.push_back(source);
	std::reverse(pth.begin(), pth.end());

	return pth;
}



// Time Complexity = O((|E| + |V|) log |V|)
int main(int argc, char* argv[]){
	if (argc < 3) exit(-1);
	std::string filename = argv[1];
	int source = std::stoi(argv[2]);
	bool undirected = argv[2];
	Graph my_graph(filename, std::stoi(argv[3]));

	// call djikstras and print result

	int numv = my_graph.getNumVertex();
	int *dist = new int[numv];
	int *pre = new int[numv];

	dijkstras(my_graph, source, dist, pre); // compute SSSP (fills dist and pre)

	for (int i = 0; i < numv; ++i){
		std::cout << pre[i] << "  ";
		std::cout << dist[i] << "  ";
	}
	std::cout << "\n";

	for (int i = 0; i < numv; ++i){ // prints SSSP for all possible targets
		std::vector<int> ssp = readSSP(dist, pre, numv, source, i);
		std::cout << i << " -> ";
		log(ssp, false);
		if (!ssp.empty()){
			log(" (" + std::to_string(dist[i]) + ")");
		} else {
			log(" (no path)");
		}
		log("");
	}


	delete[] dist;
	delete[] pre;
	return 0;
}


