class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1); 
    
    vector<int> st1; 
    vector<int> st2; 
    

    for (int i = 0; i < n; i++) {
        
        while (!st2.empty() && nums[st2.back()] < nums[i]) {
            ans[st2.back()] = nums[i];
            st2.pop_back();
        }

        
        int temp_index = st1.size();
        while (temp_index > 0 && nums[st1[temp_index - 1]] < nums[i]) {
            temp_index--;
        }

        
        st2.insert(st2.end(), st1.begin() + temp_index, st1.end());
        st1.erase(st1.begin() + temp_index, st1.end());

        
        st1.push_back(i);
    }

    return ans;
    }
};