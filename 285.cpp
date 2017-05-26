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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr)
            return nullptr;
        TreeNode* cur = find(root, p);
        if (cur == nullptr)
            return nullptr;
        if (cur->right != nullptr) {
            TreeNode* tmp = cur->right;
            while (tmp->left != nullptr)
                tmp = tmp->left;
            return tmp;
        } else {
            TreeNode* anc = root, *succ = nullptr;
            while (anc != cur) {
                if (anc->val > cur->val) {
                    succ = anc;
                    anc = anc->left;
                } else {
                    anc = anc->right;
                }
            }
            return succ;
        }
    }
    TreeNode* find(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        if (root->val < p->val)
            return find(root->right, p);
        else if (root->val > p->val)
            return find(root->left, p);
        else
            return root;
    }
};
