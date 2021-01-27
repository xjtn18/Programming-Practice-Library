//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/26/2021
//  File type: C++ source file
//  Description: Calculate sum of values in between given range from a BST.
//////////////////////////////////////////////////////


#include <iostream>
#include <stack>
#include "../../debug.h"

using namespace std;



/*
 * Idea:
 *	 Use DFS on the BST, sum all values that are in range.
*/



int rangeSumBST(TreeNode* root, int low, int high){
	if (!root) return 0;

	int sum = 0;
	std::stack<TreeNode*> nodes;
	nodes.push(root);

	while (! nodes.empty()){
		TreeNode* n = nodes.top();
		if (n->val >= low && n->val <= high){
			sum += n->val;
		}

		nodes.pop();
		if (n->right && n->val < high) nodes.push(n->right);
		if (n->left && n->val > low) nodes.push(n->left);
	}

	return sum;

}




int main(){
	TreeNode* root = createBinaryTree("18,9,27,6,15,24,30,3,null,12,null,21");
	std::cout << rangeSumBST(root,18,24) << "\n" << std::endl;
	return 0;
}



