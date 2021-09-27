//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



void reverse(ListNode<int> *&root){
	ListNode<int> *prev = nullptr;
	while (root){
		prev = exchange(root, exchange(root->next, prev));
	}
	root = prev;
}



ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
	reverse(l1);
	reverse(l2);

	ListNode<int> *front = nullptr, *curr = nullptr;
	bool carry = false;
	int digit_sum = 0;

	while (l1 || l2){
		front = new ListNode<int>();
		front->next = exchange(curr, front);

		if (l1 && l2){
			digit_sum = l1->val + l2->val + int(carry);
			l1 = l1->next;
			l2 = l2->next;

		} else if (l1){
			digit_sum = l1->val + int(carry);
			l1 = l1->next;

		} else { // l2 is still being parsed
			digit_sum = l2->val + int(carry);
			l2 = l2->next;
		}

		carry = digit_sum % 10 != digit_sum;
		digit_sum %= 10;
		curr->val = digit_sum;
	}

	if (carry){
		front = new ListNode<int>(1);
		front->next = curr;
	}
	
	return front;
}




int main(){
	ListNode<int> *a, *b;
	
	a = createLL({1,2,5});
	b = createLL({5});
	dlog(addTwoNumbers(a, b));

	a = createLL({9});
	b = createLL({2});
	dlog(addTwoNumbers(a, b));


	return 0;
}



