//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given 2 large numbers (represented as linked lists of 4 digit parts, sans leading zeros) that cannot be stored into any primitive data type, return the sum of those 2 numbers.
//////////////////////////////////////////////////////


// Idea:
// Just do simple addition proccess between the corresponding parts of the numbers and cary any 1's.
// To start, reverse the operand lists since we add from the end to the front of the numbers, and then just loop throught the addition process until we reach the end of both numbers.
//
// TC
//	O(N), N = |A| + |B|
//
// SC
// O(N) for the new list we are returning. N being the number of parts in A plus the parts in B;




#include <mystd.h>


void reverse(ListNode<int> *&head){
	ListNode<int> *prev = nullptr, *next = nullptr;
	while (head){
		next = std::exchange(head->next, prev);
		prev = head;
		head = next;
	}
	head = prev;
}




ListNode<int> * addTwoHugeNumbers(ListNode<int> *a, ListNode<int> *b) {
	// reverse the operands
	reverse(a);
	reverse(b);

	// add the parts, carry any ones
	ListNode<int> *front = nullptr;
	ListNode<int> *curr = nullptr;
	int sum = 0;
	bool carry = false;

	while (a || b){
		front = new ListNode<int>;
		front->next = std::exchange(curr, front);

		if (a && b){
			sum = a->val + b->val + (int)carry;
			a = a->next;
			b = b->next;

		} else if (a){
			sum = a->val + (int)carry;
			a = a->next;

		} else if (b){
			sum = b->val + (int)carry;
			b = b->next;
		}

		carry = (sum % 10000 != sum);
		sum %= 10000;
		curr->val = sum;
	}

	if (carry){
		front = new ListNode<int>;
		front->val = 1;
		front->next = curr;
	}

	return front;
}



int main(){
	auto ans = addTwoHugeNumbers(createLL({1}), createLL({9999, 9999, 9999, 9999, 9999}));
	dlog(ans);
	ans = addTwoHugeNumbers(createLL({9999,9999}), createLL({20}));
	dlog(ans);
	return 0;
}



