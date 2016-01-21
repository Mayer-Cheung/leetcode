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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode> vec;
        stack<TreeNode> stk;
        stk.push(root);
        while (!stk.empty())
        {
        	TreeNode tmp = stk.top();
        	stk.pop();
        	vec.push_back(tmp.val);
        	if (tmp->right != NULL)
        		stk.push(tmp->right);
        	if (tmp->left != NULL)
        		stk.push(tmp->lef);
        }
        return vec;
    }
};