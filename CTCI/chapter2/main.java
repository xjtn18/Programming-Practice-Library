//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/1/22
//  File type: Java source file
//  Description: My answers to chapter 2 of Cracking the Coding Interview.
//////////////////////////////////////////////////////

import java.util.Arrays;
import java.util.HashSet;
import java.util.HashMap;
import java.lang.*;
import myjava.LinkNode;



class Chapter_2 {

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



	static LinkNode removeDuplicates(LinkNode head){
		if (head == null) return null;
		HashSet<Integer> seen = new HashSet<>();
		LinkNode n = head;

		while (n != null){
			seen.add(n.val);
			while (n.next != null && seen.contains(n.next.val)){
				n.next = n.next.next;
			}
			n = n.next;
		}

		return head;
	}

	// FOLLOW UP: How would you do this without a temporory buffer?

	static LinkNode removeAll(LinkNode head, int val){
		// Given a linked list, return the same list with
		// the nodes removed whos values match 'val'.
		if (head == null) return null;
		LinkNode dummy = new LinkNode(0);
		dummy.next = head;
		LinkNode n = dummy, j;
		while (n != null){
			j = n.next;
			while (j != null && j.val == val) j = j.next;
			n.next = j;
			n = n.next;
		}
		return dummy.next;
	}

	static LinkNode removeDuplicates2(LinkNode head){
		if (head == null) return null;

		LinkNode i = head;
		while (i != null){
			i.next = removeAll(i.next, i.val);
			i = i.next;
		}

		return head;
	}


	static int KthToLast(LinkNode head, int k){
		/*
			Approach: Rather than doing a full pass to derive the length
			and doing another pass to stop at Length - k, we can do this
			a little faster by simply moving a pointer (n) k steps ahead of
			the head of the list. Once we've done that, we simply progress
			both n and the head pointer until n reaches the end of the list.
			We know wherever the head points is k away from n, and since n
			points to the end of the list, the head pointers value is our
			answer. We just need to check if when we first progressed n
			by k steps if we reached the end of the list before reaching k.
			In this case, the list does not have an element K spots from the
			end because the list is too small, and so here I'll just return
			the value of the first element in the list.
			TC: O(N), traverse k times, than traverse 2 pointers n-k times.
			SC: O(1)
		 */
		if (head == null || k <= 0) return -1;
		LinkNode n = head;
		int i;
		for (i = 0; i < k && n != null; ++i, n = n.next);
		if (n == null && i < k) return head.val; // no kth last element
		while (n != null){
			n = n.next;
			head = head.next;
		}
		return head.val;
	}

	static void deleteMiddle(LinkNode n){
		/*
			Approach: If you want to remove a node in
			linked list but you are only given the node to
			remove itself, we can pretend that we want to
			remove the next node. Before setting the removal
			nodes .next to .next.next, lets copy the value of
			the next node into the removal node, transitioning
			the value of the next node into the current node.
			We can then safely skip over the next node which is
			just a duplicate at this point.
			NOTE: Because we are sure we are given a node
			in the MIDDLE of the list, we dont need to do
			and edge case or null checks.
		 */
		n.val = n.next.val;
		n.next = n.next.next;
	}


	static LinkNode partition(LinkNode head, int part){
		/*
			Approach: Use 2 pointers i and j, which both start at the head.
			Let i refer to the first element of the second (>=) partition.
			If j.val is < the partition value, then the node that i points
			to should now hold that value, so do a swap between i and j's
			values, then increment i to point to the new beginning of the
			larger partition, and increment j to point to the next value
			to process. If the value of j.val is >= to the partition value,
			leave it where it is and increment j. Once j is the null, the
			list will be partitioned, in-place.
			TC: O(N), must visit every node to see if its smaller or greater.
			SC: O(1), in-place
		 */
		if (head == null) return null;
		LinkNode i = head, j = head;
		while (j != null){
			if (j.val < part){
				// swap i and j
				int temp = i.val;
				i.val = j.val;
				j.val = temp;
				j = j.next;
				i = i.next;
			} else {
				j = j.next;
			}
		}
		return head;
	}

	static LinkNode addNumbers(LinkNode num1, LinkNode num2){
		/*
			Approach: Since the linked lists of digits are already
			reversed, we can easily sum the numbers using the basic
			process of addition. We will sum the corresponding digits
			one by one as long as we hace not reached the end of both
			lists. We need to keep track of whether our last digit sum
			was greater than 10 (our base) in which case we need to add
			and extra 1 to our next digit sum. At the end when we've exhausted
			both lists, check to make sure that carry is not set; if it is set,
			the our answer list needs a new LinkNode with the value of 1.
			We build the list by adding to the end of since we are summing
			the numbers backwards, we also want the answer to be backwards
			as well.
			TC: O(M+N), linear.
			SC: O(N), because we are building a new list to store the answer.
					N here representing the length of the longer number.
		 */
		LinkNode dummy = new LinkNode(0);
		LinkNode n = dummy;
		boolean carry = false;

		while (num1 != null || num2 != null){
			int sum = 0;
			if (num1 != null){
				sum += num1.val;
				num1 = num1.next;
			}
			if (num2 != null){
				sum += num2.val;
				num2 = num2.next;
			}
			sum += (carry) ? 1 : 0;
			carry = sum >= 10;
			n.next = new LinkNode(sum % 10);
			n = n.next;
		}

		if (carry){
			n.next = new LinkNode(1);
		}

		return dummy.next;
	}

