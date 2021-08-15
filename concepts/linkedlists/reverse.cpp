#include <mystd.h>

// uses 2 pointers only to reverse a linked list in place


ListNode* reverse_2ptr(ListNode *head){
	ListNode *next, *prev = nullptr;

	while (head != nullptr){
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;

	}
	return prev;
}



int main(void){
	dlog(reverse_2ptr(createLL({1,2,3,4,5,6})));

	return 0;
}

