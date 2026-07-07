class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;           
        int minPrefix = INT_MAX;  

        for (int num : nums) {
            prefix += num;
            minPrefix = min(minPrefix, prefix);
        }
        return (minPrefix >= 0) ? 1 : (1 - minPrefix);
    }
};