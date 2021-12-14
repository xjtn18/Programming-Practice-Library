//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given 2 wires defined by right-left-up-down
//////////////////////////////////////////////////////


#include <mystd.h>
#include <fstream>
#include <sstream>
using namespace std;



#define umap unordered_map

int optimal(string wire1, string wire2){
	umap<int, umap<int, int>> m;

	int soonest = INT_MAX;
	int x = 0;
	int y = 0;
	int wire_length = 0;
	string token;
	istringstream ss1(wire1);
	while (getline(ss1, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 0; i < distance; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;
			wire_length++;
			if (!m.count(x) || !m[x].count(y)){
				m[x][y] = wire_length;
			}
		}
	}


	x = 0;
	y = 0;
	wire_length = 0;
	istringstream ss2(wire2);
	while (getline(ss2, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 0; i < distance; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;
			wire_length++;

			if (m.count(x) && m[x].count(y)){
				soonest = min(soonest, wire_length + m[x][y]);
			}
		}
	}

	return soonest;
}




struct Bounds {
	int xmin = INT_MAX;
	int xmax = INT_MIN;
	int ymin = INT_MAX;
	int ymax = INT_MIN;

};

ostream& operator <<(ostream &os, const Bounds &b){
	os << "xmin: " << b.xmin << endl;
	os << "xmax: " << b.xmax << endl;
	os << "ymin: " << b.ymin << endl;
	os << "ymax: " << b.ymax << endl;
	return os;
}

Bounds get_bounds(string wire1){
	Bounds b;
	int x = 0;
	int y = 0;
	string token;
	istringstream ss1(wire1);
	while (getline(ss1, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		if (dir == 'R') x += distance;
		if (dir == 'L') x -= distance;
		if (dir == 'D') y += distance;
		if (dir == 'U') y -= distance;
		b.xmin = min(b.xmin, x);
		b.xmax = max(b.xmax, x);
		b.ymin = min(b.ymin, y);
		b.ymax = max(b.ymax, y);
	}

	return b;
}



int soonest_intersection(string wire1, string wire2){

	Bounds b = get_bounds(wire1);

	const int xcenter = b.xmax - b.xmin;
	const int ycenter = b.ymax - b.ymin;
	const int ROWS = ycenter * 2;
	const int COLS = xcenter * 2;
	vector<vector<int>> grid(ROWS, vector<int>(COLS, 0));

	int soonest = INT_MAX;
	int x = xcenter;
	int y = ycenter;
	int wire_length = 0;
	string token;
	istringstream ss1(wire1);
	while (getline(ss1, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 0; i < distance; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;
			wire_length++;
			if (grid[x][y] == 0) grid[x][y] = wire_length;
		}
	}


	x = xcenter;
	y = ycenter;
	wire_length = 0;
	istringstream ss2(wire2);
	while (getline(ss2, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 0; i < distance; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;
			wire_length++;

			if (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != 0){
				soonest = min(soonest, wire_length + grid[x][y]);
			}
		}
	}

	return soonest;
}



int closest_intersection(string wire1, string wire2){
	
	int closest = INT_MAX;
	const int SIZE = 50001;
	const int center = SIZE/2;
	vector<vector<int>> grid(SIZE, vector<int>(SIZE, 0));
	int x = center;
	int y = center;

	string token;
	istringstream ss1(wire1);
	while (getline(ss1, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 1; i < distance+1; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;
			grid[x][y] = 1; // place wire
		}
	}

	istringstream ss2(wire2);
	x = center;
	y = center;
	while (getline(ss2, token, ',')){
		char dir = token[0];
		int distance = stoi(token.substr(1));
		for (int i = 1; i < distance+1; ++i){
			if (dir == 'R') x++;
			if (dir == 'L') x--;
			if (dir == 'D') y++;
			if (dir == 'U') y--;

			if (grid[x][y] == 1){
				closest = min(closest, abs(x-center) + abs(y-center));
			}
		}
	}

	return closest;
}




int main(){
	fstream file("input.txt");
	string wire1, wire2;
	getline(file, wire1);
	getline(file, wire2);

	//cout << closest_intersection(wire1, wire2) << endl;
	//cout << soonest_intersection(wire1, wire2) << endl;
	cout << optimal(wire1, wire2) << endl;

	return 0;
}



