
//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-maximum-path-sum.html
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ps1_root = findMaxPathSum(root, maxSum);
        return maxSum;
    }
    
    int findMaxPathSum(TreeNode *root, int &maxSum) 
    {
        if(!root) return 0;
        int ps1_left = 0, ps1_right = 0;
        if(root->left) 
            ps1_left = max(findMaxPathSum(root->left,maxSum),0);
        if(root->right)
            ps1_right = max(findMaxPathSum(root->right,maxSum),0);
        
        int ps1_root = max(ps1_left, ps1_right) + root->val;    
        int ps2_root = ps1_left + ps1_right + root->val;
        maxSum = max(maxSum,max(ps1_root, ps2_root));
        
        return ps1_root;
    }
};
