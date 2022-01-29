//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: Java source file
//  Description: Given 2 arrays, return whether or not you can do any number of subarray reversals
//  					on either array to make them equal. NOTE: This is exactly the same as asking if
//  					they contain the same values.
//////////////////////////////////////////////////////
import java.util.List;
import java.util.Arrays;
import myjava.*;



class Solution {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }


	public static boolean areTheyEqual(int[] array_a, int[] array_b) {
		int[] char_count_a = new int[10];
		for (int i = 0; i < array_a.length; ++i){
			char_count_a[array_a[i]]++;
		}

		int[] char_count_b = new int[10];
		for (int i = 0; i < array_b.length; ++i){
			char_count_b[array_b[i]]++;
			if (char_count_b[array_b[i]] > char_count_a[array_b[i]])
				return false;
		}
		return true;
	}


	public static void main(String[] args){
		log(areTheyEqual(new int[]{1,2,3,4,5}, new int[]{5,2,4,3,1}));
	}

}


