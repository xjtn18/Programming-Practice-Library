//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: Java source file
//  Description:
//////////////////////////////////////////////////////
import java.util.Arrays;
import myjava.*;


class Solution {

	static <T> void log(T input){ System.out.println(input); }
	static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	static void qlog(String input){ log("'" + input + "'"); }
	static void qlog(char[] input){ log("'" + new String(input) + "'"); }


	static class Node {
		int data; 
		Node left; 
		Node right; 

		Node() {
			this.data = 0; 
			this.left = null; 
			this.right = null; 
		}

		Node(int data) {
			this.data = data; 
			this.left = null; 
			this.right = null; 
		}
	}


	public static int visibleNodes(Node root){
		// Counts the number of leftmost nodes, AKA returns the height of the tree.
		if (root == null) return 0;
		return Math.max(visibleNodes(root.left)+1, visibleNodes(root.right)+1);
	}


	public static void main(String[] args){
		Node root = new Node(2);
		root.left = new Node(1);
		root.right = new Node(3);
		root.right.left = new Node(4);
		root.right.right = new Node(5);
		root.right.right.left = new Node(6);
		log(visibleNodes(root));
	}

}


