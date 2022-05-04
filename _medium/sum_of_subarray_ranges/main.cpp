//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 4/16/22
//  File type: C++ source file
//  Description: Let 'range' mean the difference between the largest and smallest element.
//						Given an array, find the sum of ranges of all subarrays.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*

We can use a stack.
The stack will hold the values in the sub array, and we will track the min and max.

input = [1,2,3,4]

stk = [1,2]


*/

long long subArrayRanges(vector<int>& nums){
	long long sigma = 0;
	int min = INT_MAX, max = INT_MIN;

	for (int i = 0; i < nums.size(); ++i){
		
	}

	return sigma;

}



int main(){

	return 0;
}



