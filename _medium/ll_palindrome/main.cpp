//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given a linked list, return true or false whether or not it its values form a palindrome
//  					in O(n) time and O(1) space.
//////////////////////////////////////////////////////



// Idea:
// To compute the midway point of linked list, you dont need to know the length of the list.
// A smart way of getting a pointer to the halfway point is increment 2 pointers down the list, one that increments by one node
// and another that increments by 2 nodes. When the faster one reaches the nullptr, the slower one points to the middle.
//
// TC
// Finding the midway, reversing it, and then comparing it with the first half comes out to 3 seperate O(n/2) operations, which
// makes the total time complexity O(3/2 * n), which is just linear.
//
// SC
// O(1)
//





#include <mystd.h>


void reverse(ListNode<int> *&head){
	ListNode<int> *prev = nullptr, *nextup = nullptr;
	while (head){
		nextup = std::exchange(head->next, prev); // route the next pointer back, and set 'nextup' to the old next
		prev = std::exchange(head, nextup); // set head to the nextup node, and set prev to the old head.
	}
	head = prev;
}


ListNode<int> * split(ListNode<int> *&head){
	// if the list is even length, then 'fast' will reach null before it has a chance to make its second increment; else odd.
	ListNode<int> *slow = head, *fast = head->next;
	while (fast){
		slow = slow->next;
		fast = fast->next;
		if (fast){
			fast = fast->next;
		} else { // even length list
			return slow;
		}
	}
	return slow->next; // odd length list
}



bool isListPalindrome(ListNode<int> *l){
	if (!l) return true;

	ListNode<int> *mid = split(l);
	reverse(mid);


	// compare first half and the reversed second half.
	while (mid){
		if (l->val != mid->val){
			return false;
		}
		mid = mid->next;
		l = l->next;
	}

	return true;
}



int main(){
	assert( isListPalindrome(createLL({0,1,1,0})) == true );
	assert( isListPalindrome(createLL({0,1,2})) == false );
	assert( isListPalindrome(createLL({0,1,0})) == true );
	assert( isListPalindrome(createLL({0,1})) == false );
	assert( isListPalindrome(createLL({0})) == true );
	assert( isListPalindrome(createLL({0,0})) == true );
	assert( isListPalindrome(createLL({0,1,3,1,0})) == true );
	assert( isListPalindrome(createLL({0,1,3,1,0,0})) == false );
	assert( isListPalindrome(nullptr) == true );

	return 0;
}



