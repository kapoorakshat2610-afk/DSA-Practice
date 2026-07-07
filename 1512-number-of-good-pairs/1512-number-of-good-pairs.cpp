class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int i;
        int j;
        int count=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j]&&i<j)
                {
                    count++;
                }
            }
        }
        return count;
    }
};