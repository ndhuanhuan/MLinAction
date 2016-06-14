//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-inorder-traversal.html

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTrav(root,result);
        return result;
        
    }
    void inorderTrav(TreeNode *root,vector<int> &result)
    {
        if(!root) return;
        inorderTrav(root->left,result);
        result.push_back(root->val);
        inorderTrav(root->right,result);
    }
};



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur = root;
        stack<TreeNode*> s;
        while(cur||!s.empty())
        {
            if(!cur)
            {
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                s.push(cur);
                cur = cur->left;
            }
        }
        return result;

    }

};
