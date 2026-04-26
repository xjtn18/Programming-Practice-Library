//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/4/22
//  File type: C++ source file
//  Description: Given an array of intervals ([x,y]), return the minumum number of intervals
//		to remove such that the resulting array contains no overlapping intervals.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
We need to sort the array of intervals in N log N time.
The reason why sorting is necessary here is because when evaluating a specific interval,
	finding the intervals it overlaps with would end up taking quadratic time in an unsorted list.

You would think to sort the intervals by their start times, but using the linear time greedy method
	of counting overlapping intervals on a sorted list would result in a non-optimal answer.
The trick here is that we want to sort the intervals by their END time.
Then, doing a greedy count down the list will result in the optimal answer.
*/




bool comp(const vector<int>& a, const vector<int>& b){
	return a[1] < b[1]; // sort by their END time
}


int eraseOverlapIntervals(vector<vector<int>>& intervals){
	std::sort(intervals.begin(), intervals.end(), comp);

	int ans = 0, prev = 0;
	for (int curr = 1; curr < intervals.size(); ++curr){
		if (intervals[prev][1] > intervals[curr][0]){
			ans++;
		} else {
			prev = curr;
		}
	}

	return ans;
}




int main(){
	vector<vector<int>> intervals;

	intervals = gen2d("[[1,2],[2,3],[3,4],[1,3]]");
	dlog(eraseOverlapIntervals(intervals));

	intervals = gen2d("[[1,2],[2,3],[3,4]]");
	dlog(eraseOverlapIntervals(intervals));

	intervals = gen2d("[[1,2],[2,3],[3,4]]");
	dlog(eraseOverlapIntervals(intervals));

	return 0;
}



