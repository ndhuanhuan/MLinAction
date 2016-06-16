class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size() != postorder.size()) return NULL;
		int n = inorder.size();
		return buildBT(inorder, postorder, 0, n - 1, 0, n - 1);
	}

	TreeNode *buildBT(vector<int> &inorder, vector<int> &postorder, int s1, int e1, int s2, int e2) {
		if (s1>e1 || s2>e2) return NULL;
		TreeNode *root = new TreeNode(postorder[e2]);
		int rootIndex = -1;
		for (int i = s1; i <= e1; i++) {
			if (inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}
		if (rootIndex == -1) return NULL;
		int leftTreeSize = rootIndex - s1;
		int rightTreeSize = e1 - rootIndex;

		root->left = buildBT(inorder, postorder, s1, rootIndex - 1, s2, s2 + leftTreeSize - 1);
		root->right = buildBT(inorder, postorder, rootIndex + 1, e1, e2 - rightTreeSize, e2 - 1);
		return root;
	}
};
