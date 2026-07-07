double findMaxAverage(int* nums, int numsSize, int k) {
    int windowSum = 0;

    // Initial sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < numsSize; i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    // Return average as double
    return (double)maxSum / k;
}
