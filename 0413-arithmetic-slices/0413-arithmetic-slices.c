int numberOfArithmeticSlices(int* nums, int numsSize) {
    if(numsSize<3)
    {
        return 0;
    }
    int curr=0;
    int ans=0;
     for (int i = 2; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            curr += 1;        // extend previous slices by 1
            ans += curr;      // add to total count
        } else {
            curr = 0;         // reset current count if no arithmetic slice
        }
    }
    return ans;
}