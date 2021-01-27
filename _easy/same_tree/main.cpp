/*
 * Author: Jacob Nardone
 * Date created: 9/15/2020
 * File type: C++ source file
 * Description: Classic 'divide and conquer' problem to test if two binary trees have the same structure and values.
*/


#include <iostream>


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 


bool isSameTree(TreeNode* cp, TreeNode* cq) {
	if (!cp && !cq){ // if both are nullptr
		return true;
	} else if (!cp || !cq){ // if only one is nullptr, AKA structures are not the same
		return false;
	} else if (cp->val != cq->val){ // values are not equal
		return false;
	}
	return isSameTree(cp->left, cq->left) && isSameTree(cp->right, cq->right); // evalutate likeness of both child substrees
}



void run_testcases(){
	std::cout << isSameTree(nullptr, nullptr) << std::endl; // empty trees
	std::cout << isSameTree(nullptr, new TreeNode()) << std::endl; // empty trees
	TreeNode *h1, *h2; 
	h1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	h2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	std::cout << isSameTree(h1, h2) << std::endl;
	h1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	h2 = new TreeNode(1, new TreeNode(2), nullptr);
	std::cout << isSameTree(h1, h2) << std::endl;
	h1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	h2 = new TreeNode(1, new TreeNode(1), new TreeNode(3));
	std::cout << isSameTree(h1, h2) << std::endl;
}

int main(){
	run_testcases();
	return 0;
}



