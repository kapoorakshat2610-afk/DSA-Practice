int thirdMax(int* nums, int numsSize){
    int i, j;

    // Bubble sort (descending order)
    for(i = 0; i < numsSize - 1; i++) {
        for(j = 0; j < numsSize - 1 - i; j++) {
            if(nums[j] < nums[j + 1]) {
                int t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }
        }
    }

    // Return third distinct maximum if it exists
    int count = 1, third = nums[0];
    for(i = 1; i < numsSize; i++) {
        if(nums[i] != nums[i - 1]) {
            count++;
            if(count == 3) {
                return nums[i];
            }
        }
    }

    // If less than 3 distinct numbers, return the maximum
    return nums[0];
}
