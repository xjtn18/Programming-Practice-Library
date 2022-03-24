//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 10/26/21
//  File type: C++ source file
//  Description: Given a string, return a list of the sizes of each partition.
//  					Compute the list with the maximum number of partitions such
//  					that no 2 partitions contain the same character. For example,
//  					if the string contains one instance of the letter 'c', than
//  					that will be its own partition with a size of 1.
//////////////////////////////////////////////////////


// Solution
//
// My approach was to first do a simple pass through the string and track
// the LAST position we saw any specific character in the string; I do this
// using a map.
// Once we have the indexes of the last occurences, we do one more pass through
// the string. We look for the last occurence of the first character using our 
// map and iterate inside a nested loop up until that point. As we traverse,
// we increment the size of this partition, but also we take the max of the
// current target point and current chars last occurence. If a character in
// this partition has another occurence outside the bounds of this partition,
// then the parition must be larger, and we update our new loop target value
// (end). When we reach end, it means that we fully processed that partition,
// and so we push our count to the back of our answer vector. We continue
// processing the rest of the partitions until we reach the end of the string.
// Although there are 2 nested loops, the outer loop progresses forward as the
// inner loop does, and so this results in one linear pass through the string,
// making the total function run with a TC of O(2N) linear, and since map will
// only ever hold as many unique characters there are in the string, its size
// is not a function of N, and so the SC is O(1) constant.




#include <mystd.h>
using namespace std;


vector<int> partitionLabels(string s) {
	vector<int> sizes;
	unordered_map<char, int> last; // will contain at most 24 keys (for each alphabetic char)
  
	// record first occurences
	int i = 0;
	while (i < s.length()){
		last[s[i]] = i; // update with the last index we found this char at
		i++;
	}

	i = 0;
	while (i < s.length()){
		int psize = 0;
		int end = last[s[i]];
		while (i <= end){
			psize++;
			end = max(end, last[s[i]]);
			i++;
		}
		sizes.push_back(psize);
	}

	return sizes;
}




int main(){
	auto run_case = [] (string s) {
		dlog("____________");
		dlog(s);
		c_log(partitionLabels(s));
		dlog("____________\n");
	};

	run_case("abca");
	run_case("abc");
	run_case("ababcbacadefegdehijhklij");
	run_case("a");



	return 0;
}



