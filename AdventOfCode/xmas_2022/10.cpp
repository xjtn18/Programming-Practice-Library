#include <speed.hpp>

using namespace std;


// ------------ Solution ------------ //

/*
void part_1(vector<string> lines){

	queue<int> adds;
	int X = 1;
	long sig = 0;

	for (int i = 1; i <= 220; ++i){
		string op, _v;
		if (i < lines.size()){
			auto tokens = split(lines[i], " ");
			assign(tokens, op, _v);
		}

		if (op == "addx"){
			if (adds.empty()) adds.push(0);
			adds.push(stoi(_v));
		}

		if ((i-20) % 40 == 0){
			sig += i*X;
		}

		if (!adds.empty()){
			X += adds.front();
			adds.pop();
		}
	}

	cout << "Part 1 - Answer is: " << sig << endl;
}
*/


bool handle_instruction(string op, string v, int &Z){
	if (op == "addx"){
		Z = stoi(v);
		return true;
	}
	return false;
}

void part_1(vector<string> lines){

	int X = 1, Z = 0;
	bool flag_addx = false;
	long sig = 0;

	for (int i = 0; i <= 220; ++i){
		string op, v;

		if ((i-20) % 40 == 0){
			sig += i*X;
			dlog(i*X);
		}

		X += Z * flag_addx;

		if (!flag_addx && i < lines.size()){
			auto tokens = split(lines[i], " ");
			assign(tokens, op, v);
			flag_addx = handle_instruction(op, v, Z);
		}
	}

	cout << "Part 1 - Answer is: " << sig << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/10.input";
	auto lines = read_lines(input_path);

	part_1(lines);
	//part_2(lines);
}


