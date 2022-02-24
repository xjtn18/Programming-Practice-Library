//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/6/22
//  File type: C++ source file
//  Description: Given 2 strings, return the minimum number of edits required to equate both strings.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

/*
	cuddles - cubbles --> 2
		longest substring is length 3

	horsey - abc --> 6
	horsey - sey --> 3

	Word2 is LONGER
	cuddle - scuddles --> 2 + 0
	cuddle - scubbles --> 2 + 2 = 4

	Word2 is SHORTER
	cuddle - ccuddle --> 

	Word2 is the SAME LENGTH
	the difference in length is 0, we can add that to our total as usual.
	Then scan through the words, any differences over

*/


int minDistance(string word1, string word2){
	int total = abs((int)(word1.length() - word2.length())); // atleast this many deletions/additions needed.
	if (word1.length() == word2.length()){
		for (int i = 0; i < word1.length(); ++i){
			total += word1[i] != word2[i];
		}

	} else if (word1.length() < word2.length()){
		for (int i = 0; i < word1.length(); ++i){
			total += word1[i] != word2[i];
		}

	} else { // word1 is longer
		int j = 0;
		int maxj = 0;
		for (int i = 0; i < word1.length(); ++i){
			if (word1[i] == word2[j]){
				++j;
				maxj = max(maxj, j);
			} else {
				j = 0;
			}
		}
		total += word2.length() - maxj;
	}

	return total;
}



int main(){
	string word1, word2;

	word1 = "happy";
	word2 = "cabby";
	dlog(minDistance(word1, word2));

	word1 = "happy";
	word2 = "apc";
	dlog(minDistance(word1, word2));

	word1 = "cuddles";
	word2 = "cubble";
	dlog(minDistance(word1, word2));

	return 0;
}



