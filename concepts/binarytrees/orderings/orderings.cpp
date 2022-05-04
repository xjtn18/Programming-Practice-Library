//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: The recursive and iterative solutions to the 3 ordered traversals of binary tree.
//////////////////////////////////////////////////////


#include <mystd.h>
#include <unordered_set>
#include <stack>
#include <cassert>



// PREORDER : Parent, Left, Right
// INORDER  : Left, Parent, Right
// POSTORDER: Left, Right, Parent


enum Order {
	PREORDER = 0,
	INORDER,
	POSTORDER
};



////////////  Recursive Solution /////////////
template <typename T>
std::list<T> recursive_ordering(TreeNode *root, Order order){
	//
	// This function takes a binary tree, an element type, and an Order (pre, in, post) and
	// recursively creates a list of the trees nodes in the order specified.
	//
	std::list<T> l;
	if (!root) return l;

	typedef std::function<void(void)> VoidFunc;

	VoidFunc parent = [&](){
		l.push_back(root->val);
	};

	VoidFunc leftchild = [&](){
		auto left_list = recursive_ordering<int>(root->left, order);
		std_extend(l, left_list);
	};

	VoidFunc rightchild = [&](){
		auto right_list = recursive_ordering<int>(root->right, order);
		std_extend(l, right_list);
	};

	switch(order){
		case PREORDER:
			for (auto& f : {parent, leftchild, rightchild}) {f();}
			break;
		case INORDER:
			for (auto& f : {leftchild, parent, rightchild}) {f();}
			break;
		case POSTORDER:
			for (auto& f : {leftchild, rightchild, parent}) {f();}
			break;
	}

	return l;
}



////////////  Iterative Solutions /////////////
template <typename T>
std::list<T> iterative_preorder(TreeNode *root){
	std::list<T> l;
	std::stack<TreeNode*> stk({root});

	while (!stk.empty()){
		root = stk.top();
		stk.pop();
		l.push_back(root->val);
		if (root->right) stk.push(root->right);
		if (root->left) stk.push(root->left);
	}

	return l;
}


template <typename T>
std::list<T> iterative_inorder(TreeNode *root){
	std::list<T> l;
	std::stack<TreeNode*> stk;

	while (root || !stk.empty()){
		if (root){
			stk.push(root);
			root = root->left;
		} else {
			root = stk.top();
			stk.pop();
			l.push_back(root->val);
			root = root->right;
		}
	}

	return l;
}


template <typename T>
std::list<T> iterative_postorder(TreeNode *root){
	std::list<T> l;
	std::stack<TreeNode*> stk;
	TreeNode *pre = nullptr;

	while (root || !stk.empty()){
		if (root){
			stk.push(root);
			root = root->left;

		} else {
			root = stk.top();
			if (!root->right || root->right == pre){
				stk.pop();
				l.push_back(root->val);
				pre = root;
				root = nullptr;
			} else {
				root = root->right;
			}
		}
	}

	return l;
}



void test_correctness(TreeNode *root){
	// recursive ordering is trivial and is surely correct. This mainly tests the correctness of the iterative solutions.
	assert(recursive_ordering<int>(root, PREORDER) == iterative_preorder<int>(root));
	assert(recursive_ordering<int>(root, INORDER) == iterative_inorder<int>(root));
	assert(recursive_ordering<int>(root, POSTORDER) == iterative_postorder<int>(root));
	dlog("All procedures successful.");
}



int main(){
	TreeNode *root = createBinaryTree("1,2,3,4,5,null,7,8,9");
	test_correctness(root); // will throw assertion error if any of the orderings yeilds incorrect

	return 0;
}



