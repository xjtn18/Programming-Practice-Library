//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 6/17/2020
//  File type: C++ header file
//  Description: Helper functions I made to debug/print objects, strings, etc. 
//  			and to create/initialize common data structures.
//////////////////////////////////////////////////////

#pragma once
#include <bits/stdc++.h>
#include <Timer.h>


#define kDEBUG 1 // set this to 0 if you dont want to see any of your dlogs
#define p1(x) std::cout << x << std::endl;

#define std_extend(x,y) (x.insert(x.end(), y.begin(), y.end()))
#define is_in(x,y)   y.find(x) != y.end()
#define not_in(x,y)  y.find(x) == y.end()


inline void breakpoint(){
	static int id = 1;
	std::cout << "--> Breakpoint " << id << std::endl;
	id++;
}

#define BP breakpoint();


void say_all(){ std::cout << "\n"; }

template<typename Head, typename... Tail>
void say_all(Head H, Tail... T){
	std::cout << " " << H;
	say_all(T...);
}
#define say(...) std::cout << "(" << #__VA_ARGS__ << ") =\t", say_all(__VA_ARGS__)



////////////////////////////////////////
// Logging functions
////////////////////////////////////////

template <typename T>
void buffer(T input){
	std::cout << input << std::endl;
	std::string _;
	std::getline(std::cin, _);
}


// this template prints anything (singular value)
template <typename T>
bool dlog(T x, bool nl = true, unsigned int sleeptime = 0){
	if (!kDEBUG)
		return false;
	std::cout << x;
	if (nl)
		std::cout << "\n";
	return true;
	//usleep(sleeptime * 100000);
}


// this template prints pairs
template <typename T1, typename T2>
void dlog(std::pair<T1,T2> p, bool nl = true){
	std::cout << "(" << p.first << ", " << p.second << ")";
	if (nl) std::cout << "\n";
}



// this template prints arrays
template <typename T>
void alog(T *arr, int len){
	dlog("[", false);
	for (int y = 0; y < len; y++){
		dlog(arr[y], false);
		if (y != len-1){
			dlog(", ", false);
		}
	}
	dlog("]\n", false);

}


template <typename Iter, typename Container>
bool is_last(Iter iter, const Container& cont){
	return (iter != cont.end()) && (next(iter) == cont.end());
}

// this template prints any standard container
template <typename Container>
void c_log(Container l, bool nl = true){
	std::cout << '[';
	for (auto iter = l.begin(); iter != l.end(); ++iter){
		dlog (*iter, false);
		if (!is_last(iter,l))
			std::cout << ", ";
	}
	std::cout << ']';
	if (nl) std::cout << "\n";
}

// this template prints any queue
template <typename T>
void qlog(std::queue<T> q, bool nl = true){
	std::cout << '[';
	while(!q.empty()){
		T val = q.front();
		dlog (val, false);
		if (q.size() > 1)
			std::cout << ", ";
		q.pop();
	}
	std::cout << ']';
	if (nl) std::cout << "\n";
}



template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> sorted_by_value(const std::map<T1, T2> m){
	// 
	// This function takes a map and returns a vector representation of that map sorted by value.
	//
	auto comp = [](const std::pair<T2,T2>& p1, const std::pair<T1,T2> p2){
		return p1.second < p2.second;
	};
	std::vector<std::pair<T1, T2>> m_vec(m.begin(), m.end());
	std::sort(m_vec.begin(), m_vec.end(), comp);
	return m_vec;
}


// this template prints 2d containers
template <typename Container>
void hlog(Container mat, bool nl = true){
	for (auto& subcontainer : mat){
		std::cout << '[';
		for (auto& value : subcontainer){
			//std::cout << std::setw(4) << value;
			if (value == INT_MAX)
				dlog("#", false);
			else
				dlog(value, false);
			dlog("  ", false);
			//std::cout << std::setw(6) << std::endl;
		}
		std::cout << "]\n";
	}
	if (nl) std::cout << "\n";
}



