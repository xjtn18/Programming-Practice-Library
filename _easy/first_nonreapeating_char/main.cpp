//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created:
//	File type: C++ source file
//	Description: Function that returns the first nonrepeating character in a string.
//////////////////////////////////////////////////////


// Idea:
// To keep track of what characters we've seen, we need 2 sets.
// One set keeps track of what characters we have seen once so far.
// The other keeps track of the characters we know are duplicates.
// When we find a character that was seen once already, we remove it from the 'once' set and add it to the duplicates.
// We do one more loop through the array, the first character that is in once is our answer.
// 
// TC
// Linear; even though the set lookups are logarithmic, they are logarithmic to the number of unique characters, which has a small max limit. There are 2 loops through the string, 2n, which is still linear.
//
// SC
// O(k), k being the number of unique values in the string.
//



#include <mystd.h>
#include <cassert>

#define IN(x,y) 		y.find(x) != y.end()
#define NOT_IN(x,y) 	y.find(x) == y.end()



// This was my original solution, which involved storing a map of the chars seen once and then sorting them by their value, which was their index in the string, and returning the first element in the list if not empty. This solution is much more convoluted and has a worse time/space complexity than the second solution below.

/*
char firstNonRepeatingCharacter(std::string s) {
	std::map<char, int> seen;
	std::set<char> dups;

	for (int i = 0; i < s.length(); ++i){
		if ( IN(s[i], seen) ){
			seen.erase(s[i]);
			dups.insert(s[i]);

		} else if ( NOT_IN(s[i], dups) ){ // if it is not a duplicate
			seen[s[i]] = i;
		} 
		// else, its a duplicate, ignore it
	}

	// now we need to get a sorted representation of the 'seen' by VALUE.
	auto seen_vec = sorted_by_value(seen);
	return (seen_vec.empty()) ? '_' : seen_vec[0].first;
}
*/


char firstNonRepeatingCharacter(std::string s) {
	std::set<char> once, dups;
	int i;

	for (i = 0; i < s.length(); ++i){
		if ( IN(s[i], once) ){
			once.erase(s[i]);
			dups.insert(s[i]);

		} else if ( NOT_IN(s[i], dups) ){ // if it is not a duplicate
			once.insert(s[i]);
		} 
	}

	for (i = 0; i < s.length(); ++i){
		if ( IN(s[i], once) ){
			return s[i];
		}
	}
	return '_';
}



int main(){
	assert(firstNonRepeatingCharacter("abcac") == 'b');
	assert(firstNonRepeatingCharacter("") == '_');
	assert(firstNonRepeatingCharacter("abab") == '_');
	assert(firstNonRepeatingCharacter("ababc") == 'c');
	assert(firstNonRepeatingCharacter("c") == 'c');
	assert(firstNonRepeatingCharacter("cc") == '_');
	assert(firstNonRepeatingCharacter("abazab") == 'z');
	assert(firstNonRepeatingCharacter("abcdefg") == 'a');
	assert(firstNonRepeatingCharacter("ca") == 'c');

	return 0;
}



