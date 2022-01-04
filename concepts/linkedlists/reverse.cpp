#include <mystd.h>

// uses 2 pointers only to reverse a linked list in place


void reverse_2ptr(ListNode<int> *&head){
	ListNode<int> *prev = nullptr;

	while (head != nullptr){
		prev = exchange(head, exchange(head->next, prev));
	}
	head = prev;
}



int main(void){
	ListNode<int> *ll = createLL({1,2,3,4,5,6});
	reverse_2ptr(ll);
	dlog(ll);

	return 0;
}

