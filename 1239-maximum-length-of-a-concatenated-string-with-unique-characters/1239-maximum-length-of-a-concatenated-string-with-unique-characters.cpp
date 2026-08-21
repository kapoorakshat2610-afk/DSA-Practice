class Solution {
public:

    int solve(vector<string>& arr, int index, int mask)
    {
        if(index == arr.size())
        {
            return 0;
        }

        // Don't take current string
        int ans = solve(arr, index + 1, mask);

        int newMask = 0;
        bool valid = true;

        // Create mask for current string
        for(char c : arr[index])
        {
            int bit = 1 << (c - 'a');

            // Duplicate character inside current string
            if(newMask & bit)
            {
                valid = false;
                break;
            }

            newMask |= bit;
        }

        // Take current string
        if(valid && (mask & newMask) == 0)
        {
            ans = max(ans,
                      (int)arr[index].size() +
                      solve(arr, index + 1, mask | newMask));
        }

        return ans;
    }

    int maxLength(vector<string>& arr)
    {
        return solve(arr, 0, 0);
    }
};