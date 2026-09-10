class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> count(1001, 0);
        vector<int> ans;

        // Count frequency of every element in arr1
        for(int x : arr1) {
            count[x]++;
        }

        // First put elements according to arr2 order
        for(int x : arr2) {
            while(count[x] > 0) {
                ans.push_back(x);
                count[x]--;
            }
        }

        // Remaining elements in ascending order
        for(int x = 0; x <= 1000; x++) {
            while(count[x] > 0) {
                ans.push_back(x);
                count[x]--;
            }
        }

        return ans;
    }
};