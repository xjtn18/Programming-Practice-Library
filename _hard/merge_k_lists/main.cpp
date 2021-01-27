//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/31/2020
//  File type: C++ source file
//  Description: Merge any number of sorted (ascending) lists into on large sorted linked list.
//  			WARNING: the problem is given with 'lists' being passed by reference.
//  					To keep better space complexity, this function clears all passed lists.
//  					You could simply just pass 'lists' by value to avoid this side effect.
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"


using namespace std;


#include <climits>

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int k = lists.size(), used = 0, lowVal, lowIdx; // track smallest value
	ListNode dummy;
	ListNode* head = &dummy, *curr = head;

	while (used != k){
		lowVal = INT_MAX;

		for (int i = 0; i < k; ++i){ // find lowest node
			if (lists[i] != nullptr && lists[i]->val < lowVal){
				lowVal = lists[i]->val;
				lowIdx = i;
			}
		}
		
		if (lowVal == INT_MAX){ break;} // if all linked lists were empty to begin with

		curr->next = lists[lowIdx];
		curr = curr->next;

		if (lists[lowIdx]->next == nullptr){ // if this is the end of this linked list
			++used;
		}
		lists[lowIdx] = lists[lowIdx]->next;
	}
	
	return head->next;
}


int main(){
	ListNode* l1;
	ListNode* l2;
	ListNode* l3;
	ListNode* res;
	vector<ListNode*> test;

	// tc 1
	l1 = createLL(vector<int>{1,4,5});
	l2 = createLL(vector<int>{1,3,4});
	l3 = createLL(vector<int>{2,6});
	test = {l1,l2,l3};
	res = mergeKLists(test);
	log(res);

	// tc 2
	l1 = createLL(vector<int>{4,8,11});
	l2 = createLL(vector<int>{1,8});
	l3 = createLL(vector<int>{0,6,14});
	test = {l1,l2,l3};
	res = mergeKLists(test);
	log(res);

	// tc 3
	l1 = createLL(vector<int>{});
	l2 = createLL(vector<int>{});
	test = {l1,l2};
	res = mergeKLists(test);
	log(res);

	// tc 4
	test = {};
	res = mergeKLists(test);
	log(res);
	
	// tc 5
	l1 = createLL(vector<int>{1,1,2});
	l2 = createLL(vector<int>{});
	l3 = createLL(vector<int>{1,1,1});
	test = {l1,l2,l3};
	res = mergeKLists(test);
	log(res);
	return 0;
}



