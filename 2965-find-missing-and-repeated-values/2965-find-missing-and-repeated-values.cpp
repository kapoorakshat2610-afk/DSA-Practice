class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         vector<int> ans;
    unordered_set<int> s;

    int n = grid.size();

    long long actualsum = 0;
    long long expsum = 0;

    int a = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            actualsum += grid[i][j];

            if(s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j];
            }

            s.insert(grid[i][j]);
        }
    }

    expsum = (1LL * n * n * (n * n + 1)) / 2;

    int b = expsum + a - actualsum;

    ans.push_back(a);
    ans.push_back(b);

    return ans;
    }
};