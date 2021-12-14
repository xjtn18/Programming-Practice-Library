//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/14/21
//  File type: C++ source file
//  Description: Given 'd' dice, each with 'f' faces, return the number of unique rolls
//  					where the face-up side of each die sums to the target value.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

#define umap unordered_map


// Solution explanation
//
// We will recursively search through the permutations. We will stop if the current
// sum is greater than the target (AKA target becomes negative).
// We are using a 2d array in place of a hash map because it runs MUCH faster than having
// a 2D map.
// For each possible value of one dice roll, subtract that value from target and
// compute the number of dice rolls that sum to that new difference.
// The reason why dp saves so much time here is because we end recomputing the same
// sub-targets for the same number of dice many times. We can store these in the memo
// array for easy access later on in the recursive call chain.
// We will index the 'map' by number of dice and the target we need from them.
// It will store the number of rolls that sum to that target.
// *NOTE: We need to make sure we are modding not just at the end. The problem wants
// us to modulo everytime we increase roll count.
//



const int MOD = 1000000007;
int memo[31][1001];


int solve(int d, int f, int target){
	if (d==0) return target == 0;

	int &subcount = memo[d][target]; // reference
	if (subcount != -1) return subcount;

	subcount = 0;
	for (int i=1; i<=f && i<=target; i++){
		subcount = (subcount + solve(d-1, f, target-i)) % MOD;
	}
	return subcount % MOD;
}


int numRollsToTarget(int d, int f, int target) {
	memset(memo, -1, sizeof(memo));
	return solve(d, f, target);
}


int main(){
	cout << numRollsToTarget(30, 30, 500) << endl;
	cout << numRollsToTarget(5, 6, 18) << endl;

	return 0;
}



