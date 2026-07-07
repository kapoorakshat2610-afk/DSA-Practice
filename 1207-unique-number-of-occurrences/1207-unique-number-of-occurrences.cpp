class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        
        // Step 1: Count how many times each number appears
        for (int num : arr) {
            counts[num]++;
        }
        
        // Step 2: Use a set to see if any count repeats
        unordered_set<int> uniqueCounts;
        for (auto& pair : counts) {
            int freq = pair.second;
            
            // If the frequency is already in the set, it's not unique!
            if (uniqueCounts.count(freq)) {
                return false;
            }
            uniqueCounts.insert(freq);
        }
        
        return true;
    }
};