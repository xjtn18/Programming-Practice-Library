//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



vector<int> prisonAfterNDays(vector<int>& cells, int n){
	vector<int> next(cells.size(), 0);
	for (int i = 1; i < cells.size()-1; ++i){
		next[i] = cells[i-1] == cells[i+1];
	}
	vector<int> first = next; // cycle can only start after first day since edge cells
										// can only ever be occupied at the very start.

	int cycle = 0;
	while (n-- > 0){
		for (int i = 1; i < cells.size()-1; ++i){
			next[i] = cells[i-1] == cells[i+1];
		}
		if (next == first && cycle != 0) n %= cycle;
		cells = next;
		cycle++;
	}

	return cells;
}



int main(){
	vector<int> cells;

	cells = {1,0,0,1,0,0,1,0};
	c_log(prisonAfterNDays(cells, 1000000000));
	return 0;
}



