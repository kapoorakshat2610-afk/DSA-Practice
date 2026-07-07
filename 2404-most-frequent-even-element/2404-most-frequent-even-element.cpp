class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int>even;
        for(int val:nums)
        {
            if(val%2==0)
            {
                even.push_back(val);
            }
        }
        if (even.empty()) return -1;
         sort(even.begin(), even.end()); 
         int ans = even[0];
        int maxFreq = 1;
        int currFreq = 1;

        for (int i = 1; i < (int)even.size(); i++) {
            if (even[i] == even[i - 1]) {
                currFreq++;
            } else {
                if (currFreq > maxFreq) {
                    maxFreq = currFreq;
                    ans = even[i - 1];
                }
                currFreq = 1; // reset
            }
        }

        if (currFreq > maxFreq) {
            ans = even.back();
        }

        return ans;
    }
};