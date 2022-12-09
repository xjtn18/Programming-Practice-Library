#include <speed.hpp>

using namespace std;


// ------------ Solution ------------ //

void part_1(vector<string> lines){

	for (string l : lines){
		//string token;
		//istringstream line(l);
		//line >> token;

		//auto tokens = split(l, " ");
	}
	
	cout << "Part 1 - Answer is: " << "" << endl;
}


void part_2(vector<string> lines){

	for (string l : lines){
		//string token;
		//istringstream line(l);
		//line >> token;

		//auto tokens = split(l, " ");
	}
	
	cout << "Part 2 - Answer is: " << "" << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);
}


