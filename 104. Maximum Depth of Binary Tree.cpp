/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// LeetCode, Maximum Depth of Binary Tree
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int lmax = maxDepth(root->left);
        int rmax = maxDepth(root->right);
        return max(lmax, rmax) + 1;
    }
};
