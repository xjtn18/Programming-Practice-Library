//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	int i, j;
	string lcp = strs[0]; // longest possible common prefix
	for (i = 1; i < strs.size() && lcp != ""; ++i){
		for (j = 0; j < strs[i].length(); ++j){
			if (j >= lcp.length() || strs[i][j] != lcp[j]){
				break;
			}
		}
		lcp.erase(lcp.begin() + j, lcp.end());
	}
	return lcp;
}


int main(){
	vector<string> v = vector<string>({"ab", "a", "ab"});
	string ans = longestCommonPrefix(v);
	log(ans);
	return 0;
}



// Test cases
/*
	["flower","flow","flight"]
	["dog","racecar","car"]
	["cheese"]
	["cheese", "cheese", "cheese"]
	["cheese", "cheet", "cheap"]
*/
