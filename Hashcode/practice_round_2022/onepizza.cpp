////////////////////////////////////////////////////////////
// Google Hashcode 2022: Practice Round
// Team: 3 Guys Hashes & Tries
// Members: Jacob Nardone, Nathan Mactal, Austin Merrick
// File type: C++ source file
// Date Created: 1/19/22
////////////////////////////////////////////////////////////

#include <string>
#include <random>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <atomic>

#include <save.hpp>
using namespace std;

string TESTFILE = "a";
string GRAPHMODE = "SAVE";

std::atomic<unsigned int> best_seed = 0;
std::atomic<unsigned int> max_average = 0;
std::mutex mtx;

bool will_client_eat(const Client &client, uset<string> &pizza){
	// Returns whether or not the pizza has all the clients likes and none of their dislikes.
	for (const string &ingred : client.likes)
		if (!pizza.count(ingred)) return false;
	for (const string &ingred : client.hates)
		if (pizza.count(ingred)) return false;
	return true;
}


int happy_clients(vector<Client> &clients, uset<string> &pizza){
	// given a pizza, returns how many customers this pizza will bring in.
	int count_ = 0;
	for (Client &c : clients){
		count_ += will_client_eat(c, pizza);
	}
	return count_;
}


void remove_vertex(vector<Vertex> &graph, Vertex &v){
	v.color = RED;
	for (const int &nid : v.neighbors){
		if (graph[nid].color == WHITE) graph[nid].remove_neighbor(v.id);
	}
}

void remove_neighbors(vector<Vertex> &graph, Vertex &v){
	for (const int &nid : v.neighbors){
		if (graph[nid].color == WHITE) remove_vertex(graph, graph[nid]);
	}
}


template <typename T>
void my_shuffle(vector<T> &v){
	for (int i = v.size()-1; i > 0; --i){
		int j = std::rand() % (i+1);
		std::swap(v[i], v[j]);
	}
}


vector<Vertex> get_conflict_graph(vector<Client> &clients){
	int n = clients.size();
	vector<Vertex> graph;

	if (GRAPHMODE == "SAVE"){
		graph = vector<Vertex>(n);
		//printf("Building graph...\n");
		for (int i = 0; i < n; ++i){
			for (int j = i+1; j < n; ++j){
				if (clients[i].conflicts(clients[j])){
					graph[i].add_neighbor(j);
					graph[j].add_neighbor(i);
				}
			}
		}
		save_graph(graph, TESTFILE);

	} else if (GRAPHMODE == "LOAD"){
		//printf("Loading graph...\n");
		graph = load_graph(TESTFILE);
	}

	return std::move(graph);
}


uset<string> best_pizza(vector<Client> &clients){
	//std::random_device rd;
	//std::mt19937 gen(rd());

	uset<string> pizza;
	int n = clients.size();
	vector<Vertex> graph = get_conflict_graph(clients);

	//printf("Coloring graph...\n");
	vector<int> vertexheap(n);
	std::iota(vertexheap.begin(), vertexheap.end(), 0); // fill array with vertex ID's

	// Vertex comparison lambda
	auto VertexComp = [&graph](int &a, int &b){
		return graph[a].degree() > graph[b].degree();
	};

	//my_shuffle(vertexheap);
	//std::shuffle(vertexheap.begin(), vertexheap.end(), gen);

	while (!vertexheap.empty()){
		std::make_heap(vertexheap.begin(), vertexheap.end(), VertexComp);
		int low_id = vertexheap.front();

		if (graph[low_id].color == WHITE){
			graph[low_id].color = GREEN;
			for (const string &ingred : clients[low_id].likes)
				pizza.insert(ingred);
			remove_neighbors(graph, graph[low_id]);
		}
		std::pop_heap(vertexheap.begin(), vertexheap.end(), VertexComp); // swaps front and back, sifts down
		vertexheap.pop_back();
	}

	//printf("Done.\n\n");
	return pizza;
}



// Find an optimal random seed that yeilds a pizza with a maximum average number of clients
// 		with regards to testcases D and E. 
void optimize_routine(vector<Client> &d_clients, vector<Client> &e_clients){
	mtx.lock();
	unsigned int seed;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 99999);
	seed = dis(gen);
	//seed = 25369;
	//srand(seed);

	uset<string> pizza;
	unsigned int num_clients = 0;

	TESTFILE = "d.txt";
	pizza = best_pizza(d_clients);
	num_clients += happy_clients(d_clients, pizza);
	cout << "num clients for testcase d: " << num_clients << endl;

	TESTFILE = "e.txt";
	pizza = best_pizza(e_clients);
	int enumcl = happy_clients(e_clients, pizza);
	num_clients += enumcl;
	cout << "num clients for testcase e: " << enumcl << endl;

	unsigned int avg = num_clients/2;
	cout << "this seed was: " << seed << endl;
	cout << "the avg for this thread is: " << avg << endl;
	if (avg > max_average){
		max_average = avg;
		best_seed = seed;
	}
	mtx.unlock();
}


int main(int argc, char *args[]){
	GRAPHMODE = args[1];
	int NUM_THREADS = stoi(args[2]);
	TESTFILE = args[3];

	uset<string> ingredients;
	vector<Client> d_clients, e_clients;

	// parse both d and e
	parse_input("testcases/d.txt", ingredients, d_clients);
	parse_input("testcases/e.txt", ingredients, e_clients);
	/*
	cout << "TOTAL CLIENTS: " << clients.size() << endl;
	cout << "TOTAL INGREDIENTS: " << ingredients.size() << endl;
	cout << "---------------------\n" << endl;
	*/

	vector<std::thread> threads;
	// start threads
	for (int i = 0; i < NUM_THREADS; ++i){
		threads.emplace_back(optimize_routine, std::ref(d_clients), std::ref(e_clients));
	}
	// wait for threads to finish
	for (auto &thr : threads){
		thr.join();
	}

	printf("Best seed = %u\n", best_seed.load());
	printf("Max avg = %u\n", max_average.load());
}


