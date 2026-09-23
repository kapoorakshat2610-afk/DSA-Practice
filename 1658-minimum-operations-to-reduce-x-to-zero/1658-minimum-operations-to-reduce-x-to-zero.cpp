class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int total = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        int target = total - x;

        // If target is negative, impossible
        if(target < 0)
            return -1;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for(int right = 0; right < n; right++) {

            sum += nums[right];

            while(left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No subarray with required sum
        if(maxLen == -1)
            return -1;

        return n - maxLen;
    }
};