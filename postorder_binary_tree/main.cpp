/*
 * Author: Jacob Nardone
 * Date created: 9/15/2020
 * File type: C++ source file
 * Description: Classic 'divide and conquer' problem to test if two binary trees have the same structure and values.
*/


#include <iostream>
#include <vector>
#include "../debug.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void explorePostOrder(TreeNode* curr, vector<int>& ordering){
	// takes a vector by reference to change the ordering each recursive call
	// postorder = left, right, parent
	if (curr){
		explorePostOrder(curr->left, ordering);
		explorePostOrder(curr->right, ordering);
		ordering.push_back(curr->val);
	}
}

vector<int> postorderTraversal(TreeNode* root) {
	// calls helper function so that we can create the vector here in the initial function call
	vector<int> ordering;
	explorePostOrder(root, ordering);
	return ordering;
}


void run_testcases(){
	log(postorderTraversal(new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr))));
	log(postorderTraversal(nullptr));
	log(postorderTraversal(new TreeNode()));
	log(postorderTraversal(new TreeNode(1, nullptr, new TreeNode(3, new TreeNode(2), nullptr))));
	log(postorderTraversal(new TreeNode(1, new TreeNode(4), new TreeNode(3, new TreeNode(1), nullptr))));
}

int main(){
	run_testcases();
	return 0;
}



