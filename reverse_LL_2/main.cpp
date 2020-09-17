/*
 * Author: Jacob Nardone
 * Date created:
 * File type: C++ source file
 * Description:
*/

/*
 * Logic:
 * Iterate through the linked list
 * When the index is equal to M, save the current node as 'reverse_tail'
 * Then, reverse the following nodes
 * Once the index is greater than N, set reverse tail to point to current node
 * return head
*/

#include <iostream>
#include "../debug.h"


ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* curr = head;
	ListNode* prev = nullptr, *next = nullptr;
	ListNode* pre_reverse = nullptr, *reverse_tail = nullptr;
	int index = 1;
	while (curr){
		next = curr->next; // save next node before we change the pointer to it
		if (index == m-1){
			pre_reverse = curr;
		} else if (index == m){
			reverse_tail = curr;
		} else if (index == n){
			if (pre_reverse){ // if a node was detected before we began reversing
				pre_reverse->next = curr;
			} else {
				head = curr; // reversed starts at the beggining of the list, so change head to that
			}
			reverse_tail->next = curr->next;
		}

		if (index >= m && index <= n && m != n){
			curr->next = prev; // point current node back
		}
		prev = curr; // update previous node to current node
		curr = next; // go to the next node
		index += 1;
	}
	return head;
}


int main(){
	log(reverseBetween(createLL(std::vector<int>{1,2,3,4,5}), 1, 5));
	log(reverseBetween(createLL(std::vector<int>{1,2,3,4,5}), 5, 5));
	log(reverseBetween(createLL(std::vector<int>{1,2,3,4,5}), 1, 1));
	log(reverseBetween(createLL(std::vector<int>{1,2,3,4,5}), 2, 4));
	log(reverseBetween(createLL(std::vector<int>{1,2,3,4,5}), 3, 5));
	log(reverseBetween(createLL(std::vector<int>{1,2}), 2, 2));
	log(reverseBetween(nullptr, 1, 1));
	return 0;
}


