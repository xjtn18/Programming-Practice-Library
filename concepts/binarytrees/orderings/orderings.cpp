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
	if (!root) return l;
	std::stack<TreeNode*> stack({root});

	while (!stack.empty()){
		TreeNode *curr = stack.top();
		stack.pop();
		if (curr == nullptr) continue;
		l.push_back(curr->val);
		stack.push(curr->right);
		stack.push(curr->left);
	}
	return l;
}


template <typename T>
std::list<T> iterative_inorder(TreeNode *root){
	std::list<T> l;
	if (!root) return l;
	std::stack<TreeNode*> stack;
	TreeNode *curr = root;

	while (curr || !stack.empty()){
		if (curr){
			stack.push(curr);
			curr = curr->left;
		} else { // the stack is not empty
			curr = stack.top();
			l.push_back(curr->val);
			stack.pop();
			curr = curr->right;
		}
	}
	return l;
}


template <typename T>
std::list<T> iterative_postorder(TreeNode *root){
	std::list<T> l;
	if (!root) return l;
	std::stack<TreeNode*> stack({root});
	std::unordered_set<TreeNode*> explored = {nullptr};

	while (!stack.empty()){
		TreeNode *node = stack.top();
		if ((is_in(node->left, explored) && is_in(node->right, explored))){
			l.push_back(node->val);
			explored.insert(node);
			stack.pop();
		}

		if (not_in(node->right, explored)) 	stack.push(node->right);
		if (not_in(node->left, explored)) 	stack.push(node->left);
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



