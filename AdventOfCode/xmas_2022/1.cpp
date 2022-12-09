#include <mystd.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <windows.h>

using namespace std;


// ------------- Helpers ------------- //

vector<string> parse_input(string filepath){
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

int mod(int a, int b){
	return (a%b+b)%b;
}

void split(string s, string delim=" "){
    string token = s.substr(0, s.find(delim));
}

void sleep(int seconds){
	Sleep(seconds * 1000);
}

// ----------------------------------- //




void solve(vector<string> lines){
    for (string l : lines){
        istringstream line(l);

    }
	
	cout << "Answer is: ";
    cout << "";
}






int main(int argc, char *argv[]){
	solve(parse_input("input/day_2.input"));
}
