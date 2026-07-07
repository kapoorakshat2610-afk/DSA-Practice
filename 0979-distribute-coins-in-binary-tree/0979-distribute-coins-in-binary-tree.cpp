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
    int moves = 0; 
public:
    int distributeCoins(TreeNode* root) {
        moves = 0; 
        traverse(root);
        return moves;
    }

    int traverse(TreeNode* root) {
        if (root == NULL) return 0;

       
        int l = traverse(root->left);
        int r = traverse(root->right);

        
        moves += abs(l) + abs(r);

       
        return root->val + l + r - 1;
    }
};