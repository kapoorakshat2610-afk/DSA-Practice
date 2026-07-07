class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
            int n=nums.size();
            if(n<=1)
            {
                return nums;
            }
            for(int pass=0;pass<n;pass++)
            {
                for(int i=0;i<n-1;i++)
                {
                    if(nums[i]%2!=0&&nums[i+1]%2==0)
                    {
                        int t=nums[i];
                        nums[i]=nums[i+1];
                        nums[i+1]=t;
                    }
            }    
        }
        return nums;
    }
};