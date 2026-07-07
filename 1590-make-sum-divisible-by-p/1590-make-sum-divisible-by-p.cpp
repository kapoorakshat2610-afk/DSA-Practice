class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;
        for (int x : nums) totalSum = (totalSum + x) % p;

        // If the total sum is already divisible by p, we remove 0 elements.
        int target = totalSum % p;
        if (target == 0) return 0;

        // We use a map to keep track of the 'prefix' remainders we've seen.
        // This is the "count" logic you started, but tracking positions instead.
        unordered_map<int, int> lastSeen;
        lastSeen[0] = -1; 
        
        int currentPrefix = 0;
        int minLength = n;

        for (int i = 0; i < n; i++) {
            // Your prefix logic: update the running sum (modulo p)
            currentPrefix = (currentPrefix + nums[i]) % p;

            // Instead of prefix > p, we check if we've seen a prefix 
            // that "cancels out" the target remainder.
            int needed = (currentPrefix - target + p) % p;

            if (lastSeen.count(needed)) {
                // We found a subarray! Update the minimum length.
                minLength = min(minLength, i - lastSeen[needed]);
            }

            // Store the current prefix position for future steps.
            lastSeen[currentPrefix] = i;
        }

        // If minLength is still n, it means we'd have to remove the whole array.
        return (minLength >= n) ? -1 : minLength;
    }
};