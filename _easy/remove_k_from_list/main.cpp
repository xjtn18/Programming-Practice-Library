//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/18/21
//  File type: C++ source file
//  Description: remove all nodes with given value in linked list.
//////////////////////////////////////////////////////


#include <mystd.h>


ListNode<int>* removeKFromList(ListNode<int> *l, int k) {
	if (!l) return nullptr;
	ListNode<int> *dummy = new ListNode<int>(0, l);
	l = dummy;
	ListNode<int> *temp = nullptr;;

	while (l->next){
		if (l->next->val == k){
			temp = l->next;
			l->next = l->next->next;
			delete temp;

		} else {
			l = l->next;
		}

	}

	return dummy->next;

}



int main(){
	ListNode<int> *input, *ans;

	input = createLL( {1,2,3,4,3,6} );
	ans = createLL( {1,2,4,6} );
	assert( equal(removeKFromList(input, 3), ans) );
	
	input = nullptr;
	ans = nullptr;
	assert( equal(removeKFromList(input, 1), ans) );

	input = createLL( {2} );
	ans = createLL( {2} );
	assert( equal(removeKFromList(input, 4), ans) );

	input = createLL( {2,1} );
	ans = createLL( {1} );
	assert( equal(removeKFromList(input, 2), ans) );

	input = createLL( {2} );
	ans = nullptr;
	assert( equal(removeKFromList(input, 2), ans) );


	return 0;
}



