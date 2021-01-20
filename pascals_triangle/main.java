//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/20/2021
//  File type: Java source file
//  Description: generate first n rows of pascals triangle
//////////////////////////////////////////////////////


import java.util.List;
import java.util.ArrayList;

class Solution {

	public List<List<Integer>> generate(int numRows){
		List<List<Integer>> result = new ArrayList<List<Integer>>(numRows);

		if (numRows != 0){
			result.add(new ArrayList<Integer>());
			result.get(0).add(1); // peak of triangle
		}

		for (int i = 1; i < numRows; ++i){
			result.add(new ArrayList<Integer>());

			result.get(i).add(1);
			for (int j = 1; j < i; ++j){
				result.get(i).add(result.get(i-1).get(j-1) + result.get(i-1).get(j));
			}
			result.get(i).add(1);
		}

		return result;
	}

}



class main {

	public static void main(String args[]){
		Solution sol = new Solution();
		System.out.println(sol.generate(5));
		System.out.println(sol.generate(1));
		System.out.println(sol.generate(0));
	}
}
