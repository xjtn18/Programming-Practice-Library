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
		tokens.push_back(s.substr(pos, splt));
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
	string s = lines[0];
	unordered_set<char> sset;

	int ans;
	int start = 0;
	while (start < s.length()){
		bool marker = true;
		for (int i = start; i < start + 4; ++i){
			if (i < s.length()){
				if (sset.count(s[i])){
					sset.clear();
					start += 1;
					marker = false;
					break;
				} else {
					sset.insert(s[i]);
				}
			}
		}
		if (marker){
			ans = start + 4;
			break;
		}
	}
	
	cout << "Answer is: ";
	cout << ans << endl;
}


void part_2(vector<string> lines){

	string s = lines[0];
	unordered_set<char> sset;

	int ans;
	int start = 0;
	while (start < s.length()){
		bool marker = true;
		for (int i = start; i < start + 14; ++i){
			if (i < s.length()){
				if (sset.count(s[i])){
					sset.clear();
					start += 1;
					marker = false;
					break;
				} else {
					sset.insert(s[i]);
				}
			}
		}
		if (marker){
			ans = start + 14;
			break;
		}
	}
	
	cout << "Answer is: ";
	cout << ans << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);
}


