class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currsum=1;
        int maxsum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            currsum*=nums[i];
            maxsum=max(currsum,maxsum);
            if(currsum==0)
            {
                currsum=1;
            }
        }
        currsum=1;
        for(int i=n-1;i>=0;i--)
        {
            currsum*=nums[i];
            maxsum=max(currsum,maxsum);
            if(currsum==0)
            {
                currsum=1;
            }
        }
        return maxsum;
        
    }
};