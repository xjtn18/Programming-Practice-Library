//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 4/16/22
//  File type: C++ source file
//  Description: Random 1 hour mock interview assessment from LeetCode.
//////////////////////////////////////////////////////


using namespace std;
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unistd.h>
#include <vector>




/*

ld = x % 10
x shifted = x / 10

1,2,3,4,5 = 2
6,7,8,9,10 = 2 -> 4


i = 0
j = 2
2 * 2 / 2 = 2


start = 0;
i = 1
gap = 1;

*/




int maxDistToClosest(vector<int>& seats){
	int max_dist = 1, largest_gap = 0;

	for (int i = 0; i < seats.size(); ++i){
		int start = i;
		int gap = 1;
		while (i < seats.size() && seats[i] == 0){
			i++;
			gap++;
		}
		if (start == 0 || i == seats.size()) gap = gap * 2 - 1;
		max_dist = max(max_dist, gap / 2);
	}

	return max_dist;
}




int rotatedDigits(int n){
	int count = 0;

	unordered_set<int> goodDigits = {2,5,6,9};
	unordered_set<int> badDigits = {3,4,7};


	for (int i = 1; i < n+1; ++i){
		bool rotationIsDifferent = false;
		int j = i;
		while (j > 0){
			int last_digit = j % 10;
			if (badDigits.count(last_digit)){
				rotationIsDifferent = false;
				break;
			} else if (goodDigits.count(last_digit)){
				rotationIsDifferent = true;
			}
			j /= 10;
		}

		if (rotationIsDifferent) count++;
	}

	return count;
}



int main(){
	//cout << rotatedDigits(10) << endl;

	vector<int> v;

	v = {1,1,0,0,1,0,1};
	cout << maxDistanceToClosest(v) << endl; // 1

	v = {1,0,1,0,0,0,0};
	cout << maxDistanceToClosest(v) << endl; // 4

	v = {1,0,0,0,0,0,1,1,0,0};
	cout << maxDistanceToClosest(v) << endl; // 3

	return 0;
}



