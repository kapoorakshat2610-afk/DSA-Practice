int subarraysDivByK(int* nums, int numsSize, int k) {
    int count = 0;
    int prefixSum = 0;
    int modCount[10000] = {0};  // assuming k is not too large
    modCount[0] = 1; // to handle prefixSum % k == 0

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        int mod = ((prefixSum % k) + k) % k; // handle negative mods
        count += modCount[mod];
        modCount[mod]++;
    }

    return count;
}
