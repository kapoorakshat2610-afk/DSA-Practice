class Solution {
public:
bool isvalid(vector<int>& nums,int k,int mid)
{
    int n=nums.size();
    int stu=1;
    int pages=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>mid)
        {
            return false;
        }
        if((pages+nums[i])>mid)
        {
            stu++;
            pages=nums[i];
        }
        else{
             pages+=nums[i];
        }
    }
    return stu<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)
        {
            return -1;
        }
        int start=*max_element(nums.begin(), nums.end());
        int sum=std::accumulate(nums.begin(),nums.end(),0);
        int end=sum;
        int ans=end;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isvalid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};