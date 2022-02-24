//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/11/22
//  File type: C++ source file
//  Description: Write a function that returns the approximate nth root of some number x.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

/*
 * Solution:
 * 	Run a binary search on all numbers less than X until the current approximation to the nth
 * 	power meets the margin of error requirement (is very close to X).
 *
 * TC: O(log N) : doing a binary search on the numbers in range 0 to X;
 * SC: O(1)
 *
*/




double nth_root(double x, unsigned int n){
	assert(x >= 0 && n > 0); // domain constraints

	if (x == 0) return 0;
	if (n == 1) return x;

	double lower = 0;
	double upper = max(1.0, x);
	double approx, power;

	do {
		approx = (upper + lower) / 2;
		power = pow(approx, n);
		if (power > x) upper = approx;
		else lower = approx;
	} while (abs(power - x) >= 0.001); // accuracy threshold

	int rounded = round(approx);
	return (abs(approx - rounded) < 0.001) ? rounded : approx;
}



int main(){
	dlog(nth_root(0, 3)); // 0
	dlog(nth_root(1, 3)); // 1
	dlog(nth_root(5, 1)); // 5
	dlog(nth_root(8, 3)); // 2
	dlog(nth_root(16, 2)); // 4
	dlog(nth_root(7, 3)); // 1.912
	dlog(nth_root(0.5, 3)); // 0.793
	dlog(nth_root(0.38, 1)); // 0.38

	return 0;
}



