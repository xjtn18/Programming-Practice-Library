//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given a string, store a sum of all the vowels that appear
//  					in each substring of that string.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// 
//	Solution:
//	Rather than counting the total number of vowels in each substring, we can split
//	the counting up by rechecking substrings multiple times later on in the iteration.
//	When we get to a vowel, count the number of indices before it and the number after.
//	Multiplying these 2 vowels gives us the number of possible substrings that can be
//	made that contain that vowel. We dont need to worry about when the count is higher
//	for times when the substring contains 2 or more vowels. In order to keep the 
//	time complexity linear, we can just count each substring as 1, based on the current
//	vowel we are at. The same substring will be counted again later in the linear search
//	but for the other vowels that it contains (if any more exist).
//
// TC: Linear
// SC: Constant
//




bool isVowel(const char &c){
	static string vowels = "aeiou";
	return count(vowels.begin(), vowels.end(), c);
}

long long countVowels(string word) {
	long long sigma = 0;
	int n = word.size();
	
	for (int i = 0; i < n; ++i){
		if (isVowel(word[i])){
			sigma += (i + 1) * (n - i);
		}
	}
  
	return sigma;
}



int main(){
	cout << countVowels("esekk") << endl;
	cout << countVowels("aa") << endl;
	cout << countVowels("aba") << endl;
	return 0;
}



