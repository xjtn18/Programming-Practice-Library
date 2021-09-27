//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


#define say cout <<
#define shut << endl



TreeNode* trimBST(TreeNode* root, int low, int high) {
	if (!root) return nullptr;

	if (root->val < low){
		return trimBST(root->right, low, high);
	} else if (root->val > high){
		return trimBST(root->left, low, high);
	} else {
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
	}
	return root;
}


int main(){
	TreeNode *root;

	root = createBinaryTree("1,0,2");
	dlog(root);
	dlog( trimBST(root, 1, 2) );


	root = createBinaryTree("3,0,4,null,2,null,null,null,null,1");
	dlog(root);
	dlog ( trimBST(root, 1, 3) );

	root = createBinaryTree("3,1,4,null,3,null,null,null,null,2");
	dlog(root);
	dlog ( trimBST(root, 0, 0) );


	return 0;
}



