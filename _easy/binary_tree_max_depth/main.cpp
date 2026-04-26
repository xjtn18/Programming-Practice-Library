//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/8/22
//  File type: C++ source file
//  Description: Given a binary tree, return it's max depth.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



int dfs(TreeNode *node, int depth){
	if (!node) return depth-1;
	return std::max(dfs(node->left, depth+1), dfs(node->right, depth+1));
}



int maxDepth(TreeNode *root){
	return dfs(root, 1);
}



int main(){
	TreeNode *root = createBinaryTree("3,9,20,15,7");
	dlog(maxDepth(root));

	root = createBinaryTree("3,9,20,null,null,15,7,null,null,null,null,30");
	dlog(maxDepth(root));

	root = createBinaryTree("1");
	dlog(maxDepth(root));

	root = nullptr;
	dlog(maxDepth(root));

	root = createBinaryTree("1,2");
	dlog(maxDepth(root));

	return 0;
}



