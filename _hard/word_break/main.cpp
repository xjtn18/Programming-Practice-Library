//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/15/22
//  File type: C++ source file
//  Description: Given a string of chars, add spaces to the string to create a sentence where every
//  	word is a valid dictionary word. Return all such possible sentences.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


template <class T> using uset = unordered_set<T>;
template <class K, class V> using umap = unordered_map<K, V>;

/*
 * Solution:
 * 	My gut tells me that we need to use backtracking to create all of the sentences.
 * 	-First thing we will do is create a set of the vector of valid words, so we can get
 * 	constant lookup time when checking if a word is valid.
 * 	-Then, I will iterate through the string 's' and check every substring up until that point if
 * 	they are valid words.
 * 	-If it is a valid word, we will save that index do a recursive search on the rest of the string.
 *
 * 	(D is the length of the dictionary, N is the length of the character string)
 * 	TC: O(N^2)
 * 	SC: O(D + N)
 *
 * 	@Note: This can be optimized by using DP. Because we are backtracking, we could potentially be
 * 	searching the same substring multiple times. We can cut down on subsequent searches of the same
 * 	string by storing a map, where the key is some index 'k' into 's' and the value is a vector of
 * 	strings, where each string is all the sentences that can be made from the string s[k:].
 *
 * 	Further down, I've implemented the memoized version with keys for the map being the substring
 * 	itself.
 *
*/

void solve(vector<string> &all, string sentence, string s, unordered_set<string> d){
	if (s.empty()){
		sentence.pop_back();
		all.push_back(sentence);
		return;
	}

	for (int i = 1; i <= s.length(); ++i){
		string sub = s.substr(0, i);
		if (d.count(sub)){ // if its a valid dict word
			solve(all, sentence + sub + " ", s.substr(i), d);
		}
	}
}


vector<string> wordBreak(string s, vector<string> &wordDict){
	unordered_set<string> d;
	for (string &word : wordDict){
		d.insert(word);
	}

	vector<string> all;
	string sentence = "";
	solve(all, sentence, s, d);

	return all;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Faster solution


// returns all sentences made from a given string (with memoization)
vector<string> _solve(string s, uset<string> &d, umap<string, vector<string>> &m) {
	// if we already have all sentences computed for this string
	if (m.count(s)){
		return m[s];
	}

	// else, compute those sentences
	for (int i = 1; i <= s.length(); ++i){
		string sub = s.substr(0, i);
		if (d.count(sub)){
			if (i == s.length()){ // for when the entire string is a word.
				m[s].push_back(sub);
				break;
			} 
			vector<string> rest = _solve(s.substr(i), d, m);
			for (string &sent : rest) m[s].push_back(sub + " " + sent);
		}
	}

	return m[s];
}


vector<string> _wordBreak(string s, vector<string> &wordDict){
	uset<string> d;
	// put the words in to the set
	for (string &word : wordDict){
		d.insert(word);
	}

	umap<string, vector<string>> m;
	return _solve(s, d, m);
}





int main(){
	vector<string> wordDict;

	wordDict = {"cat", "cats", "and", "sand", "dog"};
	c_log(wordBreak("catsanddog", wordDict));

	wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
	c_log(wordBreak("pineapplepenapple", wordDict));

	wordDict = {"a","aa","aaa"};
	c_log(wordBreak("aaa", wordDict));


	dlog("\n\n-----------------------------\nMemoized:\n");
	// memoized solution tests
	wordDict = {"cat", "cats", "and", "sand", "dog"};
	c_log(_wordBreak("catsanddog", wordDict));

	wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
	c_log(_wordBreak("pineapplepenapple", wordDict));

	wordDict = {"a","aa","aaa"};
	c_log(_wordBreak("aaa", wordDict));

	return 0;
}



