//https://segmentfault.com/a/1190000003509399
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p||root==q) return root;   //I missed this line last time. Parent to child relation.
        TreeNode *L = lowestCommonAncestor(root->left,p,q);
        TreeNode *R = lowestCommonAncestor(root->right,p,q);
        if(L&&R) return root;
        return L? L:R;
    }
};
