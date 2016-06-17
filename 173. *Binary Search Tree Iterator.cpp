//http://blog.csdn.net/feliciafay/article/details/42341633

class BSTIterator {

private:
    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode *root) {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
            
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());  
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* current = s.top();  
        TreeNode* return_current = current;  
        s.pop();  
        current = current->right;  
        while(current != NULL) {  
            s.push(current);  
            current = current->left;  
        }  
        return return_current->val;
    }
};
