class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {

                int count = 0;
                for (int j = i + 1; j < n; j++) {

                    if (nums[j] == 0) {
                        count++;
                    } 
                    else if (nums[j] == 1) {
                        if (count < k) return false;
                        break;
                    }
                }
            }
        }
        return true;
    }
};
