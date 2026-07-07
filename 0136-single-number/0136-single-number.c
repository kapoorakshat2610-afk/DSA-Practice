int singleNumber(int* nums, int numsSize) {
    int i;
    int j;
    int k;
    for(i=0;i<numsSize;i++)
    {
        int d=0;
        for(j=0;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                d++;
            }
        }
        if(d==1)
        {
            return nums[i];
        }
    }
    return -1;
}   
        