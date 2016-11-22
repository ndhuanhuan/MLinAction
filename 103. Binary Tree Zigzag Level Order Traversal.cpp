class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traverse(root, 1, result, true);
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result,
		bool left_to_right) {
		if (!root) return;
		if (level > result.size())
			result.push_back(vector<int>());
		if (left_to_right)
			result[level - 1].push_back(root->val);
		else
			result[level - 1].insert(result[level - 1].begin(), root->val);
		traverse(root->left, level + 1, result, !left_to_right);
		traverse(root->right, level + 1, result, !left_to_right);
	}
};



2016/11/22 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeftToRight=true;
        while(!q.empty())
        {
                vector<int> oneLevel;
                int size = q.size();
                for(int i=0;i<size;i++)
                {
                     TreeNode* node = q.front();
                     q.pop();
                     if(isLeftToRight)
                     {
                         oneLevel.push_back(node->val);
                          if (node->left) q.push(node->left);
                          if (node->right) q.push(node->right);
                     }
                    else
                    {
                         oneLevel.insert(oneLevel.begin(),node->val);
                          if (node->left) q.push(node->left);
                          if (node->right) q.push(node->right);
                    }
                }
                 res.push_back(oneLevel);
                isLeftToRight=!isLeftToRight;
                
        }
                
            
           
        
        return res;
        
    }
};
