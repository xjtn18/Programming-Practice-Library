//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/21/21
//  File type: C++ source file
//  Description: Take a linked list and turn it into K groupings of reversed sublists.
//////////////////////////////////////////////////////


#include <mystd.h>



ListNode<int> * reverse_k(ListNode<int> *head, int k){
	if (k == 0) return head;
	ListNode<int> *prev = nullptr, *next = nullptr;
	ListNode<int> *tail = head;
	int count = 0;

	while (count < k && head){
		next = std::exchange(head->next, prev);
		prev = std::exchange(head, next);
		count++;
	}

	tail->next = next; // end of the reversed section points to the rest of the original list
	return prev; // head of reversed section
}


ListNode<int> * reverseNodesInKGroups(ListNode<int> *l, int k){
	ListNode<int> *dummy_head 	= new ListNode<int>;
	ListNode<int> *front, *curr, *next_front;
	front = curr = dummy_head;
	int count = 0;

	dummy_head->next = l; // dummy's 'next' points to our list
	
	while (curr){
		while (count < k && curr){
			curr = curr->next;
			count++;
		}
		if (curr) { // we know this section is long enough to reverse it
			next_front = std::exchange(front->next, reverse_k(front->next, k));
			front = next_front;
			curr 	= next_front;
			count = 0;
		}
	}

	return dummy_head->next;
}




int main(){
	ListNode<int> *input;

	input = createLL({1,2,3,4,5,6,7,8,9,10,11});
	dlog(reverseNodesInKGroups(input, 3));

	input = createLL({2,1,4,3,5});
	dlog(reverseNodesInKGroups(input, 2));

	input = createLL({1,2,3,4,5});
	dlog(reverseNodesInKGroups(input, 2));

	input = nullptr;
	dlog(reverseNodesInKGroups(input, 2));

	return 0;
}



