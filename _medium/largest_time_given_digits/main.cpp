//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/10/21
//  File type: C++ source file
//  Description: Given 4 digits, return a string representing the largest possible time
//  					(on a 24 hour clock) that can be made using those digits.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


#define ts(x) to_string(x)

string largestTimeFromDigits(vector<int>& arr){
	int lrg_value = -1;
	vector<int> lrg;
	sort(arr.begin(), arr.end()); // must be sorted in order to get all permutations possible

	do {
		int value = 0;
		for (int i = 0; i < arr.size(); ++i) value += pow(10, 3-i) * arr[i];
		if (value < 2400 && value % 100 < 60 && value > lrg_value){
			lrg_value = value;
			lrg = arr;
		}
	} while (next_permutation(arr.begin(), arr.end()));

	return (!lrg.empty()) ? ts(lrg[0]) + ts(lrg[1]) + ":" + ts(lrg[2]) + ts(lrg[3]) : "";
}


int main(){
	vector<int> arr;

	arr = {1,2,3,4};
	cout << largestTimeFromDigits(arr) << endl; // "23:41"

	arr = {6,0,2,6};
	cout << largestTimeFromDigits(arr) << endl; // "02:26"

	arr = {5,5,5,5};
	cout << largestTimeFromDigits(arr) << endl; // ""

	arr = {0,0,0,0};
	cout << largestTimeFromDigits(arr) << endl; // ""

	return 0;
}



