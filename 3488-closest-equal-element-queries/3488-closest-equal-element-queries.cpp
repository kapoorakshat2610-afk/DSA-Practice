class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int m = nums.size();
    int n = queries.size();
    vector<int> ans;
    ans.reserve(n);

    // Step 1: Store all indices for each value
    unordered_map<int, vector<int>> posMap;
    for (int i = 0; i < m; i++) {
        posMap[nums[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        int targetIdx = queries[i];
        int val = nums[targetIdx];
        const vector<int>& positions = posMap[val];

        // If the value only appears once, there's no "other" index j
        if (positions.size() <= 1) {
            ans.push_back(-1);
            continue;
        }

        // Step 2: Find the position of targetIdx in our sorted indices list
        auto it = lower_bound(positions.begin(), positions.end(), targetIdx);
        int posInList = distance(positions.begin(), it);

        // Step 3: Check immediate neighbors in the sorted list
        // In a circular array, the "nearest" must be one of the adjacent indices 
        // in the sorted positions list (including the wrap-around neighbors).
        
        int min_dist = m; // Initialize with max possible distance
        int numMatches = positions.size();

        // Indices of neighbors in the 'positions' vector
        int prevIdxInList = (posInList - 1 + numMatches) % numMatches;
        int nextIdxInList = (posInList + 1) % numMatches;

        int neighbors[] = {positions[prevIdxInList], positions[nextIdxInList]};

        for (int j_idx : neighbors) {
            if (j_idx == targetIdx) continue;
            
            int abs_diff = abs(targetIdx - j_idx);
            // Circular distance formula: min(|i-j|, m - |i-j|)
            int circular_dist = min(abs_diff, m - abs_diff);
            min_dist = min(min_dist, circular_dist);
        }

        ans.push_back(min_dist);
    }
    return ans;
    }
};