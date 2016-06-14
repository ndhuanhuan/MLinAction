class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, (long long int)INT_MIN-1,(long long int)INT_MAX+1);
        }
        bool isValidBST(TreeNode* root, long long int lower, long long int upper) {
            if (root == nullptr) return true;
            //if(root!=nullptr&&root->left==nullptr&&root->right==nullptr) return true;
            return root->val > lower && root->val < upper&& isValidBST(root->left, lower, root->val)&& isValidBST(root->right, root->val, upper);
        }
};
