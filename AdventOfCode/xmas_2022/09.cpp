#include <speed.hpp>

using namespace std;


// ------------ Solution ------------ //


umap<char, s2> dirmap = {
	{ 'R', { 1, 0} },
	{ 'L', {-1, 0} },
	{ 'U', { 0, 1} },
	{ 'D', { 0,-1} }
};


void part_1(vector<string> lines){
	umap<int, uset<int>> visited;
	int hx = 0, hy = 0, tx = 0, ty = 0;

	for (string l : lines){
		auto tokens = split(l, " ");
		char direc = tokens[0][0];
		int steps = stoi(tokens[1]);

		for (int i = 0; i < steps; ++i){
			int dx = dirmap[direc].x;
			int dy = dirmap[direc].y;
			hx += dx;
			hy += dy;

			int diffx = hx - tx;
			int diffy = hy - ty;
			if (diffx == 2 || diffx == -2){
				tx += diffx / 2;
				ty += diffy;
			} else if (diffy == 2 || diffy == -2){
				ty += diffy / 2;
				tx += diffx;
			}
			visited[tx].insert(ty);
		}

	}
	
	long sigma = 0;
	for (auto pair : visited){
		sigma += pair.second.size();
	}
	cout << "Part 1 - Answer is: " << sigma << endl;
}


umap<char, s2> dirmap = {
	{ 'R', { 1, 0} },
	{ 'L', {-1, 0} },
	{ 'U', { 0, 1} },
	{ 'D', { 0,-1} }
};

void part_2(vector<string> lines){
	uset<s2> visited;
	s2 head;
	record<s2> knots(9);

	for (string l : lines){
		auto tokens = split(l, " ");
		char dir = tokens[0][0];
		int steps = stoi(tokens[1]);

		while (steps--){
			head += dirmap[dir];
			s2 prev = head;

			for (auto &knot : knots){
				s2 diff = prev - knot;

				if (abs(diff.x) == 2 && abs(diff.y) == 2){
					knot.x += diff.x / 2;
					knot.y += diff.y / 2;
				} else if (abs(diff.x) == 2){
					knot.x += diff.x / 2;
					knot.y += diff.y;
				} else if (abs(diff.y) == 2){
					knot.y += diff.y / 2;
					knot.x += diff.x;
				}
					
				prev = knot;
			}

			visited.insert(knots[-1]);
		}

	}
	
	cout << "Part 2 - Answer is: " << visited.size() << endl;
}

// ----------------------------------- //





int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);

}


