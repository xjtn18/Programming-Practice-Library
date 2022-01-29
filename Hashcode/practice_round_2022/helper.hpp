#pragma once
#include <iostream>
using namespace std;
#define uset unordered_set

// this template prints any standard container
template <typename Iter, typename Container>
bool is_last(Iter iter, const Container& cont){
	return (iter != cont.end()) && (next(iter) == cont.end());
}
template <typename Container>
void c_log(Container l, bool nl = true){
	cout << '[';
	for (auto iter = l.begin(); iter != l.end(); ++iter){
		cout << *iter;
		if (!is_last(iter,l))
			cout << ", ";
	}
	cout << ']';
	if (nl) cout << "\n";
}

////////////////////////////////////////////////////////////////////


enum Color { RED, GREEN, WHITE };

struct Vertex {
	static int ID;
	int id = 0;
	Color color = WHITE;
	uset<int> neighbors;

	Vertex() : id(ID++) { }
	Vertex(int _id) : id(_id) { }

	void add_neighbor(int nid){
		neighbors.insert(nid);
	}

	void remove_neighbor(int nid){
		neighbors.erase(nid);
	}

	int degree() const {
		return neighbors.size();
	}

	void print() const {
		cout << "Vertex " << id << ": ";
		c_log(neighbors);
	}
};
int Vertex::ID = 0;



struct Client {
	int id;
	uset<string> likes, hates;

	Client() { }

	bool like(const string &ingred) const {
		return likes.count(ingred);
	}

	bool hate(const string &ingred) const {
		return hates.count(ingred);
	}

	bool conflicts(const Client &other){
		for (const string &i : likes)
			if (other.hate(i)) return true;
		for (const string &i : hates)
			if (other.like(i)) return true;
		return false;
	}
};


void parse_input(const string filename, unordered_set<string> &ingredients, vector<Client> &clients){
	ifstream fs(filename);
	if (!fs) throw std::runtime_error(
			"\n!! ERROR !! Cannot load, \"" + filename + ".graph\" not found.");
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

	fs.close();
}

