#include <mystd.h>
using namespace std;


// NOTE: This can be done with an array based hashmap for better time complexity,
// 		at the sacrifice of space.


vector<int> bucketsort(const vector<int> &nums, const int scope){
	unordered_map<int, int> buckets;

	for (int i = 0; i < nums.size(); ++i){
		buckets[nums[i]]++;
	}

	vector<int> sorted;
	sorted.reserve(nums.size());
	for (int i = -scope; i <= scope; ++i){
		while (buckets[i] > 0){
			buckets[i]--;
			sorted.push_back(i);
		}
	}

	return sorted;
}




int main(void){
	const int scope = 100; // positive and negative
	vector<int> nums;
	
	nums = {6,1,3,6,2,3,4,10,15,2,0,-7};
	c_log(bucketsort(nums, scope));


}


