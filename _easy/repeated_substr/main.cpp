//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created: 10/4/21
//	File type: C++ source file
//	Description: Given a string, return whether or not there
//						exists a substring that could form the original
//						string when repeated any number of times.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

//
// Original solution:
// This is the most minimal brute force way of solving this
// problem that I could get. Iteratively grows the substring
// up 'til half the size of the original string and checks
// if that substring is reapeated to the end. The modulus check
// saves a lot of wasted time as well.
//
// SC:
// worst case O(N * M) where N is the length of the original string
// and M is the average size of the substring we are comparing
// with. A long string that is simply a doubled substring would
// be the worst time complexity for this method.
//
// TC:
// Creating the substrings would take up around O(M) memory.
//



bool repeats(const string &ss, const string &s){
	int pos = ss.length();
	while (pos < s.length()){
		if (s.substr(pos, ss.length()) != ss)
			return false;
		pos += ss.length();
	}
	return pos == s.length();
}


bool brute(string s) {
	if (s.length() == 1) return false;
	for (int i = ceil(s.length()/2.); i >= 1; --i){
		string ss = s.substr(0, i);
		if (s.length() % ss.length() == 0 && repeats(ss, s)){
			return true;
		}
	}
	return false;
}



//
// Optimal (linear time, linear space)
//

bool kmp(string s) {
	int i = 1;
	int j = 0;
	int n = s.length();

	while (i < n){
		if (s[i] == s[j]){
			i++;
			j++;
		} else {
			i += (j == 0);
			j = (j < 2) ? 0 : j-2;
		}
	}
	
	// we found a repeated substring and the substring was complete (length divisible by n)
	return j && n % (n-j) == 0;
}




int main(){
	dlog(brute("abab"));
	dlog(brute("ab"));
	dlog(brute("a"));
	dlog(brute("aa"));
	dlog(brute("aabaab"));
	dlog(brute("carcar"));
	dlog(brute("carcarcar"));
	dlog(brute("carcarb"));
	dlog(brute("carcabcarcab"));
	dlog(brute("carcabcar"));

	dlog("");

	dlog(kmp("abab"));
	dlog(kmp("ab"));
	dlog(kmp("a"));
	dlog(kmp("aa"));
	dlog(kmp("aaa"));
	dlog(kmp("aabaab"));
	dlog(kmp("carcar"));
	dlog(kmp("carcarcar"));
	dlog(kmp("carcarb"));
	dlog(kmp("carcabcarcab"));
	dlog(kmp("carcabcar"));
	dlog(kmp("carcarca"));


	return 0;
}



