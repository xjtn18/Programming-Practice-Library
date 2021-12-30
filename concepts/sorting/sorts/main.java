//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/29/21
//  File type: Java source file
//  Description: All the flagship sorting methods.
//////////////////////////////////////////////////////

import java.util.Arrays;



class Solution {

	public static <T> void log(T input){
		System.out.println(input);
	}

	public static <T> void alog(T[] arr){
		System.out.println(Arrays.toString(arr));
	}



	public static <T extends Comparable<T>> void bubbleSort(T[] arr){
		int n = arr.length;
		boolean done = false;

		for (int i = 0; i < n-1 && !done; ++i){
			done = true;
			for (int j = 0; j < n-i-1; ++j){
				if (arr[j+1].compareTo(arr[j]) < 0){
					T temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					done = false;
				}
			}
		}
	}



	public static void main(String args[]){
		// random unsorted array of integers
		Integer[] arr = new Integer[]{4,1,5,3,4,19,3,20,3,7};

		bubbleSort(arr);
		alog(arr);


		bubbleSort(arr);
		alog(arr);

	}

}


