class Solution {
public:
    int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return -1; // Need at least 3 elements for a tuple

    long long minTotalDist = -1; // Use -1 to represent "not found"

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) { 
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) { 
                        
                        
                        int currentDist = 2 * (k - i);
                        
                        if (minTotalDist == -1 || currentDist < minTotalDist) {
                            minTotalDist = currentDist;
                        }
                    }
                }
            }
        }
    }

    return (int)minTotalDist;
    }
};