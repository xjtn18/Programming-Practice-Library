//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
	ListNode<int> *dummy = new ListNode<int>();
	ListNode<int> *curr = dummy;
	bool carry = false;
	int summ;

	while (l1 || l2){
		if (l1 && l2){
			summ = l1->val + l2->val + carry;
			carry = (summ >= 10);
			curr->next = new ListNode<int>(summ % 10);
			curr = curr->next;
			l1 = l1->next;
			l2 = l2->next;

		} else if (l1){
			summ = l1->val + carry;
			carry = (summ >= 10);
			curr->next = new ListNode<int>(summ % 10);
			curr = curr->next;
			l1 = l1->next;

		} else { // l2 has not been fully searched
			summ = l2->val + carry;
			carry = (summ >= 10);
			curr->next = new ListNode<int>(summ % 10);
			curr = curr->next;
			l2 = l2->next;
		}
	}

	if (carry){
		curr->next = new ListNode<int>(1);
	}

	return dummy->next;
}



int main(){


	ListNode<int> *l1 = createLL({9,9,9,9,9,9,9});
	ListNode<int> *l2 = createLL({9,9,9,9});
	dlog(addTwoNumbers(l1, l2));

	return 0;
}



