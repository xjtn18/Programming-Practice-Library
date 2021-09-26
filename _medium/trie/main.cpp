//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/25/12
//  File type: C++ source file
//  Description: Implementation of a prefix tree.
//////////////////////////////////////////////////////


//NOTE: Should be optimized with a RedBlack tree
//			std::set could not be used because the tree DS
//			is abstracted and doesn't help up when implementint
//			startsWith.
//
//	Time
//		O(n) where n is the number of words in the tree.
//
//	Space
//		O(log n) for average case, linear time for worst if tree
//		is skewed; this should be done using a RedBlack so we
//		have self-balancing.


#include <mystd.h>
using namespace std;


#define say cout <<
#define stop << endl;



class Node {
public:
	string val;
	Node *right = nullptr, *left = nullptr;

	Node(string _val) : val(_val)
	{}
};




class Trie {
	Node *root;

public:
	Trie () : root(nullptr)
	{ }


	void insert(string s){
		if (root){
			Node *curr = root;
			while (true){
				if (s < curr->val){
					if (curr->left){
						curr = curr->left;
					} else {
						curr->left = new Node(s);
						return;
					}
				} else if (s > curr->val){
					if (curr->right){
						curr = curr->right;
					} else {
						curr->right = new Node(s);
						return;
					}
				} else { // duplicate
					return;
				}
			}

		} else {
			root = new Node(s);
		}
	}



	bool search(string s){
		if (!root) return false;
		Node *curr = root;

		while (curr){
			if (s < curr->val){
				curr = curr->left;
			} else if (s > curr->val){
				curr = curr->right;
			} else {
				return true;
			}
		}
		return false;
	}

	
	bool startsWith(string prefix){
		if (!root) return false;
		Node *curr = root;

		while (curr){
			bool exit_flag = false;
			size_t i;

			for (i = 0; i < prefix.size() && i < curr->val.size(); ++i){
				if (prefix[i] < curr->val[i]){
					curr = curr->left;
					exit_flag = true;
					break;
				} else if (prefix[i] > curr->val[i]){
					curr = curr->right;
					exit_flag = true;
					break;
				}
			}

			if (!exit_flag){
				if (i != prefix.size()){
					curr = curr->right;
				} else {
					return true;
				}
			}

		}

		return false;
	}

};




int main(){
	Trie t;
	t.insert("apple");
	t.search("app");
	t.startsWith("app");
	

	return 0;
}



