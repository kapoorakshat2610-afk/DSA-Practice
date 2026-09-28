class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>& arr,int indx, int target,vector<vector<int>>&ans,vector<int>&combin){
           int n=arr.size();
           if(indx==n||target<0)
           {
            return;
           }
           if(target==0)
           {
            if(s.find(combin)==s.end())
            {
            ans.push_back(combin);
            s.insert(combin);
            return;
            }
           }
           combin.push_back(arr[indx]);
           helper(arr,indx+1,target-arr[indx],ans,combin);
           helper(arr,indx,target-arr[indx],ans,combin);
           combin.pop_back();
           helper(arr,indx+1,target,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>combin;
        helper(arr,0,target,ans,combin);
        return ans;
    }
};