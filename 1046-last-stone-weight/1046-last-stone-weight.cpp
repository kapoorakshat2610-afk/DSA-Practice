class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

    while(stones.size() > 1)
    {
        sort(stones.begin(), stones.end());

        int n = stones.size();

        int a = stones[n - 2];
        int b = stones[n - 1];

        
        stones.pop_back();
        stones.pop_back();

        
        if(a != b)
        {
            stones.push_back(b - a);
        }
    }

    if(stones.empty())
        return 0;

    return stones[0];
}
};