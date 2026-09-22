class Solution {
public:
    void getperms(vector<int>&nums,int indx,vector<vector<int>>&ans)
     {
        if(indx==nums.size()){

            ans.push_back({nums});
            return;
        }
         unordered_set<int> used;
        for (int i=indx;i<nums.size();i++)
        {
            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            swap(nums[indx],nums[i]);
            getperms(nums,indx+1,ans);

            swap(nums[indx],nums[i]);
        }

     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
         getperms(nums,0,ans);
         return ans;
    }
};