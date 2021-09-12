//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/29/21
//  File type: C++ source file
//  Description: Given a linked list, return that list with pairs of 2 swapped
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


ListNode<int> * reverse(ListNode<int> *head){
	//
	// One variable / one liner linked list reversal!
	// (Not really, exchange creates temp variables, but still nifty).
	//
	ListNode<int> *prev = nullptr;
	while (head){
		prev = std::exchange(head, std::exchange(head->next, prev));
	}
	return prev;
}


ListNode * reverse(ListNode *head){
	ListNode *prev = nullptr;
	while (head){
		prev = std::exchange(head, std::exchange(head->next, prev));
	}
	return prev;
}


ListNode<int> * reverse2(ListNode<int> *head){
	if (!head) return nullptr;
	ListNode<int> *prev = nullptr, *tail = head;
	int count = 0;

	while (head && count < 2){
		prev = std::exchange(head, std::exchange(head->next, prev));
		count++;
	}

	tail->next = head;
	return prev;
}


ListNode<int>* swapPairs(ListNode<int>* head){
	ListNode<int> *dummy = new ListNode<int>;
	dummy->next = std::exchange(head, dummy);

	while (head){
		head = std::exchange(head->next, reverse2(head->next));
	}

	return dummy->next;
}



ListNode<int> * faster(ListNode<int> *head){
	//
	// Takes a linked list of integers and return the
	// list with every pair swapped.
	//
	auto dummy = new ListNode<int>(0, head);
	head = dummy;

	while ( head->next && head->next->next ){
		head = std::exchange(head->next, 
				std::exchange(head->next->next,
					std::exchange(head->next->next->next, head->next)));
	}

	return dummy->next;
}





int main(){
	ListNode<int> *head;



	head = createLL({1,2,3,4,5,6});
	dlog( faster(head) );

	head = createLL({1,2,3,4,5,6});
	dlog( reverse(head) );


	return 0;
}



