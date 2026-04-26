//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/8/22
//  File type: C++ source file
//  Description: Given a binary tree, return the level order traversal of that tree.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


#include <queue>



vector<vector<int>> levelOrder(TreeNode* root){
	vector<vector<int>> ordering;

	if (!root) return ordering;

	std::queue<TreeNode*> nodeQueue({root});
	
	while (!nodeQueue.empty()){
		int queueSize = nodeQueue.size();
		vector<int> row;

		while (--queueSize >= 0){
			TreeNode *node = nodeQueue.front();
			nodeQueue.pop();
			row.push_back(node->val);
			if (node->left) nodeQueue.push(node->left);
			if (node->right) nodeQueue.push(node->right);
		}

		ordering.push_back(row);
	}


	return ordering;
}







int main(){
	TreeNode* root = createBinaryTree("3,9,20,null,null,15,7");
	hlog(levelOrder(root));

	return 0;
}



