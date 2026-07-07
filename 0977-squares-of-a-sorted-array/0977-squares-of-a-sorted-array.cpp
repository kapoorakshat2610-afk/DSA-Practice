class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int leftVal = nums[left] * nums[left];
            int rightVal = nums[right] * nums[right];
            if (leftVal > rightVal) {
                ans[pos--] = leftVal;
                left++;
            } else {
                ans[pos--] = rightVal;
                right--;
            }
        }

        return ans;
    }
};
