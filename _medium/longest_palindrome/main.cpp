#include <mystd.h>


std::string longest_palindrome(std::string s){
	// base cases
	if (s == "" || s.length() == 1) return s;

	int longest_left = 0, longest_length = 0;
	
	auto expand_out = [&](int left, int right){
		for (; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++){ }
		int this_length = right - left - 1;
		if (this_length > longest_length){
			longest_left = left+1;
			longest_length = this_length;
		}
	};
	
	for (int i = 0; i < s.length()-1; ++i){
		expand_out(i, i+1); // check for even length palindromes
		expand_out(i, i); // check for odd length palindromes
	}

	return s.substr(longest_left, longest_length);
}



int main(){
	assert( longest_palindrome("abba") == "abba");
	assert( longest_palindrome("pabcba") == "abcba");
	assert( longest_palindrome("cookies") == "oo");
	assert( longest_palindrome("emilywantstoplay") == "tst");
	assert( longest_palindrome("ilovetimothyoshea") == "i");
	assert( longest_palindrome("") == "");
	assert( longest_palindrome("x") == "x");
	assert( longest_palindrome("xx") == "xx");
	assert( longest_palindrome("racecar") == "racecar");
	assert( longest_palindrome("tacocat") == "tacocat");

	return 0;
}


