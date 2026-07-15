class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> freq;
        for(int num : candyType)
        {
            freq.insert(num);
        }
        int m=freq.size();
        return min(n/2,m);
    }
};