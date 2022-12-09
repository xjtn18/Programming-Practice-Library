#include <mystd.h>
#include <fstream>
#include <unordered_map>
#include <windows.h>



int mod(int a, int b){
	return (a%b+b)%b;
}

enum M {
	paper = 0,
	scissors,
	rock
};

std::unordered_map <int, M> fuckyou
{
	{0, M::paper},
	{1, M::scissors},
	{2, M::rock},
};

std::unordered_map<char, M> m
{
	{'A', M::rock},
	{'B', M::paper},
	{'C', M::scissors},
	{'X', M::rock},
	{'Y', M::paper},
	{'Z', M::scissors}
};

std::unordered_map<M, int> score
{
	{M::rock, 1},
	{M::paper, 2},
	{M::scissors, 3},
};




void parse_input(){
	std::fstream file;
	file.open("day_2.input", std::ios::in);

	std::string line;
	char opp_move, my_move;
	long total = 0;
	while (true){
		file >> opp_move >> my_move;
		if (file.eof()) break;

		total += score[m[my_move]];
		int diff = m[opp_move] - m[my_move];

		if (diff == -1 || diff == 2){
			total += 6;
		} else if (diff == 0){
			total += 3;
		}
	}

	std::cout << "Answer is: "; dlog(total);

	file.close();
}



void parse_input_2(){
	std::fstream file;
	file.open("day_2.input", std::ios::in);

	std::string line;
	char opp_move, result;
	long total = 0;
	while (true){
	    file >> opp_move >> result;
		if (file.eof()) break;

		int my_move;
		if (result == 'X'){
			my_move = mod(m[opp_move]-1, 3);

		} else if (result == 'Y'){
			my_move = m[opp_move];
			total += 3;
			
		} else { // result == 'Z'
			my_move = mod(m[opp_move]+1, 3);
			total += 6;
		}

		total += score[fuckyou[my_move]];
	}

	std::cout << "Answer is: "; dlog(total);

	file.close();
}




int main(int argc, char *argv[]){
	parse_input_2();
	solve();
}
