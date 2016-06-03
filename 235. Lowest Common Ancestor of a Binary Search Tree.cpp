// Leetcode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) 
		{
			if ((p->val < root->val) && (q->val < root->val)) 
			{
				root = root->left;
				continue;
			}
			if ((p->val > root->val) && (q->val > root->val))
			{
				root = root->right  ;
				continue;
			}
			return root; 
		}
		return NULL;
	}
};
int main()
{
	TreeNode *p = new TreeNode(6);
	p->left = new TreeNode(2);
	p->right = new TreeNode(8);
	p->left->left = new TreeNode(0);
	p->left->right = new TreeNode(4);
	p->right->left = new TreeNode(7);
	p->right->right = new TreeNode(9);
	p->left->right->left = new TreeNode(3);
	p->left->right->right = new TreeNode(5);
	std::cout << Solution().lowestCommonAncestor(p, p->left->right, p->left->right->left)->val << endl;
	
			return 0;

}
