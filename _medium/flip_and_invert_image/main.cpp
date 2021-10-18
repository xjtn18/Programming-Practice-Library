//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
	int n = image.size();

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n/2.; ++j){
			image[i][n-j-1] = int(!exchange(image[i][j], int(!image[i][n-j-1])) );
		}
	}

	return image;
}




int main(){
	vector<vector<int>> input;


	input = {{1,1,0},{1,0,1},{0,0,0}};
	hlog(input);
	hlog(flipAndInvertImage(input));

	input = {{1}};
	hlog(input);
	hlog(flipAndInvertImage(input));


	return 0;
}



