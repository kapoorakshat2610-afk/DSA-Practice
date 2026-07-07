void moveZeroes(int* nums, int numsSize) {
    int i;
    int t;
    int j;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=0;j<numsSize-1-i;j++){if(nums[j]==0)
        {
            t=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=t;

        }

        }
    }
    
}