//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given a list of heights, find the max area of water
//  					that can be contained within 2 heights that represent
//  					walls of a container.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


int maxArea(vector<int>& height){
	int lo = 0, hi = height.size()-1;
	int max_area = 0;
	while (lo < hi){
		if (height[lo] < height[hi]){
			max_area = max(max_area, height[lo] * (hi-lo));
			++lo;
		} else {
			max_area = max(max_area, height[hi] * (hi-lo));
			--hi;
		}
	}
	return max_area;
}





int main(){
	vector<int> input;

	input = {1,7,5,1,7};
	assert(maxArea(input) == 21);

	input = {0};
	assert(maxArea(input) == 0);

	input = {};
	assert(maxArea(input) == 0);

	input = {1,7,5,50,50,1,7};
	assert(maxArea(input) == 50);

	return 0;
}



