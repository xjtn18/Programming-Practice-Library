#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <random>
#include <helper.hpp>
using namespace std;

#define uset unordered_set
const string TESTFILE = "a.txt";

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/* Approach:
	We will create a graph of the clients, where vertices represent each client and the edges
	between them represent conflicts of interest (one likes an ingredient that the other
	person dislikes). Having conflicted interests means we can not create a pizza that
	appeases both of these clients. So, it makes sense that the optimal pizza is the one that
	contains the ingredients of the clients that form the MAXIMUM INDEPENDENT SET (MIS) of 
	vertices within the graph. Finding this set is NP-Hard.
	Rather than doing a straight greedy approach of finding any single maximally independent
	set, we will do slightly better and sort the vertices by their degree; degrees will be
	updated as we select nodes for our set: nodes that are selected must be removed from the
	graph, as well as their neighbors (because we cant select 2 nodes (or clients) that have
	a conflict of interest (an edge) between them).
	This is never gauranteed to find the MAXIMUM independent set as there are certain complex
	graph structures that prevent this algorithm from finding it. It mainly comes down to the
	order in which we select nodes for our set if multiple nodes have the same degree, and
	for other crazy graphs, vertices that have a distinct lowest degree in the graph may not
	even actually be in the maximum independent set.
	To avoid running random swaps on the ingredients and seeing what brings in more customers 
	(which is nearly equivalent to doing a brute force solution), we will shuffle the array of
	vertices under different random seeds for short time. Different seeds will change the way
	in which the vertex heap will sort same-degree vertices. We will then run the degree-based
	MIS algorithm and store whichever pizza yeilds the most customers.
*/
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void remove_vertex(vector<Vertex> &graph, Vertex &v){
	v.color = RED;
	for (const int &nid : v.neighbors){
		if (graph[nid].color == WHITE) graph[nid].remove_neighbor(v.id);
	}
}

void remove_neighbors(vector<Vertex> &graph, Vertex &v){
	for (const int &nid : v.neighbors){
		remove_vertex(graph, graph[nid]);
	}
}

template <typename T>
void my_shuffle(vector<T> &v){
	for (int i = v.size()-1; i > 0; --i){
		int j = std::rand() % (i+1);
		std::swap(v[i], v[j]);
	}
}

uset<string> best_pizza(uset<string> &ingredients, vector<Client> &clients){
	uset<string> pizza;
	int n = clients.size();
	vector<Vertex> graph(n);

	printf("Building graph...\n");
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			if (clients[i].conflicts(clients[j])){
				graph[i].add_neighbor(j);
				graph[j].add_neighbor(i);
			}
		}
	}

	printf("Coloring graph...\n");
	vector<int> vheap(n);
	std::iota(vheap.begin(), vheap.end(), 0); // fill array with vertex ID's
	auto VertexComp = [&graph](int &a, int &b){ return graph[a].degree() > graph[b].degree(); };

	my_shuffle(vheap);

	while (!vheap.empty()){
		std::make_heap(vheap.begin(), vheap.end(), VertexComp);
		int low_id = vheap.front();
		if (graph[low_id].color == WHITE){
			graph[low_id].color = GREEN;
			// add this clients liked ingredients to the pizza
			for (const string &ingred : clients[low_id].likes) pizza.insert(ingred);
			remove_neighbors(graph, graph[low_id]);
		}
		std::pop_heap(vheap.begin(), vheap.end(), VertexComp); // swaps front and back, sifts down
		vheap.pop_back();
	}

	printf("Done.\n\n");
	return pizza;
}


bool will_client_eat(const Client &client, uset<string> &pizza){
	// Returns whether or not the pizza has all the clients likes and none of their dislikes.
	for (const string &ingred : client.likes)
		if (!pizza.count(ingred)) return false;
	for (const string &ingred : client.hates)
		if (pizza.count(ingred)) return false;
	return true;
}


int happy_clients(vector<Client> &clients, uset<string> &pizza){
	int count_ = 0;
	for (Client &c : clients){
		count_ += will_client_eat(c, pizza);
	}
	return count_;
}


void parse_input(unordered_set<string> &ingredients, vector<Client> &clients){
	ifstream fs("testcases/" + TESTFILE);
	string token;
	int amount;
	fs >> token; // number of clients

	while (fs >> token){
		Client client;

		amount = stoi(token);
		while (amount-- > 0){
			fs >> token;
			ingredients.insert(token);
			client.likes.insert(token);
		}

		fs >> token;
		amount = stoi(token);
		while (amount-- > 0){
			fs >> token;
			ingredients.insert(token);
			client.hates.insert(token);
		}

		clients.push_back(move(client));
	}
}


string answer_string(uset<string> &pizza){
	string s = std::to_string(pizza.size());
	for (const string &ingredient : pizza)
		s += " " + ingredient;
	return s;
}


int main(){
	// set random seed
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9999);

	uset<string> ingredients;
	vector<Client> clients;

	parse_input(ingredients, clients);
	cout << "TOTAL CLIENTS: " << clients.size() << endl;
	cout << "TOTAL INGREDIENTS: " << ingredients.size() << endl;
	cout << "---------------------\n" << endl;

	int best_seed = 0;
	int max_clients = 0;
	uset<string> pizza, optimal_pizza;
	// run some loops to get random seeds; compare results from different seeds
	for (int i = 0; i < 15; ++i){
		int seed = dis(gen);
		srand(seed);
		pizza = best_pizza(ingredients, clients);
		int num_clients = happy_clients(clients, pizza);
		if (num_clients > max_clients){
			max_clients = num_clients;
			best_seed = seed;
			optimal_pizza = std::move(pizza);
		}
	}

	cout << "Best seed found is " << best_seed << ".\n";
	cout << "Yeilded " << max_clients << " happy customers.\n";

	// write our answer to a file
	//ofstream fs("answers/c_answer.txt");
	//fs << answer_string(optimal_pizza);
	//fs.close();
}


