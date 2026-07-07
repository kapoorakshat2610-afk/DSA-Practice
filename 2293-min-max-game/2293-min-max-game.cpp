

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            int n = nums.size() / 2;
            vector<int> newNums(n);
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            nums = newNums; // shrink nums
        }
        return nums[0];
    }
};
