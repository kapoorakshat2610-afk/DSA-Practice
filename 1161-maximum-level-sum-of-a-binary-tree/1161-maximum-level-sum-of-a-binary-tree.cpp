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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            levels.push_back(level);
        }

        int maxSum = INT_MIN;
        int answer = 1;

        for(int i = 0; i < levels.size(); i++) {
            int sum = 0;

            for(int x : levels[i]) {
                sum += x;
            }

            if(sum > maxSum) {
                maxSum = sum;
                answer = i + 1;
            }
        }

        return answer;
    }
};