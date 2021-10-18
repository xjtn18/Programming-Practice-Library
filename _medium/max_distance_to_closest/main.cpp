//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 10/16/21
//  File type: C++ source file
//  Description: Given an array of bits, return the distance from
//  					the farthest unset bit to its nearest set bit.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
Solution explanation:
	There are three types of places where we can sit:
	A) We sit to left of everyone else, in which case we sit in chair 1.
	B) We sit to the right of everyone else, in which case we sit in chair n.
	C) We sit in between 2 people in chairs X and Y, in which case we sit in
	chair (X + Y) / 2, which has a distance-to-nearest of Z/2 where Z is the
	number of seats between chair X and Y.

	TC: Linear time in the number of seats
	SC: Constant; we just need iterator, maxx to store the max, and count to keep track;


*/


int maxDistToClosest(vector<int>& seats) {
	int maxx, count = 0;
	int i = 0;

	while (!seats[i]) {++i;} // gauranteed that atleast one set bit exists
	maxx = i;
	while (++i < seats.size()){
		if (seats[i]){
			maxx = max(maxx, ++count/2);
			count = 0;
		} else {
			++count;
		}
	}
	return max(maxx, count);
}


int main(){
	vector<int> seats;

	seats = {0,1};
	assert( maxDistToClosest(seats) == 1);

	seats = {1,0};
	assert( maxDistToClosest(seats) == 1);

	seats = {1,0,0,1};
	assert( maxDistToClosest(seats) == 1);

	seats = {1,0,0,0,1}; // 2
	assert( maxDistToClosest(seats) == 2);

	seats = {0,1,0,0,1};
	assert( maxDistToClosest(seats) == 1);

	seats = {0,1,0,0,1,0,0,0};
	assert( maxDistToClosest(seats) == 3);

	seats = {0,0,0,1,0,0,0,0,0,0,1}; // 3
	assert( maxDistToClosest(seats) == 3);

	seats = {0,0,1,0,0,0,0,0,0,0,1}; // 4
	assert( maxDistToClosest(seats) == 4);

	seats = {1,0,0,0,1,0,1};
	assert( maxDistToClosest(seats) == 2);

	return 0;
}



