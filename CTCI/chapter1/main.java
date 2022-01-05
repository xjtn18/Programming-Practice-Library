//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: Java source file
//  Description: My answers to chapter 1 of Cracking the Coding Interview.
//////////////////////////////////////////////////////

import java.util.Arrays;
import java.util.HashSet;
import java.util.HashMap;
import java.lang.*;



class Chapter_1 {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void mlog(Integer[][] mat){
		for (int i = 0; i < mat.length; ++i){
			if (i == 0) System.out.printf("[[%d", mat[i][0]);
			else System.out.printf(" [%d", mat[i][0]);
			for (int j = 1; j < mat[0].length; ++j) System.out.printf(", %d", mat[i][j]);
			if (i == mat.length-1) System.out.print("]]\n");
			else System.out.print("]\n");
		}
	}
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }




	static boolean isUnique(String s){
		// TC: O(N) assuming HashSet.contains() runs in constant time.
		// SC: O(1), set will store a max of 26 of the chars in the English alphabet.
		HashSet<Character> seen = new HashSet<>();
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
		HashMap<Character, Integer> map = new HashMap<>();

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


	static boolean oneEditAway(String a, String b){
		/*
			TC : O(N)
			SC : O(1)
			Approach: First check if the length of strings are different
			by 2 or more; in this case we would neead atleast 2 addition
			edits to make these equivalent, so we know they cant be one
			edit way. Next, we traverse down the strings and keep a integer
			counter that counts how many mismatches we have. When the characters
			are the same, increment both pointers to our strings. If they are
			NOT equal, increment the pointer to the longer string UNLESS the
			strings are of equal length, in which case we're just checking if
			the strings have the same characters at each index. If we get to
			the end of the smaller string and the number of mismatches is 2
			or greater, than return false, else return true.
		 */
		if (Math.abs(a.length() - b.length()) >= 2) return false;
		int smaller = Math.min(a.length(), b.length());
		int i = 0, j = 0;
		int mm = 0;
		while (mm < 2 && j < smaller){
			if (a.charAt(i) == b.charAt(j)){
				++i; ++j;
			} else {
				mm++;
				if (a.length() == b.length()){
					++i; ++j;
				} else {
					// increment the pointer to the longer string
					if (a.length() == smaller) ++j;
					else ++i;
				}
			}
		}

		return mm < 2;

	}


	static String compress(String s){
		StringBuilder res = new StringBuilder();
		int i = 0;
		while (i < s.length()){
			int counter = 1;
			while (i+1 < s.length() && s.charAt(i) == s.charAt(i+1)){
				++counter;
				++i;
			}
			res.append(s.charAt(i));
			res.append(counter);
			++i;
		}
		if (res.length() >= s.length()) return s;
		return res.toString();
	}

	// cleaner implementation
	static String compress2(String s){
		StringBuilder res = new StringBuilder();
		int consec = 0;

		for (int i = 0; i < s.length(); ++i){
			++consec;
			if (i == s.length()-1 || s.charAt(i) != s.charAt(i+1)){
				res.append(s.charAt(i));
				res.append(consec);
				consec = 0;
			}
		}

		return (res.length() < s.length()) ? res.toString() : s;

	}



	static void rotateCell(Integer[][] mat, int i, int j){
		for (int _i = 0; _i < 3; ++_i){
			int ni = mat.length-j-1;
			int nj = i;
			int temp = mat[i][j];
			mat[i][j] = mat[ni][nj];
			mat[ni][nj] = temp;
			i = ni; j = nj;
		}
	}

	static void rotate90(Integer[][] mat){
		// Given a square matrix, rotate in place by 90 degrees
		for (int i = 0; i < mat.length; ++i){
			for (int j = i; j < mat.length-i-1; ++j){
				rotateCell(mat, i, j);
			}
		}
	}




	static void zeroMatrix(Integer[][] mat){
		/*
			TC : O(MN)
			SC : O(M+N)
			Given a matrix, if mat[i][j] is 0, set its whole
			column and row to 0.
			Approach: Traverse through the whole matrix twice.
			In the first run, keep track of which rows and which
			columns have a zero in them. We can use single dimension
			arrays for both columns and rows. In the second run,
			simply set matrix[i][j] if the ith row has a zero
			of if the jth column has a zero.
			NOTE: We can perform this operation using
			no auxillary space without sacrificing runtime by
			using the first column and the first row of the
			matrix itself to store what rows and columns should
			be zeroed respectively. The solution is outlined in
			the book.
		 */
		boolean[] rowsZero = new boolean[mat.length];
		boolean[] colsZero = new boolean[mat[0].length];

		// find columns and rows to zero out
		for (int i = 0; i < mat.length; ++i){
			for (int j = 0; j < mat[0].length; ++j){
				if (mat[i][j] == 0){
					rowsZero[i] = true;
					colsZero[j] = true;
				}
			}
		}
		// set all zeroes
		for (int i = 0; i < mat.length; ++i){
			for (int j = 0; j < mat[0].length; ++j){
				if (rowsZero[i] || colsZero[j]){
					mat[i][j] = 0;
				}
			}
		}
	}


	static int[] getLPS(String pattern){
		int[] lps = new int[pattern.length()];
		lps[0] = 0;

		int j = 0, i = 1;
		while (i < pattern.length()){
			if (pattern.charAt(i) == pattern.charAt(j)){
				lps[i] = lps[i-1] + 1;
				++i; ++j;
			} else {
				if (j == 0){
					lps[i] = 0;
					++i;
				} else {
					j = lps[j];
				}
			}
		}
		return lps;
	}

	static boolean isSubstring(String pattern, String text){
		// Using the KMP algorithm
		if (pattern.length() == 0) return true;
		int[] lps = getLPS(pattern);
		int i = 0, j = 0;
		while (i < text.length() && j < pattern.length()){
			if (text.charAt(i) == pattern.charAt(j)){
				++i; ++j;
			} else {
				if (j == 0) ++i;
				else j = lps[j-1];
			}
		}

		return j == pattern.length();
	}

	// My intial solution
	static boolean stringRotation(String original, String rotated){
		/*
			TC : O(N), assuming we use the linear KMP substring search
			SC : O(N)
			Approach:
			First, we know that if the strings are not the same length,
			then they cant be rotations of each other. Return false. Else,
			traverse through both strings simultaneously; when
			they do not match, increment our pointer to the original string.
			When they do match, increment our pointer to both strings.
			Once we reach the end of the original string, call isSubstring
			with the remainder of the rotated string as the pattern, and the
			original as the text to be searched. If the remainder is found
			in the original strings prefix, then they are valid rotations.

		 */
		if (original.length() != rotated.length()) return false;
		int i = 0, j = 0;
		while (i < original.length()){
			j += (original.charAt(i) == rotated.charAt(j)) ? 1 : 0;
			++i;
		}

		String remainder = rotated.substring(j);
		String prefix = original.substring(0, original.length()-j);
		return isSubstring(remainder, prefix);
	}


	static boolean stringRotationBetter(String original, String rotated){
		/*
			TC : O(N)
			SC : O(N)
			This solution fits much better with the spirit of the problem.
			My original solution simply uses "isSubstring" as a way of
			checking if the prefix of the rotated stirng matches the suffix
			of the original string, when isnt really checking for a "substring"
			at all. The solution the book was looking is below.
			Explanation: If the two strings are rotations of each other,
			then that means they formed by the two same substrings but with
			the substrings swapped, so s1 = xy and s2 = yx. Given this, then
			it makes sense that in some new string s3, formed as xyxy,
			the rotated string s2 must be a substring within s3. If it isnt,
			then s1 and s2 are not rotations of each other.
		 */
		if (original.length() != rotated.length() || original.length() == 0) return false;
		String concat = original + original;
		return isSubstring(rotated, concat);
	}


	public static void main(String[] args){
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
		log(oneEditAway("moonrock","moonro")); // false
		log(oneEditAway("cheese","ceese")); // true
		log(oneEditAway("a","")); // true
		log(oneEditAway("ab","c")); // false
		log(oneEditAway("abcd","abcd")); // true
		log(oneEditAway("abkd","abcd")); // true
		log(oneEditAway("","")); // true
		log(oneEditAway("","aa")); // false

		log("\n-- Question 5 --");
		log(compress("aaaabbbcddeeeee"));
		log(compress("apple")); // apple
		log(compress("a")); // a
		log(compress("aa")); // aa
		log(compress("aaa")); // a3
		log(compress("aaabccc")); // a3b1c3
		qlog(compress("")); // ""
		log("");

		log(compress2("aaaabbbcddeeeee"));
		log(compress2("apple")); // apple
		log(compress2("a")); // a
		log(compress2("aa")); // aa
		log(compress2("aaa")); // a3
		log(compress2("aaabccc")); // a3b1c3
		qlog(compress2("")); // ""

		log("\n-- Question 6 --");
		Integer[][] mat;
		mat = new Integer[][]{{1,2,3}, {4,5,6},{7,8,9}};
		mlog(mat);
		rotate90(mat);
		mlog(mat);
		mat = new Integer[][]{{1,2},{3,4}};
		mlog(mat);
		rotate90(mat);
		mlog(mat);
		mat = new Integer[][]{{1}};
		mlog(mat);
		rotate90(mat);
		mlog(mat);

		log("\n-- Question 7 --");
		mat = new Integer[][]{{1,0,3},{4,5,6},{7,8,0}};
		mlog(mat);
		zeroMatrix(mat);
		mlog(mat);
		mat = new Integer[][]{{0},{2}};
		mlog(mat);
		zeroMatrix(mat);
		mlog(mat);

		log("\n-- Question 8 --");
		log(stringRotationBetter("waterbottle", "erbottlewat")); // yes
		log(stringRotationBetter("water", "waterr")); // no
		log(stringRotationBetter("w", "w")); // yes
		log(stringRotationBetter("", "")); // no
		log(stringRotationBetter("ab", "ba")); // yes
		log(stringRotationBetter("water", "wager")); // no
		log(stringRotationBetter("banana", "ananan")); // oops! NO
	}

}


