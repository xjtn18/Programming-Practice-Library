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
		TreeNode *ptr = root->left;
		while (ptr->right != nullptr){
			ptr = ptr->right;
		}
		ptr->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
}



int main(){
	TreeNode *root = createBinaryTree("1,2,4,3,null");
	dlog(root);
	flatten(root);
	dlog(root);
	return 0;
}



