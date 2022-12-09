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
	int total = 0;

	for (string rucksack : lines){
		int len = rucksack.length();
		unordered_set<char> items;
		for (int i = 0; i < len/2; ++i){
			items.insert(rucksack[i]);
		}

		char x;
		for (int i = len/2; i < len; ++i){
			if (items.count(rucksack[i])){
				x = rucksack[i];
				break;
			}
		}

		int score;
		if (x >= 97){
			score = x - 'a' + 1;
		} else {
			score = x - 'A' + 27;
		}
		total += score;
	}
	
	cout << "Part 1 - Answer is: ";
	cout << total << endl;
}


void part_2(vector<string> lines){
	int total = 0;

	for (int i = 0; i < lines.size(); i += 3){
		string r1 = lines[i], r2 = lines[i+1], r3 = lines[i+2];

		unordered_set<char> items, items2;
		for (int i = 0; i < r1.length(); ++i){
			items.insert(r1[i]);
		}

		for (int i = 0; i < r2.length(); ++i){
			if (items.count(r2[i])){
				items2.insert(r2[i]);
			}
		}

		char x;
		for (int i = 0; i < r3.length(); ++i){
			if (items2.count(r3[i])){
				x = r3[i];
				break;
			}
		}

		int score;
		if (x >= 97){
			score = x - 'a' + 1;
		} else {
			score = x - 'A' + 27;
		}
		total += score;
	}
	
	cout << "Part 2 - Answer is: ";
	cout << total << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	part_1(read_lines(input_path));
	part_2(read_lines(input_path));
}


