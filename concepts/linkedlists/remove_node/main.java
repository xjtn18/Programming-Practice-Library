//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/3/22
//  File type: Java source file
//  Description: Remove a linked list node given the node that we
//				want to remove.
//////////////////////////////////////////////////////

import java.util.Arrays;



class Node {

	int val;
	Node next;

	Node(int _val){
		val = _val;
	}

	public static Node buildList(String data){
		int sIndex = 0;
		Node head = new Node(0);
		Node curr = head;
		while (curr != null){
			int nextComma = data.indexOf(',', sIndex);
			if (nextComma == -1) nextComma = data.length();
			curr.val = Integer.parseInt(data.substring(sIndex, nextComma));
			sIndex = nextComma + 1;
			if (sIndex < data.length()) curr.next = new Node(0);
			curr = curr.next;
		}
		return head;
	}

	void print(){
		Node node = this;
		System.out.printf("[%d", node.val);
		node = node.next;
		while (node != null){
			System.out.printf(", %d", node.val);
			node = node.next;
		}
		System.out.print("]\n");
	}

	void remove(Node node){
		// NOTE: using this method, it is impossible to remove the tail node of the list.
		if (node == null|| node.next == null) {
			Solution.log("Node to be removed is null or is a tail node.");
		} else {
			node.val = node.next.val;
			node.next = node.next.next;
		}
	}

	static Node removeAll(Node head, int val){
		Node dummy = new Node(0);
		dummy.next = head;
		Node i = dummy;

		while (i != null){
			Node j = i.next;
			while (j != null && j.val == val) j = j.next;
			i.next = j;
			i = i.next;
		}
		head = dummy.next;
		return head;
	}

	// TAKEAWAY: In java, arguments are as a "reference, by value". This means that any operations we
	// perform or methods we call on the arguments will reflect those changes in the calling environment;
	// however, because it is not a true reference, assigning the arguments to something else simply
	// points the passed reference to another object, and this is not reflected in the calling environment.
	// This means that for a function such as "removeAll" above where we remove all instances of a value
	// in a linked list, if the HEAD of the list is the value we are trying to remove, we cannot reassign the
	// head such that it also changes in the calling environment. For the solution above, I am doing a hacky
	// edge case check for the first node by doing an alternative approach where we remove a node by swapping
	// that node with the node after it. NOTE: This method does not work if we want to remove the last node,
	// because what would we be swapping the value with? At this point we would need to set the node to null,
	// which will not refelct in the calling environment.
	//
	// There are two workarounds to this:
	//
	// A: You can create another wrapper class called "LinkedList"
	// that stores the head node. Say you have an instance of LinkedList called 'L'. Calling L.removeAll()
	// will also remove the head node (if its to be removed) because we'd be reassigning the L.head member.
	//
	// B: The other approach is to instead write a function that returns a node, the node whos address points
	// to the new head of the list. Only downfall to this is that you have to remember the messy assignment
	// syntax when calling the method from the calling environment.

}




class Solution {

	public static <T> void log(T input){ System.out.println(input); }
	public static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
	public static void qlog(String input){ log("'" + input + "'"); }
	public static void qlog(char[] input){ log("'" + new String(input) + "'"); }


	public static void main(String args[]){
		//Node n = Node.buildList("7,1,7,6,3,7,7,4");
		Node n = Node.buildList("7,1,7,7,7,5,2,6,2,7");
		n.print();
		n = Node.removeAll(n, 7);
		n = Node.removeAll(n, 2);
		n.print();
	}

}


