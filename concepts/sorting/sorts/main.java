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
		// What bubble sort wants to do is take the next largest element
		// and swap it down to the end of the list. If we do this N-1 times,
		// we are gauranteed to have a sorted list. We can cut the main outer
		// loop short if we dont find an element that is greater than the 
		// following element, hence the use of the 'done' boolean.
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
		Integer[] arr = new Integer[]{7,4,3,5,2};

		bubbleSort(arr);
		alog(arr);


		bubbleSort(arr);
		alog(arr);

	}

}


