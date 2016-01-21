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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if (root == NULL)
        	return vec;
        stack<TreeNode*> stk;
        const TreeNode* p = root;
        while (!stk.empty() || p != NULL)
        {
        	if (p != NULL)
        	{
        		stk.push(p);
        		p = p->left;
        	}
        	else
        	{
        		p = stk.top();
        		stk.pop();
        		vec.push_back(p->val);
        		p = p->right;
        	}
        }
        return vec;
    }
};