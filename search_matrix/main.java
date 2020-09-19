//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/18/2020
//  File type: Java source file
//  Description: 2x binary search through 2D sorted matrix to check if matrix contains target.
//////////////////////////////////////////////////////


/*
 * Logic:
 * Use binary search to iterate through the rows.
 * At each row, check first if the target is between the first and last element.
 * If it is, use binary search on this row to find the number.
 * If found, return True, else False.
 * In the case that the target could not possibly be in this row:
 * - If the target is greater than the last number in the row, split forward.
 * - If the target is less than the last number in the row, split backward.
*/

class main {
	public static boolean arrayBinarySearch(int[] arr, int target){
		int l = 0, r = arr.length - 1;
		int mid;
		while (l <= r){
			mid = (int)(l + r-l / 2);
			if (arr[mid] < target){
				l = mid + 1;
			} else if (arr[mid] > target){
				r = mid - 1;
			} else { // this is the number
				return true;
			}
		}
		return false;
	}

	public static int matrixBinarySearch(int[][] matrix, int target){
		int l = 0, r = matrix.length - 1;
		int mid;
		if (matrix.length == 0 || matrix[0].length == 0) {return -1;} // if empty matrix
		while (l <= r){
			mid = (int)(l + r-l / 2);
			if (matrix[mid][matrix[0].length-1] < target){
				l = mid + 1;
			} else if (matrix[mid][0] > target){
				r = mid - 1;
			} else { // the number is in this range
				return mid;
			}
		}
		return -1;
	}

	public static boolean searchMatrix(int[][] matrix, int target) {
		int array_index = matrixBinarySearch(matrix, target);
		if (array_index == -1) {return false;}
		return arrayBinarySearch(matrix[array_index], target);
	}

	public static void main(String args[]){
		System.out.println(searchMatrix(new int[][]{{1,2,3},{4,5,6}}, 1));
		System.out.println(searchMatrix(new int[][]{{1,2,3},{4,5,6}}, 0));
		System.out.println(searchMatrix(new int[][]{{1,2},{4,5},{8,10}}, 8));
		System.out.println(searchMatrix(new int[][]{{}}, 2));
		System.out.println(searchMatrix(new int[][]{}, 1));
	}

}

