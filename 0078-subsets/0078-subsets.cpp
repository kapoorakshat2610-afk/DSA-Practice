class Solution {
public:

    void getallsubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allsubsets) {
        
        if(i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include nums[i]
        ans.push_back(nums[i]);
        getallsubsets(nums, ans, i + 1, allsubsets);

        // Backtrack
        ans.pop_back();

        // Don't include nums[i]
        getallsubsets(nums, ans, i + 1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};