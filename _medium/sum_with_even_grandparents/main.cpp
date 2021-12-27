//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/16/21
//  File type: C++ source file
//  Description: Given a tree, return a sum of the nodes that have even grandparents.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// Solution
//
//	The sum of nodes given a root node is the sum of itself (if it has an even grandparent)
//	plus the full sum of root->left plus the full sum of root->right.
//	We create a helper function that recursively calls itself with 2 exta variables 'p' and
//	'gp'. Every recursive call, we bind 'p' to the current value of the node, and we bind
//	'gp' to the current parent of the node we are on (stored in 'p').
//	This effectively shifts the meaning of parent and grandparent upward as we traverse 
//	down the tree.
//
// TC: Linear in the size of the tree
// SC: 2n where n is the number of nodes
//


int solve(TreeNode *node, int p, int gp){
	if (!node) return 0;
	return (gp % 2 == 0) * node->val \
						+ solve(node->left, node->val, p) \
						+ solve(node->right, node->val, p);
}
 
 
int sumEvenGrandparent(TreeNode* root) {
	return solve(root, 1, 1); // just call it with odd values
}


int main(){
	auto tree = createBinaryTree("6,7,8,2,7,1,3");
	cout << sumEvenGrandparent(tree) << endl;

	return 0;
}