	// FOLLOW UP: Suppose the digits for both numbers are NOT in reverse order.

	static LinkNode reverse(LinkNode head){
		LinkNode prev = null, next;
		while (head != null){
			next = head.next;
			head.next = prev;
			prev = head;
			head = next;
		}

		return prev;
	}

	static LinkNode addNumbers2(LinkNode num1, LinkNode num2){
		/*
			Adding the numbers but this time they are NOT reversed.
			Simply call a reverse function on both arguments and
			then sum the digits in a similar fashion; however, this
			time we also want to the answer to be in forward order,
			so we need to build our answer list from end to front.
			TC: O(M+N), reverse the numbers (linear) + sum all digits (linear).
			SC: O(N), and the reversing is done in place.
		 */

		LinkNode head = null, n;
		boolean carry = false;
		num1 = reverse(num1);
		num2 = reverse(num2);
		while (num1 != null || num2 != null){
			int sum = 0;
			if (num1 != null){
				sum += num1.val;
				num1 = num1.next;
			}
			if (num2 != null){
				sum += num2.val;
				num2 = num2.next;
			}
			sum += (carry) ? 1 : 0;
			n = new LinkNode(sum % 10);
			n.next = head;
			head = n;
			carry = sum >= 10;
		}

		if (carry){
			n = new LinkNode(1);
			n.next = head;
			head = n;
		}

		return head;
	}


	static LinkNode reverseCopy(LinkNode head){
		LinkNode newHead = null, n;
		while (head != null){
			n = new LinkNode(head.val);
			n.next = newHead;
			newHead = n;
			head = head.next;
		}
		return newHead;
	}


	static boolean isPalindrome(LinkNode list){
		/*
			Approach: To determine if a linked listed
			is a palindrome, we can simply get reversed
			copy of the list, traverse both of them and
			determing if at each location, the values are
			the same.
			NOTE: While this doest change the time complexity,
			we can do this slightly faster if can determine
			how long the list is N. If we know this, we only
			need to match the first N/2 elements of both lists
			to know if the list is a palindrome.
		 */
		if (list == null) return true;
		LinkNode rev = reverseCopy(list);
		while (list != null){
			if (list.val != rev.val) return false;
			list = list.next;
			rev = rev.next;
		}
		return true;
	}


	static boolean intersects(LinkNode l1, LinkNode l2){
		/*
			 We can do this in linear time by figuring out
			 what the last node of each list is. If they are the
			 same, they must have merged together at some point.
			 Rather than trying and finding the exact node that they
			 merge at, we can save time and space by just going to end,
			 because it will always tell us whether or not they merged.
			 Since its a singly linked list, if they merged at one point,
			 then they went to the same destination (could not have split
			 aport).
			 SC: O(1);
			 TC: O(1);
		 */
		if (l1 == null || l2 == null) return false;
		while (l1.next != null) l1 = l1.next;
		while (l2.next != null) l2 = l2.next;
		return l1 == l2;
	}

	// Follow Up: What if we want the find the node where the 2 lists merge?

	static int length(LinkNode l){
		// return the length of a linked list
		int len = 0;
		while (l != null){
			l = l.next;
			++len;
		}
		return len;
	}

	static LinkNode getIntersection(LinkNode l1, LinkNode l2){
		int l1len = length(l1);
		int l2len = length(l2);
		while (l1len != l2len){
			if (l1len > l2len){
				l1len--;
				l1 = l1.next;
			} else {
				l2len--;
				l2 = l2.next;
			}
		}
		while (l1 != l2){ // traverse both lists, if they merge, they will point to the same
							// node at the same time.
			if (l1 == null) return new LinkNode(-1); // No intersection exists, you can decide what happens here.
			// ^ We know they must be the same length, so we can just
			// 		check if one of them ever reach null.
			l1 = l1.next;
			l2 = l2.next;
		}
		return l1; // or l2, arbitrary; they both point to the same node
	}

