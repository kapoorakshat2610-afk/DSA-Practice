int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if(k<=1){
        return 0;
    }
    int ans=0;
    int curr=1;
    int left=0;
    for(int right=0;right<numsSize;right++)
    {
        curr=curr*nums[right];
        while(curr>=k)
        {
            curr=curr/nums[left];
            left++;
        }
        ans+=right-left+1;
    }
    return ans;
}