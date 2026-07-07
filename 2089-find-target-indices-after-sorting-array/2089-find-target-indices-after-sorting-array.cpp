class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(nums[mid]==target)
            {
                ans.push_back(mid);
                int left = mid - 1;
            while (left >= 0 && nums[left] == target) {
                ans.push_back(left);
                left--;
            }

           
            int right = mid + 1;
            while (right < n && nums[right] == target) {
                ans.push_back(right);
                right++;
            }
            break;
            }    
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};