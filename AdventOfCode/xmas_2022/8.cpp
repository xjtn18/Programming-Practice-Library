#include <speed.hpp>
using namespace std;


// ------------ Solution ------------ //


bool in_bounds(int i, int j, int height, int width){
	return (i >= 0 && j >= 0 && i < height && j < width);
}


void part_1(vector<string> lines){
	int height = lines.size();
	int width = lines[0].length();
	vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

	int sigma = height*2 + (width-2)*2;
	for (int i = 1; i < height-1; ++i){
		for (int j = 1; j < width-1; ++j){
			int h = lines[i][j] - '0';
			int blocked = 0;
			for (auto d : dirs){
				int u = i+d[0], v = j+d[1];
				while (in_bounds(u, v, height, width)){
					if (lines[u][v] - '0' >= h){
						blocked++;
						break;
					}
					u += d[0]; v += d[1];
				}
			}
			sigma += (blocked < 4);
		}
	}
	
	cout << "Answer is: ";
	cout << sigma << endl;
}


void part_2(vector<string> lines){
	int height = lines.size();
	int width = lines[0].length();
	vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

	int max_view = 0;
	for (int i = 1; i < height-1; ++i){
		for (int j = 1; j < width-1; ++j){
			int h = lines[i][j] - '0';
			vector<int> views = {0, 0, 0, 0};

			for (int k = 0; k < 4; ++k){
				auto d = dirs[k];
				int u = i+d[0], v = j+d[1];
				while (in_bounds(u, v, height, width)){
					if (lines[u][v] - '0' < h){
						views[k]++;
					} else {
						views[k]++;
						break;
					}
					u += d[0]; v += d[1];
				}
			}

			//max_view = max(max_view, pi(views));
		}
	}
	
	cout << "Answer is: ";
	cout << max_view << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1(lines);
	part_2(lines);
}


