//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 4/16/22
//  File type: C++ source file
//  Description: Random 1 hour mock interview assessment from LeetCode.
//////////////////////////////////////////////////////


using namespace std;
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unistd.h>
#include <vector>
#include <map>



struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*


*/



int romanToInt(string s){

	int number = 0;

	std::map<char, int> m = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	for (int i = 0; i < s.length(); ++i){
		if (s[i] == 'I' && i+1 < s.length()){
			i++;
			if (s[i] == 'V') number += 4;
			else if (s[i] == 'X') number += 9;
			else {
				number += 1;
				i--;
			}
		} else if (s[i] == 'X' && i+1 < s.length()){
			i++;
			if (s[i] == 'L') number += 40;
			else if (s[i] == 'C') number += 90;
			else {
				number += 10;
				i--;
			}
		} else if (s[i] == 'C' && i+1 < s.length()){
			i++;
			if (s[i] == 'D') number += 400;
			else if (s[i] == 'M') number += 900;
			else {
				number += 100;
				i--;
			}
		} else {
			number += m[s[i]];
		}
	}

	return number;

}


ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
	ListNode *dummy = new ListNode();
	ListNode *ans = dummy;
	int carry = 0;

	while (l1 || l2){
		int l1d = (l1) ? l1->val : 0;
		int l2d = (l2) ? l2->val : 0;
		int sigma = l1d + l2d + carry;

		ans->next = new ListNode(sigma % 10);
		ans = ans->next;
		carry = sigma / 10;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}

	if (carry){
		ans->next = new ListNode(1);
	}

	return dummy->next;
}






int main(){

	cout << romanToInt("III") << endl;
	cout << romanToInt("IX") << endl;


	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *head = addTwoNumbers(l1, l2);


	while (head){
		cout << head->val << endl;
		head = head->next;
	}



	return 0;
}



