//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created: 9/12/21
//	File type: C++ source file
//	Description: Given a string of words, spaces and symbols, return the most frequently
//					appearing word that isn't a banned word.
//////////////////////////////////////////////////////



// Solution:
// Use 2 pointers to tokenize the 'paragraph' string.
// Extract the tokens using substr and store a count of the non-banned words in a map.
// When a value in the map is the higest we've seen, update our new max and our most frequent word.
// Once we get to end of the string, return the most frequent word.
//
// TC:
// O(n log m)
// Mostly linear in the number of characters in the paragraph string.
// The complexity ends up being slightly larger because of case insensitivity as well as the map/set searches.
// Could use a hash map instead of a tree map for constant map lookup.
//	So worst case for this solution is O(n*m) where 'n' is # of chars in paragraph, and 'm' is avg # of chars per
//	word (for setting to lowercase); NOTE: 'm' is going to be very small if the paragraph contains valid language words.
//



#include <mystd.h>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
	map<string, int> freq_map;
	unordered_set<string> ban_set(banned.begin(), banned.end());
	int highest_freq = 0;
	string highest_token;
	size_t token_start = 0, token_end;
  
	while (token_start < paragraph.length()){
		//skip leading white space
		while ( token_start < paragraph.length() && ! isalpha(paragraph[token_start]) ) {
			 ++token_start;
		}
		token_end = token_start;
		//traverse the token
		while ( token_end < paragraph.length() && isalpha(paragraph[token_end]) ) {
			 ++token_end;
		}
		//extract token
		string token = paragraph.substr(token_start, token_end-token_start);
		// ignore case!!
		transform(token.begin(), token.end(), token.begin(), [](unsigned char c){return tolower(c);});

		//update count and most frequent token
		if (!ban_set.count(token)){ // if this word isnt banned
			 freq_map.emplace(token, 0); // set mapping to 0 if not in map already
			 freq_map[token]++;
			 if (freq_map[token] > highest_freq){
				  highest_token = token;
				  highest_freq = freq_map[token];
			 }
		}
		token_start = token_end + 1;
	}

	return highest_token;
}



int main(){
	string para;
	vector<string> banned;

	para = "She ate a cookie, she liked the Cookie .cookie";
	banned = {};
	dlog( mostCommonWord(para, banned) );

	para = "She ate a cookie, she liked the Cookie .cookie";
	banned = {"cookie"};
	dlog( mostCommonWord(para, banned) );



	return 0;
}



