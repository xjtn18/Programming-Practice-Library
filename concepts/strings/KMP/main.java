//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/29/21
//  File type: Java source file
//  Description: Knuth Morris Pratt (KMP) linear substring search algorithm.
//////////////////////////////////////////////////////


//
// Idea:
//
// The reasoning behind the KMP algorithm is that we want to do better than the brute
// force method of finding a substring match in some text, where the text may or may not
// contain some pattern we are searching for.
//
// Assume the length of the text is N, and the length of the pattern is M. Brute force
// would mean every time theres a mismatch, we reset our search index in the pattern
// to the beginning. This means that in the worst case, our brute force algorithm
// would run O(M*N) time.
//
// By using some special indexing techniques and an auxillary array, we can drop this
// worst case to M+N (linear) using the KMP algorithm.
//
// The idea behind this algorithm is that rather than running a full linear search through
// the pattern for every index in the text, we will create an array A of integers where,
// for an index 'i' in the pattern string, A[i] holds the index where the pattern from
// A[i] to 'i' (inclusive) matches the pattern from 0 to A[i]-1 (inclusive). This means
// that we dont need to traverse backwards in the text to compare the the next index with
// all the pattern. We can recognize that as we were comparing the last substring, we matched
// a suffix with the prefix of our search pattern, and so we can start our next search
// with a pattern index of A[i];
//

import java.util.Arrays;


class Solution {

	public static <T> void log(T input){
		System.out.println(input);
	}

	public static <T> void alog(T[] arr){
		System.out.println(Arrays.toString(arr));
	}


	static Integer[] computeLPS(String pattern){
		Integer[] LPS = new Integer[pattern.length()];
		Arrays.fill(LPS, 0);

		int j = 0;
		int i = 1;
		while (i < pattern.length()){
			if (pattern.charAt(i) == pattern.charAt(j)){
				LPS[i] = j+1;
				j++; i++;
			} else {
				if (j == 0) i++;
				j = (j == 0) ? 0 : LPS[j-1];
			}
		}

		return LPS;
	}


	static int kmp(String text, String pattern){
		// Returns the index in 'text' that starts a full match of 'pattern'.
		// If no match is found, returns -1.
		if (pattern == "") return 0;
		int n = text.length();
		int m = pattern.length();
		Integer[] LPS = computeLPS(pattern);

		int i = 0;
		int j = 0;
		while (i < n && j < m){
			if (text.charAt(i) == pattern.charAt(j)){
				i++; j++;
			} else {
				if (j == 0) i++;
				j = (j == 0) ? 0 : LPS[j-1];
			}
		}

		return (j == m) ? i-m: -1;
	}



	public static void main(String args[]){
		log(kmp("appappappapea", "appapea"));
		log(kmp("a", "a"));
		log(kmp("", "a"));
		log(kmp("oreo", ""));
		log(kmp("ab", "b"));
		log(kmp("ab", "a"));
		log(kmp("ororeo", "oreo"));
	}

}


