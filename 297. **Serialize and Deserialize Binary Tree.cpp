class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nodes;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            int n = level.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front(); level.pop();
                nodes.push_back(node ? to_string(node->val) + "," : "null,");
                if (node) {
                    level.push(node->left);
                    level.push(node->right);
                }
            }
        }
        while (!nodes.empty() && nodes.back() == "null,")
            nodes.pop_back();
        string tree;
        for (string node : nodes) tree += node;
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string vs;
        getline(ss, vs, ',');
        TreeNode* root = new TreeNode(stoi(vs));
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            int n = level.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front(); level.pop();
                if (getline(ss, vs, ',') && vs != "null") {
                    node->left = new TreeNode(stoi(vs));
                    level.push(node -> left);
                }
                if (getline(ss, vs, ',') && vs != "null") {
                    node->right = new TreeNode(stoi(vs));
                    level.push(node -> right);
                }
            }
        }
        return root;
    }
};
