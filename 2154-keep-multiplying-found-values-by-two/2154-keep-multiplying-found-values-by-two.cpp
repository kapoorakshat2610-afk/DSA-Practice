class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==original)
            {
                nums[i]*=2;
                original=nums[i];
            }
        }
         
                return original;
            
    }
};