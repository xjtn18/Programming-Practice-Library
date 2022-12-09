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

	for (string l : lines){
		//string token;
		//istringstream line(l);
		//line >> token;

		//tokens = split(l, " ");
	}
	
	cout << "Answer is: ";
	cout << "" << endl;
}


void part_2(vector<string> lines){

	for (string l : lines){
		//string token;
		//istringstream line(l);
		//line >> token;

		//tokens = split(l, " ");
	}
	
	cout << "Answer is: ";
	cout << "" << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);
}


