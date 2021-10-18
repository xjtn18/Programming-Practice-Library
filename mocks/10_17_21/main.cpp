//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 10/17/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


//////////  Problem 1  //////////
// Given a string, return the same string with all vowels swapped.
// TC: Linear
// SC: Constant

bool is_vowel(const char &c){
	return (c == 'a' || c == 'A' ||
			c == 'e' || c == 'E' ||
			c == 'i' || c == 'E' ||
			c == 'o' || c == 'O' ||
			c == 'u' || c == 'U');
}


string reverseVowels(string s){
	int n = s.length();
	int i = 0, j = n - 1;

	while (i < j){
		while (i < n && !is_vowel(s[i])) { ++i; }
		if (i >= j){ return s; }
		while (j >= 0 && !is_vowel(s[j])) { --j; }
		swap(s[i], s[j]);
		++i; --j;
	}

	return s;
}


//////////  Problem 2  //////////
// Given a binary tree, return an array of the largest values in each row of the tree.
// TC: Linear in size of the tree
// SC: Queue will hold at most the size of the largest row in the tree, give or take.

vector<int> largestValues(TreeNode* root){
	vector<int> large;
	queue<TreeNode*> q({root});
	TreeNode *node;

	while (!q.empty()){
		int size = q.size();
		int maxx = q.front()->val;

		while (size--){
			node = q.front();
			q.pop();
			maxx = max(maxx, node->val);
			if (node->left) { q.push(node->left); }
			if (node->right) { q.push(node->right); }
		}
		// we've exhausted the last row
		large.push_back(maxx);
	}

	return large;
}



int main(){
	assert(reverseVowels("hello") == "holle");
	assert(reverseVowels("leetcode") == "leotcede");
	assert(reverseVowels("trty") == "trty");
	assert(reverseVowels("a") == "a");
	assert(reverseVowels("ao") == "oa");
	assert(reverseVowels("aeo") == "oea");

	TreeNode *root;
	vector<int> ans;

	root = createBinaryTree("1,2,3");
	ans = {1,3};
	assert(largestValues(root) == ans);

	root = createBinaryTree("1,3,2,5,3,null,9");
	ans = {1,3,9};
	assert(largestValues(root) == ans);

	return 0;
}



