#include <mystd.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;


// ------------- Helpers ------------- //

void sleep(int seconds){
	Sleep(seconds * 1000);
}

int mod(int a, int b){
	return (a%b+b) % b;
}

vector<string> split(string s, string delim=" "){
	vector<string> tokens;
	size_t pos, splt = -1;
	do {
		pos = splt+1;
		splt = s.find(delim, pos);
		tokens.push_back(s.substr(pos, splt-pos));
	} while (splt != string::npos);

	return tokens;
}

vector<string> read_lines(string filepath){
	fstream file;
	file.open(filepath, ios::in);

	vector<string> lines;
	string line;
	while (getline(file, line)){
		lines.push_back(line);
	}

	file.close();
	return lines;
}

// ----------------------------------- //




// ------------ Solution ------------ //

void part_1(vector<string> lines){
	long sigma = 0;
	unordered_map<string, long> m;

	string path = "/";
	for (string l : lines){
		if (l[0] == '$'){
			auto tokens = split(l, " ");
			string command = tokens[1];
			if (command == "cd"){
				string dest = tokens[2];
				if (dest == "/"){
					path = "/";
				} else if (dest == ".."){
					size_t last_slash = path.find_last_of("/");
					path.erase(last_slash);
				} else {
					path += "/" + dest;
				}
			} else if (command == "ls"){
				continue;
			}
		} else {
			auto tokens = split(l, " ");
			if (tokens[0] != "dir"){
				long sz = stoi(tokens[0]);
				if (m.count(path)){
					m[path] += sz;
				} else {
					m[path] = sz;
				}

				// propogate size up
				string cpy = string(path);
				while (cpy != ""){
					size_t last_slash = cpy.find_last_of("/");
					cpy.erase(last_slash);
					if (m.count(cpy)){
						m[cpy] += sz;
					} else {
						m[cpy] = sz;
					}
				}

			} else {
				continue;
			}
		}
	}

	for (auto pair : m){
		//cout << pair.first << " " << pair.second << endl;
		if (pair.second <= 100000){
			sigma += pair.second;
		}
	}
	
	cout << "Answer is: ";
	cout << sigma << endl;
}


void part_2(vector<string> lines){
	long sigma = 0;
	unordered_map<string, long> m;

	string path = "/";
	for (string l : lines){
		if (l[0] == '$'){
			auto tokens = split(l, " ");
			string command = tokens[1];
			if (command == "cd"){
				string dest = tokens[2];
				if (dest == "/"){
					path = "/";
				} else if (dest == ".."){
					size_t last_slash = path.find_last_of("/");
					path.erase(last_slash);
				} else {
					if (path == "/"){
						path += dest;
					} else {
						path += "/" + dest;
					}
				}
			} else if (command == "ls"){
				continue;
			}
		} else {
			auto tokens = split(l, " ");
			if (tokens[0] != "dir"){
				long sz = stoi(tokens[0]);
				if (m.count(path)){
					m[path] += sz;
				} else {
					m[path] = sz;
				}

				// propogate size up
				string cpy = string(path);
				while (cpy != ""){
					size_t last_slash = cpy.find_last_of("/");
					cpy.erase(last_slash);
					if (m.count(cpy)){
						m[cpy] += sz;
					} else {
						m[cpy] = sz;
					}
				}
				m["/"] += sz;

			} else {
				continue;
			}
		}
	}

	long total_size = m["/"];
	long total_space = 70000000;
	long unused = total_space - total_size;
	long smallest = total_space;


	for (auto pair : m){
		if (pair.second + unused >= 30000000){
			smallest = min(smallest, pair.second);
		}
	}
	
	cout << "Answer is: ";
	cout << smallest << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	//part_1(lines);
	part_2(lines);
}


