//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////



// Idea:
// reverse the list
// after n iterations, move the remainder of the list to the front of the list
// return the reverse of that and that is the answer



#include <mystd.h>
using namespace std;


void reverse(ListNode<int> *&head){
	ListNode<int> *prev, *next;
	prev = next = nullptr;
	
	while (head){
		next = std::exchange(head->next, prev);
		prev = std::exchange(head, next);
	}

	head = prev;
}


void back_to_front(ListNode<int> *&front, ListNode<int> *&tail){
	if (!tail || !tail->next) return;
	ListNode<int> *new_front = tail->next;
	tail = std::exchange(tail->next, nullptr);

	while (tail->next){
		tail = tail->next;
	}
	tail->next = front;
	front = new_front;
}


ListNode<int> * rearrangeLastN(ListNode<int> *l, int n){
	if (n == 0) return l;
	reverse(l);

	ListNode<int> *curr = l;
	int count = 0;
	while (curr && count < n-1){ // n-1 so we stop at the new tail
		curr = curr->next;
		count++;
	}

	back_to_front(l, curr);

	reverse(l);
	return l;
}



int main(){
	ListNode<int> *input;
	
	for (int i = 5; i >= 0; --i){
		input = createLL({1,2,3,4});
		dlog(rearrangeLastN(input, i));
	}

	dlog(rearrangeLastN(nullptr, 3));

	return 0;
}



