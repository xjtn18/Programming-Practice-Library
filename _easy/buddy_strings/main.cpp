//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/10/21
//  File type: C++ source file
//  Description: Given 2 strings, return true if the first string can have
//  					exactly 2 indices swapped such that it makes it equal to
//  					the other string.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


bool buddyStrings(string s, string goal){
	if (s.length() != goal.length()) return false;
	int mismatch = 0;
	char need, has;
	unordered_set<char> seen;
	bool duplicate = false;

	for (int i = 0; i < s.size(); ++i){
		if (s[i] != goal[i]){
			mismatch++;
			if (mismatch == 1){
				need = goal[i];
				has = s[i];
			} else if (mismatch == 2){
				if (need != s[i] || has != goal[i]) return false;
			} else { // mismatch is greater than 2
				return false;
			}
		}
		duplicate = duplicate || seen.count(s[i]);
		seen.insert(s[i]);
	}

	return mismatch == 2 || (mismatch == 0 && duplicate);
}




int main(){
	/*
	cout << buddyStrings("ab", "ba") << endl; // 1
	cout << buddyStrings("ab", "ab") << endl; // 0
	cout << buddyStrings("a", "b") << endl; // 0
	cout << buddyStrings("cheese", "chesee") << endl; // 1
	cout << buddyStrings("heese", "chesee") << endl; // 0
	cout << buddyStrings("cheese", "cehsee") << endl; // 0
	cout << buddyStrings("aab", "aab") << endl; // 1
	cout << buddyStrings("abac", "abad") << endl; // 0
	*/
	cout << buddyStrings("ab", "babbb") << endl; // 0
	return 0;
}



