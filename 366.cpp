/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        help(root, res);
        return res;
    }

    int help(TreeNode* root, vector<vector<int>>& res) {
        if (root == nullptr)
            return 0;
        int depth = 1 + max(help(root->left, res), help(root->right, res));
        if (depth >= res.size())
            res.resize(depth + 1);
        res.push_back(root->val);
        return depth;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root != nullptr) {
            vector<int> tmp;
            root = remove(root, tmp);
            res.push_back(tmp);
        }
        return res;
    }

    TreeNode* remove(TreeNode* root, vector<int>& tmp) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            tmp.push_back(root->val);
            return root = nullptr;
        }
        root->left = remove(root->left, tmp);
        root->right = remove(root->right, tmp);
        return root;
    }
};
