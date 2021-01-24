//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/20/2020
//  File type: C++ source file
//  Description: Move all nodes to the right side of binary tree (linked list)
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"

//using namespace std;


void flatten(TreeNode* node){
	if (!node || (!node->left && !node->right)){
		return;
	}

	if (node->left){
		flatten(node->left);
		TreeNode* tmp = node->right;
		node->right = node->left;
		node->left = nullptr;
		TreeNode* curr = node->right;
		while (curr->right){
			curr = curr->right;
		}
		curr->right = tmp;
	}

	if (node->right){
		flatten(node->right);
	}

}



int main(){
	TreeNode* root = createBinaryTree(std::vector<int>{1,2,5,3,4,0,6});
	flatten(root);
	TreeNode* n = root;
	while (n){
		log(n->val);
		n = n->right;
	}
	return 0;
}



