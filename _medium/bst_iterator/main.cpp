//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 6/7/22
//  File type: C++ source file
//  Description: A class that represents an iterator to a inorder BST.
//////////////////////////////////////////////////////


#include <mystd.h>
#include <stack>
using namespace std;


class BSTIterator {
    std::stack<TreeNode*> stk;
    TreeNode *curr;


public:
    BSTIterator(TreeNode* root) : curr(root)
    {}

    
    int next() {
        // Given problem description, next will only be
        //  called when there is a next node to explore.

        if (curr){
            while (curr->left){
                stk.push(curr);
                curr = curr->left;
            }
        } else {
            curr = stk.top();
            stk.pop();
        }

        return std::exchange(curr, curr->right)->val;
    }


    bool hasNext() {
        return (!stk.empty() || curr);
    }
};



int main(){
    TreeNode *root = createBinaryTree("7,3,15,null,null,9,20");
    BSTIterator it(root);

    dlog(it.next()); // 3
    dlog(it.next()); // 7
    it.hasNext(); // true
    dlog(it.next()); // 9
    it.hasNext(); // true
    dlog(it.next()); // 15
    it.hasNext(); // true
    dlog(it.next()); // 20
    it.hasNext(); // false

	return 0;
}



