//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 3/7/22
//  File type: C++ source file
//  Description: Gives an array numbers, order the numbers such that when strung
//  	together, they form the largest possible number.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// Idea:
// Sorting the numbers in decreasing order seems like the naive initial approach,
// but cleary that fails for this testcase:
// 	[2, 10]
// Here, this naive algorithm would swap 2 and 10, yieling 102 as our final number,
// when really leaving them as is would have given us bigger final number, 210.
//
// Another idea that came to mind was simply sorting the digits lexographically, like
// we would with strings, and places 'bigger' numbers first in this sense, but after
// manually running some test cases, we have a problem.
// Consider the following 2 cases:
// A) [121, 12]
// B) [122, 12]
// Using a descending lexographical sort, we would consider both of these already sorted
// and we would return our answer using this ordering, but only 1 of these would yield the
// correct result.
// Test case B would yield 12212, which is greater than 12122, however:
// Test case A would yield 12112, which is smaller than 12121, so this wont work.
//
// After sitting and thinking on it for a bit, I've determined that the lexographic ordering
// will always work if we are comparing 2 numbers with the same number of digits. The
// trouble comes when we are comparing 2 numbers that are the SAME, except that one is longer
// and has extra digits (ex. [121,12] or [456, 45681]).
// We can visualize this scenario as an algebra problem, where the 2 numbers we are comparing
// can be respresented as [x, xy], where the first number is contained in the prefix of the 
// second number. Because we know x is equivalent in both numbers, we can recursively call
// our comparison function with [x, y], and return that result as our answer. Here, if x
// ends up being greater than y according to our method, than x is also greater than xy, and
// so comes first in our list. Else, we swap. The recursive calls simply run linearly to the
// length of the numbers.
//
// @NOTE: I wrote my recursive function to take indices, so I can avoid creating extra substring
// objects every recursive call and improve space complexity.
//
// @NOTE: A beautiful way that we can use the standard C++ string lexographic comparison is to,
// instead of explicity writing out the specialized lexo comparison method like I have below,
// you simply tell std::sort to base the swaps off of whether or not a+b > b+a. We concatenate
// the strings in both orderings and see which is larger. If a+b is larger, then a should come
// before b in the list. This essentially doesn the same linear time comparison that my comp
// function does, but it is a lot cleaner while still making a lot of sense.
//
// time complexity: O(NlogN), since we are sorting a list.
// space complexity: O(M), where M is is the total number of digits across all N numbers.
//

bool comp(string &a, string &b, int i, int j){
	while (i < a.length() && j < b.length()){
		if (a[i] > b[j]) return true;
		else if (a[i] < b[j]) return false;
		++i, ++j;
	}
	if (i < a.length()){
		return comp(a, b, i, 0);
	} else if (j < b.length()){
		return comp(a, b, 0, j);
	}

	return false; // Should be arbitrary, but this MUST be false,
						//	because of something to do with the way the
						//	std::sort function determines to make a swap.
						//	'True' here will lead to an infinite loop on 
						//	specific cases...
}


string largestNumber(vector<int>& nums) {
	int call = 0;
	auto _comp = [&](int &_a, int &_b) -> bool {
		string a = std::to_string(_a);
		string b = std::to_string(_b);
		return comp(a, b, 0, 0);
	};

	std::sort(nums.begin(), nums.end(), _comp);

	// build our result string
	string result;
	for (int &num : nums) result += std::to_string(num);
	if (result[0] == '0') result = '0'; // to avoid returning answers like '000..'
	return result;
}



int main(){
	vector<int> nums;

	nums = {12,3};
	dlog(largestNumber(nums)); // 312

	nums = {121,12};
	dlog(largestNumber(nums)); // 12121

	nums = {122,12};
	dlog(largestNumber(nums)); // 12212

	nums = {0,3};
	dlog(largestNumber(nums)); // 30

	nums = {0,3,73,41,730};
	dlog(largestNumber(nums)); // 737304130

	nums = {0,0,0};
	dlog(largestNumber(nums)); // 0

	nums = {8308,8308,830};
	dlog(largestNumber(nums)); // 83088308830
	
	nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	dlog(largestNumber(nums)); // 0


	return 0;
}





