//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/30/2020
//  File type: C++ source file
//  Description: Rotating a square matrix clockwise 90 degrees.
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"

using namespace std;



#include <cmath>

// solution explanation:
// 		rotate every sub-square within the matrix
// 		(rotating outer square, then inner square, then inner inner square, etc.
// 		Standard formula for 90 degree rotation:
// 			[x,y] -> [-y,x]

void swap(int& a, int& b){
	int tmp = b;
	b = a;
	a = tmp;
}

void rotate(vector<vector<int>>& matrix){
	// assume matrices are square
	int n = matrix.size(); // dimension
	int mid = floor(n/2);

	for (int i = 0; i < mid; ++i){ // row
		for (int j = i; j < n - i - 1; ++j){ // column
			int curr_i = i, curr_j = j, next_i, next_j, zbase_x, zbase_y;
			for (int c = 0; c < 3; ++c){ // for each 4 corresponding square points
				zbase_x = curr_j - mid;
				zbase_y = curr_i + mid;
				cout << zbase_x << " " << zbase_y << endl;
				// swap indices in opposite direction of rotation
				swap(zbase_x, zbase_y);
				zbase_x = -zbase_x;
				cout << zbase_x << " " << zbase_y << endl;
				
				next_i = abs(zbase_y - mid) % n;
				next_j = abs(zbase_x + mid) % n;
				cout << next_i << " " << next_j << endl;
				log("");
				swap(matrix[curr_i][curr_j], matrix[next_i][next_j]);
				curr_i = next_i;
				curr_j = next_j;
			}
			
		}
	}
}



int main(){
	vector<vector<int>> m {{1,2,3}, {4,5,6}, {7,8,9}};
	//vector<vector<int>> m {{5,1,9,11,3},{2,4,8,10,2},{13,3,6,7,8},{15,14,12,16,11}, {1,2,3,4,5}};
	log(m);
	rotate(m);
	log(m);
	return 0;
}


/*

0,0
0,3
3,3
3,0

0,1
1,3
3,2
2,0

1,1
1,2
2,2
2,1


PATTERN FOR CLOCKWISE 90 degree rotation:
x,y   ->   y,(n-1)-x

*/
