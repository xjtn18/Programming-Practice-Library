//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: Java source file
//  Description: My answers to chapter 1 of Cracking the Coding Interview.
//////////////////////////////////////////////////////

import java.util.Arrays;
import java.util.HashSet;
import java.util.HashMap;



class Chapter_1 {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }




	static boolean isUnique(String s){
		// TC: O(N) assuming HashSet.contains() runs in constant time.
		// SC: O(1), set will store a max of 26 of the chars in the English alphabet.
		HashSet<Character> seen = new HashSet<Character>();
		// NOTE: This could also be done with a 26 length array of booleans.

		for (int i = 0; i < s.length(); ++i){
			if (seen.contains(s.charAt(i))) return false;
			seen.add(s.charAt(i));
		}

		return true;

		// Follow-up: What if we cant use any data structures?
		// 	Assuming an array is considered a data structure,
		// 	we would be forced to a brute force O(n^2) solution
		// 	where for every character, we check every other index
		// 	in the string to see if other chars are the same. This
		// 	is the worst case, meaning the string is actually unique.
		// 	In the best case this runs in constant time (where the
		// 	first 2 indices we check have the same character)
	}

	static boolean arePermutations(String a, String b){
		// Approach: Two strings are permutations of each other if they have the same characters
		// 			and the same number of those characters. By using a HashMap where the key
		// 			is the character and the value is the count of that character, we can see
		// 			if the strings are permutations of each other. I'll fill the map with data
		// 			from the first string, remove from the map using data from the second string,
		// 			and then return whether or not the map is empty at the end. I will assume that
		// 			fully equal strings are considered permutations of each other. If not, you could
		// 			do a linear check for equality between A and B at the beginning.
		// TC: O(M+N)
		// SC: O(z) where z is the number for unique characters in the first string.

		if (a.length() != b.length()) return false; // shortcut; they cant be permutations if lengths dont match.
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();

		int i;
		for (i = 0; i < a.length(); ++i){
			map.put(a.charAt(i), map.getOrDefault(a.charAt(i), 0) + 1);
		}

		for (i = 0; i < b.length(); ++i){
			if (!map.containsKey(b.charAt(i))) return false;
			map.put(b.charAt(i), map.get(b.charAt(i)) - 1);
			map.remove(b.charAt(i), 0); // remove map entry if value is 0
		}

		return map.isEmpty();
	}



	// My initial solution
	static void _URLify(char[] str, int len){
		// For every whitespace in the str, replace it with "%20".
		// The char array holds sufficient space at the end.
		// 'len' refers to the 'true' length of string (without the extra whitespace).
		// NOTE: Doing this in-place means we have to sacrifice time complexity
		// by shifting all characters past the white space forward by
		// X, where X is the length of the replacement value - 1.
		//
		// TC: O(N*W) where W is the number of white spaces to replace.
		// SC: O(1)

		int i = 0;
		while (i < len){
			if (Character.isWhitespace(str[i])){
				for (int j = len-1; j > i; --j){
					str[j+2] = str[j];
				}
				str[i] = '%';
				str[i+1] = '2';
				str[i+2] = '0';
				len += 2;
				i += 3;
			} else {
				i++;
			}
		}

	}

	
	// Optimal solution
	static int countChar(char[] str, int stop, char target){
		int count = 0;
		for (int i = 0; i < stop; ++i){
			if (str[i] == target) count++;
		}
		return count;
	}

	static void URLify(char[] str, int len){
		// The faster approach to this would be work backwards down the string.
		// First we calculate the last index at which a character would
		// exist at the end of our new string. We do this using the number
		// of spaces, which takes O(N) time to find. Then we simply map
		// the original values to their new indices, and this avoids having
		// to shift the entire array like we did every time we replaced a space
		// in the previous 'forward iteration' solution.
		//
		// TC: O(N)
		// SC: O(1)

		int numSpaces = countChar(str, len, ' ');
		int newIndex = len + numSpaces*2 - 1;

		for (int i = len-1; i >= 0; --i){
			if (str[i] == ' '){
				str[newIndex] = '0';
				str[newIndex-1] = '2';
				str[newIndex-2] = '%';
				newIndex -= 3;
			} else {
				str[newIndex] = str[i];
				newIndex--;
			}
		}
	}


	public static void main(String args[]){
		log("\n-- Question 1 --");
		log(isUnique("hello"));
		log(isUnique(""));
		log(isUnique("a"));
		log(isUnique("abcdefghijklmnopqrstuvwxyz"));
		log(isUnique("yeah no "));
		
		log("\n-- Question 2 --");
		log(arePermutations("", ""));
		log(arePermutations("a", ""));
		log(arePermutations("", "a"));
		log(arePermutations("a", "a"));
		log(arePermutations("hello", "lolhe"));
		log(arePermutations("babe", "baby"));
		log(arePermutations("babee", "babbe"));
		log(arePermutations("harry potter", "pothar terry"));
		
		log("\n-- Question 3 --");
		String input;

		input = "I like pizza";
		char[] carray = (input + "    ").toCharArray();
		URLify(carray, input.length());
		qlog(carray);


		log("\n-- Question 4 --");

	}

}


