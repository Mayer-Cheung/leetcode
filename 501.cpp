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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        map<int, int> ht;
        inorder(root, ht, mx);
        for (auto a : ht) {
            if (a.second == mx)
                res.push_back(a.first);
        }
        return res;
    }

    void inorder(TreeNode *root, map<int, int>& ht, int& mx) {
        if (root == nullptr)
            return;
        inorder(root->left, ht, mx);
        mx = max(mx, ++ht[root->val]);
        inorder(root->right, ht, mx);
    }
};
