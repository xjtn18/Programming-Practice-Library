#include <speed.hpp>

using namespace std;


// ------------ Solution ------------ //


umap<char, Plot> dirmap = {
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



void part_2(vector<string> lines){
	umap<int, uset<int>> visited;
	int hx = 0, hy = 0;
	record<Plot> knots(9);

	for (string l : lines){
		auto tokens = split(l, " ");
		char direc = tokens[0][0];
		int steps = stoi(tokens[1]);

		for (int i = 0; i < steps; ++i){
			int dx = dirmap[direc].x;
			int dy = dirmap[direc].y;
			hx += dx;
			hy += dy;

			int lastx = hx, lasty = hy;

			for (int j = 0; j < knots.size(); ++j){
				int &tx = knots[j].x;
				int &ty = knots[j].y;
				int diffx = lastx - tx;
				int diffy = lasty - ty;

				if (abs(diffx) == 2 && abs(diffy) == 2){
					tx += diffx / 2;
					ty += diffy / 2;
				}
				else if (abs(diffx) == 2){
					tx += diffx / 2;
					ty += diffy;
				} else if (abs(diffy) == 2){
					ty += diffy / 2;
					tx += diffx;
				}
				lastx = tx;
				lasty = ty;
			}

			visited[knots[-1].x].insert(knots[-1].y);
		}

	}
	
	long sigma = 0;
	for (auto [_, group] : visited) sigma += group.size();

	cout << "Part 2 - Answer is: " << sigma << endl;
}

// ----------------------------------- //





int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);

	Plot head(4,5);
	say(head.x, head.y);
	say(head.y);

}


