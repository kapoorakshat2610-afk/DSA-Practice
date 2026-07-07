int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int curr = 0;
    int ans = numsSize + 1; // initialize to a large number (impossible length)

    for (int right = 0; right < numsSize; right++) {
        curr += nums[right];

        // shrink the window as long as the current sum is >= target
        while (curr >= target) {
            int windowLen = right - left + 1;
            if (windowLen < ans) {
                ans = windowLen;
            }
            curr -= nums[left];
            left++;
        }
    }

    // if no valid subarray found
    if (ans == numsSize + 1) {
        return 0;
    }

    return ans;
}
