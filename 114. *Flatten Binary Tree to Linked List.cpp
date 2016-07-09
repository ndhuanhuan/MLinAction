class Solution {
public:
	void flatten(TreeNode *root) {
		if (root == nullptr) return; // 
		flatten(root->left);
		flatten(root->right);
		if (nullptr == root->left) return;
		//  
		TreeNode *p = root->left;
		while (p->right) p = p->right; // 
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
};


class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			auto p = s.top();
			s.pop();
			if (p->right)
				s.push(p->right);
			if (p->left)
				s.push(p->left);
			p->left = nullptr;
			if (!s.empty())
				p->right = s.top();
		}
	}
};
