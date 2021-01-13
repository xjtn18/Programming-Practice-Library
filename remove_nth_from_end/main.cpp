//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/13/21
//  File type: C++ source file
//  Description: Remove the Nth node from the end of a linked list.
//  	Complexity: O(N)
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode *head, int n){
	int count = 0;
	ListNode *dummyHead = new ListNode(0, head);
	ListNode *curr = dummyHead, *removedPred = dummyHead;

	while (curr != nullptr){
		if (count > n){
			removedPred = removedPred->next;
		}
		count++;
		curr = curr->next;
	}

	// disconnect and delete removed node
	ListNode *newNext = removedPred->next->next;
	delete removedPred->next;
	removedPred->next = newNext;

	return dummyHead->next; // DO NOT return head, it might have been the removed node
}




int main(){
	log(removeNthFromEnd(createLL(vector<int>{1,2,3,4,5}), 5));
	log(removeNthFromEnd(createLL(vector<int>{1,2,3,4,5}), 4));
	log(removeNthFromEnd(createLL(vector<int>{1,2,3,4,5}), 3));
	log(removeNthFromEnd(createLL(vector<int>{1,2,3,4,5}), 2));
	log(removeNthFromEnd(createLL(vector<int>{1,2,3,4,5}), 1));
	log(removeNthFromEnd(createLL(vector<int>{1}), 1));
	log(removeNthFromEnd(createLL(vector<int>{0,2}), 1));
	log(removeNthFromEnd(createLL(vector<int>{1,3}), 2));

	return 0;
}



