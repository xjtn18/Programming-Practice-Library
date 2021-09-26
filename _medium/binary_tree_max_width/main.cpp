//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/17/21
//  File type: C++ source file
//  Description: Given a binary tree, find the width of its widest level.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


int widthOfBinaryTree(TreeNode* root) {
	queue<pair<TreeNode*, uint64_t>> q({{root, 0}});
	int width = 0;

	while ( !q.empty() ){
		uint64_t left = q.front().second;
		uint64_t right = 0;
		int size = q.size();

		while (size--) {
			auto node = q.front();

			if (node.first->left)
				q.push({node.first->left, 2 * node.second + 1});

			if (node.first->right)
				q.push({node.first->right, 2 * node.second + 2});

			right = node.second;
			q.pop();
		}

		width = max(width, int(right - left + 1));
	}

	return width;
}



int main(){
	TreeNode* root;


	root = createBinaryTree("1,3,2,5,3,null,9");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,null,5,3");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,2,5");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,2,5,null,null,null,7,8");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,2");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,2,5,4,null,9,7,8");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,2,5,null,null,9,6,null,null,null,null,null,null,7");
	dlog( widthOfBinaryTree(root) );

	root = createBinaryTree("1,3,2,5,null,null,9");
	dlog( widthOfBinaryTree(root) );


	return 0;
}



