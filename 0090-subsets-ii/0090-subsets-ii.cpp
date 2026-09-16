class Solution {
public:
    void getallsubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allsubsets) {

        if(i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Take nums[i]
        ans.push_back(nums[i]);
        getallsubsets(nums, ans, i + 1, allsubsets);

        // Backtrack
        ans.pop_back();

        // Don't take nums[i]
        int indx = i + 1;

        while(indx < nums.size() && nums[indx] == nums[i]) {
            indx++;
        }

        getallsubsets(nums, ans, indx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};