	static LinkNode cycleStart(LinkNode head){
		/*
			Idea: This definitley is something that would come
			easily, but the actual solution in terms of the code
			needed is extremely simple. It's just a matter of
			finding the pattern and understanding the 'runner'
			method with linked lists.
			Using the 'runner' method, we will make to pointers
			to the head of list and call them 'slow' and 'fast'.
			The slow node will will increment 1 step at a time
			while the fast node will increment 2 steps at a time.
			If at any point the fast pointer finds a null, there
			cannot be a cycle and we return null. If it keeps
			going however, it must eventually meet up with the
			slow pointer after it has done a full lap around the
			cycle. The position at which it meets up with the slow
			pointer corresponds to the number of nodes each pointer
			had to traverse before reaching the beggining of the
			cycle. In fact there is some number X such that incrementing
			the head by X and the conversion point by X, they will
			eventually meet at the start of the cycle.
			So to get that start node, we just increment both the head
			and the node where the runner met the slow pointer, and
			check for equality (reference equality) along the way.
			Once they are equal (which is guaranteed), both are
			pointing to the start of the cycle.
			TC: O(N), takes at most 2N operations for the runner to
				catch the slow pointer, and then at most N-1 operations
				to get the head to the start of the cycle.
			SC: O(1)
		 */
		LinkNode slow = head, fast = head;
		do {
			if (fast == null || fast.next == null) return null; // there is no cycle
			slow = slow.next;
			fast = fast.next.next;
		} while (slow != fast);

		while (slow != head){
			head = head.next;
			slow = slow.next;
		}
		return head; // the start of the cycle
	}


	public static void main(String[] args){
		log("\n-- Question 1 --");
		LinkNode n = LinkNode.buildList("1,2,2,3,4,3,5,6,7,5");
		n = removeDuplicates(n);
		n.print();
		n = LinkNode.buildList("1,1");
		n = removeDuplicates(n);
		n.print();
		n = LinkNode.buildList("1,2,2,3,4,3,5,6,7,5");
		n = removeDuplicates2(n);
		n.print();

		log("\n-- Question 2 --");
		int k;
		n = LinkNode.buildList("1,2,3,4"); k = 2;
		n.print();
		System.out.printf("%d from end is: %d\n", k, KthToLast(n, k));
		n = LinkNode.buildList("1,2,3,4,5,6,7"); k = 3;
		n.print();
		System.out.printf("%d from end is: %d\n", k, KthToLast(n, k));
		n = LinkNode.buildList("1,2,3"); k = 4;
		n.print();
		System.out.printf("%d from end is: %d\n", k, KthToLast(n, k));

		log("\n-- Question 3 --");
		n = LinkNode.buildList("1,2,3");
		deleteMiddle(n.next);
		n.print();
		n = LinkNode.buildList("1,2,3,4,5,6,7,8,9");
		deleteMiddle(n.next.next.next.next);
		n.print();

		log("\n-- Question 4 --");
		n = LinkNode.buildList("3,5,8,5,10,2,1");
		n = partition(n, 5);
		n.print();
		n = LinkNode.buildList("2,1");
		n = partition(n, 2);
		n.print();
		n = LinkNode.buildList("2,3,2");
		n = partition(n, 2);
		n.print();

		log("\n-- Question 5 --");
		LinkNode a = LinkNode.buildList("0,2");
		LinkNode b = LinkNode.buildList("0,3");
		LinkNode ans = addNumbers(a, b);
		ans.print(); // [0,5]
		a = LinkNode.buildList("9,9,9");
		b = LinkNode.buildList("2,1");
		ans = addNumbers(a, b);
		ans.print(); // [1,1,0,1]
		a = LinkNode.buildList("5");
		b = LinkNode.buildList("9,1");
		ans = addNumbers(a, b);
		ans.print(); // [4,2]

		// Follow up
		a = LinkNode.buildList("1,2,3");
		b = LinkNode.buildList("7");
		ans = addNumbers2(a, b);
		ans.print(); // [1,3,0]
		a = LinkNode.buildList("-1,-2");
		b = LinkNode.buildList("2,4");
		ans = addNumbers2(a, b);
		ans.print(); // [1,3,0]
		a = LinkNode.buildList("9,0");
		b = LinkNode.buildList("1,0");
		ans = addNumbers2(a, b);
		ans.print(); // [1,0,0]

		log("\n-- Question 6 --");
		log(isPalindrome(LinkNode.buildList("1,2,3,2,1")));
		log(isPalindrome(LinkNode.buildList("1,2,2,1")));
		log(isPalindrome(LinkNode.buildList("1,2,2,3")));
		log(isPalindrome(LinkNode.buildList("1")));
		log(isPalindrome(LinkNode.buildList("1,3,1")));

		log("\n-- Question 7 --");
		a = LinkNode.buildList("1,2,3");
		b = LinkNode.buildList("-2,-1,0");
		b.next.next.next = a;
		log(intersects(a,b));
		log(getIntersection(a,b).val);

		log("\n-- Question 8 --");
		n = LinkNode.buildList("0,1,2,3,4,5");
		n.next.next.next.next.next.next = n.next.next; // route 5 back to 2
		log(cycleStart(n).val);
		n = LinkNode.buildList("1,2");
		n.next.next = n; // route 2 back to 1
		log(cycleStart(n).val);
		n = LinkNode.buildList("1,2,3,4,5,6,7");
		n.next.next.next.next.next.next.next = n.next.next.next.next; // route 7 back to 5
		log(cycleStart(n).val);
	}

}


