//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/3/22
//  File type: C++ source file
//  Description: Given a histogram, find the area of the largest rectangle.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
 * TC: O(2N)
 * SC: O(N)
 *
*/

int largestRectangleArea(vector<int>& heights) {
	stack<int> s;
	int area = 0;
	heights.push_back(0);

	for (int i=0; i < heights.size(); ++i){
		while (!s.empty() && heights[i] < heights[s.top()]){
			int last = s.top(); s.pop();
			int start = s.empty() ? 0 : s.top()+1;
			area = max(area, heights[last] * (i-start));
		}
		s.push(i);
	}

	return area;
}


int main(){
	vector<int> heights;
	heights = {2,1,2}; // 3
	dlog(largestRectangleArea(heights));

	heights = {2,3,1,2}; // 4
	dlog(largestRectangleArea(heights));

	heights = {4,2,0,3,2,5}; // 6
	dlog(largestRectangleArea(heights));

	heights = {2,1,5,6,2,3}; // 10
	dlog(largestRectangleArea(heights));

	heights = {2,4}; // 4
	dlog(largestRectangleArea(heights));

	heights = {0}; // 0
	dlog(largestRectangleArea(heights));

	heights = {1}; // 1
	dlog(largestRectangleArea(heights));

	heights = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // 28
	dlog(largestRectangleArea(heights));

	return 0;
}



