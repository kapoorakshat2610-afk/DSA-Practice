

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        int score = maximum - minimum - 2 * k;
        return max(0, score);
    }
};
