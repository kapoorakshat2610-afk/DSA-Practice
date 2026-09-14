class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int leftSum = 0;
        int rightSum = 0;

        // Calculate total sum
        for(int x : nums) {
            rightSum += x;
        }

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            
            // Remove current element from right side
            rightSum -= nums[i];

            // Difference between left and right
            ans.push_back(abs(leftSum - rightSum));

            // Add current element to left side
            leftSum += nums[i];
        }

        return ans;
    }
};