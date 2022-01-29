//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/26/22
//  File type: Java source file
//  Description: Given a list of n ints, return the median value at i for each i from 0 to n-1.
//////////////////////////////////////////////////////
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Comparator;
import myjava.*;



/*
 * Idea: Use a min heap and max heap.
 * The max heap will store the lower half of the data stream and the min heap
 * will store the upper half of the data stream.
 * The head of both these heaps represent the middle values, we will aribitrarily
 * pick the smaller half heap to store the exact median in the case that the input
 * stream has an odd number of values. In this case, the smaller heap may contain
 * 1 more value than the larger heap.
 * When adding a median to our result, we will check if the heaps are equal in size,
 * if they are than the median the is the average of the 2 heads, else, the median
 * is just the head of the smaller half (because we've chosen smaller to hold it).
 * All we have to do is make sure the sizes of both heaps are either equal or the
 * aribitrarily chosen of the 2 heaps is 1 larger than the other.
 *
 */

class Solution {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void alog(int[] arr){ System.out.println(Arrays.toString(arr)); }
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }


	int[] findMedian(int[] arr){
		/*
			TC: O(log n)
			SC: O(n) to hold the solution result.
		 */
		PriorityQueue<Integer> smaller = new PriorityQueue<>(Comparator.reverseOrder()); // max heap
		PriorityQueue<Integer> bigger = new PriorityQueue<>(); // min heap
		int[] res = new int[arr.length];

		res[0] = arr[0];
		smaller.add(arr[0]);

		for (int i = 1; i < arr.length; ++i){
			int val = arr[i];
			if (smaller.size() == bigger.size()){
				if (val < bigger.peek()){ // go into smaller
					smaller.add(val);
				} else { // go into bigger
					smaller.add(bigger.poll());
					bigger.add(val);
				}
			} else { // sizes are not equal (smaller holds one more value)
				if (val < smaller.peek()){ // go into smaller
					bigger.add(smaller.poll());
					smaller.add(val);
				} else { // go into bigger
					bigger.add(val);
				}
			}
			res[i] = (smaller.size() == bigger.size()) ? (smaller.peek() + bigger.peek()) / 2 : smaller.peek();
		}

		return res;
	}

	public void run(){
		alog(findMedian(new int[]{1,5,3,5})); // 1,3,3,4
		alog(findMedian(new int[]{3,1,1,4})); // 3,2,1,2
		alog(findMedian(new int[]{3,4,5})); // 3,3,4
		alog(findMedian(new int[]{1,1})); // 1, 1
		alog(findMedian(new int[]{5})); // 5
	}

	public static void main(String[] args){
		new Solution().run();
	}

}


