//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/26/22
//  File type: Java source file
//  Description:
//////////////////////////////////////////////////////
import java.util.Arrays;
import myjava.*;


class Solution {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void alog(int[] arr){ System.out.println(Arrays.toString(arr)); }
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }


	public static int[] findSignatureCounts(int[] arr){
		int[] counts = new int[arr.length];

		for (int i = 0; i < arr.length; ++i){
			int count = 0;
			int j = i;
			do {
				count++;
				j = arr[j]-1;
			} while (j != i);
			counts[i] = count;
		}

		return counts;
	}


	public static void main(String[] args){
		alog(findSignatureCounts(new int[]{2,1})); // [2,2]
	}

}


