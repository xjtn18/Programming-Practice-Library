//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Merge two sorted linked lists in-place.
//////////////////////////////////////////////////////


// Idea:
// Keep track of which list is currently lessern and which is greater.
// The head of our result will be whichever list has the smaller head.
// Work down the lesser list until the next value is either null or bigger than the current position of the greater list.
// When that condition is met, we set the lessers node next to the first in greater, set lesser to the old next, and then swap lesser and greater. Rinse and repeat.
//
// TC
// O(|A| + |B|), linear
//
// SC
// O(1): in-place merging



#include <mystd.h>


ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2){
	// base case
	if (!l1) return l2;
	if (!l2) return l1;
	
	ListNode<int> *lessr = (l1->val <= l2->val) ? l1 : l2;
	ListNode<int> *greatr = (l1->val <= l2->val) ? l2 : l1;
	ListNode<int> *head = lessr; // pick the lesser to be the final head
	
	while (lessr && greatr){ // as soon as one list runs out, we're done
		while (lessr->next  &&  lessr->next->val <= greatr->val){
			lessr = lessr->next;
		}
		lessr = std::exchange(lessr->next, greatr);
		std::swap(lessr, greatr);
	}

	return head;
}



int main(){
	ListNode<int> *l1, *l2, *ans;

	l1 = createLL({1,2,5});
	l2 = createLL({3,4,6});
	ans = createLL({1,2,3,4,5,6});
	assert( equal(mergeTwoLinkedLists(l1, l2), ans) );


	l1 = createLL({1,1,2,2,5,7});
	l2 = createLL({2,3,3,5,6,9,10,11});
	dlog(mergeTwoLinkedLists(l1, l2));
	dlog(l1);
	dlog(l2);

	l1 = nullptr;
	l2 = nullptr;
	dlog(mergeTwoLinkedLists(l1, l2));

	l1 = createLL({3,3});
	l2 = createLL({3,3,3});
	dlog(mergeTwoLinkedLists(l1, l2));
	dlog(l1);
	dlog(l2);

	return 0;
}



