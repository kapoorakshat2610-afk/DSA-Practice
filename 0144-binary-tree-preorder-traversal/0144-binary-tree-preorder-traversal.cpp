/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }

        // Root
        ans.push_back(root->val);

        // Left
        f(root->left, ans);

        // Right
        f(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        f(root, ans);

        return ans;
    }
};