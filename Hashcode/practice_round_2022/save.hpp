#pragma once
#include <helper.hpp>
#include <fstream>
#include <sstream>
using namespace std;


void save_graph(vector<Vertex> &graph, string filename){
	ofstream fs("graphs/" + filename + ".graph");

	for (Vertex &v : graph){
		fs << v.id << " " << v.degree();
		for (int nid : v.neighbors){
			fs << " " << nid;
		}
		fs << "\n";
	}

	fs.close();
}


vector<Vertex> load_graph(string filename){
	ifstream fs("graphs/" + filename + ".graph");
	if (!fs) throw std::runtime_error(
			"\n!! ERROR !! Cannot load, \"" + filename + ".graph\" not found. Run 'save' rule first.");
	string token;
	vector<Vertex> graph;

	while (fs >> token){
		Vertex v(stoi(token));
		fs >> token;
		int degree = stoi(token);
		for (int i = 0; i < degree; ++i){
			fs >> token;
			v.add_neighbor(stoi(token));
		}
		graph.push_back(std::move(v));
	}

	fs.close();

	return graph;
}




