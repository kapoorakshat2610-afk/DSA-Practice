class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        for(int x : nums)
        {
            st.insert(x);
        }

        int i = 1;

        while(true)
        {
            int multiple = k * i;

            if(st.find(multiple) == st.end())
            {
                return multiple;
            }

            i++;
        }
    }
};