#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        // Fix 1: Outer loop picks the STARTING point of the subarray
        for (int i = 0; i < n; i++) {
            int sum = 0; // Fix 2: Reset sum for every new starting point

            // Fix 3: Inner loop picks the ENDING point of the subarray
            for (int j = i; j < n; j++) {
                sum += nums[j]; // Add the current element to the running sum

                // If the sum from index i to j equals k, we found one!
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};