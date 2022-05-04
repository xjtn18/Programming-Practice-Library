//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



void flatten(TreeNode *root){
	if (root == nullptr){ return; }

	if (root->right){
		flatten(root->right);
	}

	if (root->left){
		flatten(root->left);
		TreeNode *right = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right) root = root->right;
		root->right = right;
	}
}



int main(){
	TreeNode *root = createBinaryTree("1,2,4,3,null");
	dlog(root);
	flatten(root);
	dlog(root);
	return 0;
}



