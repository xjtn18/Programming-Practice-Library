//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/8/22
//  File type: C++ source file
//  Description: Given an array of integers, return a list of the top K most frequent elements.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// Approach:
// For this problem we'll need to do some sorting and use a priority queue (max heap)
// First we are going to sort the array of numbers.
// We do this so that for each unique number, we know exactly how many of that number
// there are before we insert its entry into the priority queue. Doing this on an unsorted
// array would mean we need to keep going back and reupdating old entries which isnt possible
// with the standard libary. We could just update new updated entries and discard old entries
// when picking the ones for our final answer, but we would need to keep track of previously
// chosen entries by using a set.
// There are honestly many different ways to approach this problem, but they mostly all have
// the same complexity, so I am just going to implement the one I think makes the most sense.





typedef std::pair<int, int> IntPair;



struct IntPairComp {
	bool operator ()(const IntPair &a, const IntPair &b) const {
		return a.second < b.second;
	}
};



vector<int> topKFrequent(vector<int>& nums, int k){
	std::priority_queue<IntPair, std::vector<IntPair>, IntPairComp> freq_queue;

	// sort the array of numbers
	std::sort(nums.begin(), nums.end());


	// count each unique element
	for (int i = 0; i < nums.size(); ++i){
		int freq = 1;
		while (i < nums.size()-1 && nums[i] == nums[i+1]){
			++freq;
			++i;
		}
		freq_queue.push(IntPair(nums[i], freq));
	}

	vector<int> res;
	for (int i = 0; i < k; ++i){
		res.push_back(freq_queue.top().first);
		freq_queue.pop();
	}

	return res;
}



int main(){
	vector<int> nums;


	nums = {1,1,1,2,2,3};
	c_log(topKFrequent(nums, 2));

	nums = {1,1,1,2,2,3,3,3};
	c_log(topKFrequent(nums, 2));

	nums = {1,1,1,2,2,2,2,3,3,3};
	c_log(topKFrequent(nums, 1));

	nums = {1,3,5,2,6,7,3,5,6,5,8,0};
	c_log(topKFrequent(nums, 3));


	return 0;
}



