//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/12/2021
//  File type: C++ source file
//  Description: Given 2 lists of ints, compute their intersection (elements they both share).
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;




/*
Idea:
	Iterate through the smaller list and keep track of the frequency of each number in a hashmap.
	Then iterate through the larger list and append to the intersection vector each time a value in the larger list has a positive non-zero value in the hashmap.
	Return intersection vector.


*/


vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
	vector<int> isec;
	unordered_map<int, int> hmap;

	for (const int& e : nums1) hmap[e]++;

	for (const int& e : nums2){
		if (hmap.count(e) && hmap[e] != 0){
			isec.push_back(e);
			hmap[e]--;
		}
	}

	return isec;
}



int main(){
	vector<int> n1 {1,2,2,3};
	vector<int> n2 {2,2};
	c_log(intersect(n1, n2));

	return 0;
}



