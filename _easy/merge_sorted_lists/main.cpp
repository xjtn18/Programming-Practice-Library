//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
#include <unistd.h>


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	//null check
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode *head;
	if (l1->val > l2->val){
		head = l2;
		l2 = l2->next;
	} else {
		head = l1;
		l1 = l1->next;
	}
	ListNode *curr = head;

	while (l1 && l2){
		if (l1->val > l2->val){
			curr->next = l2;
			curr = curr->next;
			l2 = l2->next;
		} else {
			curr->next = l1;
			curr = curr->next;
			l1 = l1->next;
		}

	}

	if (!l1){ // if we've exhausted l1
		curr->next = l2;
	} else if (!l2){ // if we've exhausted l2
		curr->next = l1;
	}

	return head;
}



int main(){
	dlog(mergeTwoLists(createLL({1,3,3,5}), createLL({2,4,5,6})));
	ListNode *head = createLL({1,3,5});
	ListNode *curr = new ListNode(*head);
	return 0;
}



