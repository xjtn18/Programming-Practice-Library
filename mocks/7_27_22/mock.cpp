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
#include <map>
#include <Windows.h>



/// Problem 1

void duplicateZeros(vector<int>& arr){
	// count number of zeros
	int cnt = 0;
	for (int &n : arr) cnt += (n == 0);
	if (cnt == arr.size()) return;

	int j = arr.size() - 1;
	while (j >= 0 && arr[j] == 0){
		j--;
		cnt--;
	}

	int e = arr.size() - 1;
	while (cnt > 0){
		if (arr[j] == 0){
			cnt--;
			arr[e] = 0;
			arr[e-1] = 0;
			e -= 2;

		} else {
			arr[e] == arr[j];
			j--;
			e--;
		}
	}
}



/*
 *
 * Go through the array and count the number of zeros.
 * Then, iterate backwards up the array.
 * We will have 2 pointers X and Y. Y will point to the back of the array initially, and X will point to 
 * 	the second to last index of the array.
 * We will iterate both pointers down the array. Everytime we encounter a zero, we will decrease the amount
 *
 *
 *
 * 1 2 3 0 4 5
 *
 */




int main(){
	vector<int> arr;

	arr = {1,0,2,3,0,4,5,0};
	duplicateZeros(arr);
	for (auto i : arr) cout << i << " "; cout << endl;

	arr = {0,0,0,1};
	duplicateZeros(arr);
	for (auto i : arr) cout << i << " "; cout << endl;

	arr = {0,0,0,1,0,0,0};
	duplicateZeros(arr);
	for (auto i : arr) cout << i << " "; cout << endl;

	return 0;
}



