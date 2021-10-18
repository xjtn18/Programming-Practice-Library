//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


// TC:
// O(m + n)
//
// SC:
// worst case O(m + n)



bool leafSimilar(TreeNode *root1, TreeNode *root2){
	stack<TreeNode*> q1({root1});
	stack<TreeNode*> q2({root2});
	TreeNode *n1, *n2;

	while (q1.size() && q2.size()){
		do {
			n1 = q1.top();
			q1.pop();
			if (n1->right) q1.push(n1->right);
			if (n1->left) q1.push(n1->left);
		} while (n1->left || n1->right); // find the next leaf of root2

		do {
			n2 = q2.top();
			q2.pop();
			if (n2->right) q2.push(n2->right);
			if (n2->left) q2.push(n2->left);
		} while (n2->left || n2->right); // find the next leaf of root2

		if (n1->val != n2->val){
			return false;
		}
	}

	return q1.empty() && q2.empty();
}



int main(){

	TreeNode *root1, *root2;

	//[3,5,1,6,2,9,8,null,null,7,4]
	//[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
	root1 = createBinaryTree("3,5,1,6,2,9,8,null,null,7,4");
	root2 = createBinaryTree("3,5,1,6,7,4,2,null,null,null,null,null,null,9,8");
	dlog(root1);
	dlog(root2);
	dlog(leafSimilar(root1, root2));


	return 0;
}



