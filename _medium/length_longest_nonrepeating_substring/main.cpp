//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
#include <cassert>
#include <map>



// Idea:
// Loop through the string once.
// Keep a running integer count of the current length since last duplicate was found.
// For every char, update its value in the map for that char with the index of the position it was just seen at.
// If we find a char that already has a listing in the map, then its a duplicate.
// 	We set the current length to the MIN of the distance between that char and its last known position and 
// 	the value of length + 1. If length + 1 is less, it means that there was another duplicate set of characters
// 	that we found after we saw the current character last.
// If we havent seen it yet, just increment the length count by 1.
// Update the max every loop in case the current length is greater than the max.
// Return max.
//
// TC
// The time complexity is linear O(n), n being the length of the string.
// Ordered map lookups are O(log(26+10+1))) for chars, digits, and spaces, so lookups are linear.
// Unordered maps run the risk of the collisions and could be O(n) worst case.
//
// SC
// Only using a map with size 26+10+1, so O(1) space complexity.
//



int lengthOfLongestSubstring(std::string s){
	int maxx = 0;
	int length = 0;
	std::map<char,int> map;

	for (int i = 0; i < s.length(); ++i){
		if (map.find(s[i]) != map.end()){ // duplicate char
			length = std::min(i - map[s[i]], length + 1);
		} else {
			length++;
		}
		map[s[i]] = i; // saying that this index is the latest position where this char was seen.
		maxx = std::max(length, maxx); // update new max
	}
	return maxx;
}



int main(){
	assert(lengthOfLongestSubstring("abcabca") == 3);
	assert(lengthOfLongestSubstring("abcabc") == 3);
	assert(lengthOfLongestSubstring("abcd") == 4);
	assert(lengthOfLongestSubstring("") == 0);
	assert(lengthOfLongestSubstring("aaaa") == 1);
	assert(lengthOfLongestSubstring("aaaab") == 2);
	assert(lengthOfLongestSubstring("dvdf") == 3);
	assert(lengthOfLongestSubstring("abba") == 2);
	dlog(">> PASSED <<");
	return 0;
}