// this template prints standard 1d maps
template <typename Container>
void mlog(Container dict, bool nl = true){
	for (auto& pairing : dict){
		std::cout << '[';
		std::cout << pairing.first << ":  ";
		//std::cout << std::setw(4) << value;
		dlog(pairing.second, false);
		//std::cout << std::setw(6) << std::endl;
		std::cout << "]\n";
	}
	if (nl) std::cout << "\n";
}


// this template prints 2d maps (maps where value is a container)
template <typename Container>
void m2log(Container dict, bool nl = true){
	for (auto& pairing : dict){
		std::cout << '[';
		std::cout << pairing.first << ":  ";
		for (auto it = pairing.second.begin(); it != pairing.second.end(); ++it){
			//std::cout << std::setw(4) << value;
			dlog(*it, false);
			if ( !is_last(it, pairing.second) ) dlog(", ", false);
			//std::cout << std::setw(6) << std::endl;
		}
		std::cout << "]\n";
	}
	if (nl) std::cout << "\n";
}



////////////////////////////////////////
// Linked Lists
////////////////////////////////////////


// standard (LeetCode) linked list node structure
template <typename T>
struct ListNode {
	T val;
	ListNode<T>* next;
	ListNode() : val(T()), next(nullptr) {}
	ListNode(T x) : val(x), next(nullptr) {}
	ListNode(T x, ListNode<T> *next) : val(x), next(next) {}

	friend bool equal(const ListNode<T> *l1, const ListNode<T> *l2){
		const ListNode<T> *l1_curr = l1, *l2_curr = l2;
		while (l1_curr && l2_curr){
			if (l1_curr->val != l2_curr->val){
				return false;
			}
			l1_curr = l1_curr->next;
			l2_curr = l2_curr->next;
		}
		return l1_curr == l2_curr; // if one list ended before the other, this returns false, else true;
	}
};


// template to intitialize and fill a linked list from a given vector
template <typename T>
ListNode<T>* createLL(std::initializer_list<T> v){
	ListNode<T>* head = new ListNode<T>(*(v.begin()));
	ListNode<T>* curr = head;
	for (auto it = v.begin()+1; it != v.end(); ++it){
		curr->next = new ListNode<T>(*it);
		curr = curr->next;
	}
	return head;
}


// Print a Linked List
template <typename T>
void dlog(ListNode<T>* head){
	if (!head){
		std::cout << "Empty" << std::endl;
		return;
	}
	ListNode<T>* curr = head;
	while (curr->next){
		std::cout << curr->val << " - ";
		curr = curr->next;
	}
	std::cout << curr->val << "\n";
}



////////////////////////////////////////
// Binary Trees
////////////////////////////////////////


// standard (LeetCode) binary tree node structure
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode *left, TreeNode *right);
	friend std::ostream& operator <<(std::ostream& os, const TreeNode* node){
		os << node->val;
		return os;
	}
};


// recursive function that fills binary tree row by row left to right
void fill(TreeNode*& node, std::vector<std::string> v, int i);

// initialize and fill a binary tree (row by row) from a given vector
TreeNode* createBinaryTree(std::string vstr);

// Print a tree
void dlog(TreeNode* root);



// ///////////////////////////////////
// 2D Arrays
// ///////////////////////////////////

template <typename T>
using vec2D = std::vector<std::vector<T>>;  // typedef


//get2D("1 2 3|4 5 6|7 8 9")    <-- what we want

/*
template <typename T>
vec2D<char> get2D(std::string vstr){
	int row = 0, col = 0;
	vec2D<char> mat = {{}};

	for (int i = 0; i < vstr.size(); ++i){
		char c = s[i];
		if (c == ' '){
			col++;
		} else if (c == '|'){
			row++;
		} else {
			mat[row][col] = c;
		}
	}
	return mat;
}
*/






