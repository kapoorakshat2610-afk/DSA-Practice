#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // Use a vector for prefix sums to handle memory automatically
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Standard deque for the monotonic queue approach
        deque<int> dq;
        int minLen = n + 1;

        for (int i = 0; i <= n; i++) {
            // 1. Check if the current sum window meets the requirement k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }

            // 2. Maintain increasing order in the deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (minLen <= n) ? minLen : -1;
    }
};