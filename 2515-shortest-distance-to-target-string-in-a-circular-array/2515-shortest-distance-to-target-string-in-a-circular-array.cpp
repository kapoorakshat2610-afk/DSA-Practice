class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
    int minDistance = -1;

    for (int i = 0; i < n; i++) {
        if (words[i] == target) {
            // 1. Calculate the linear distance
            int diff = std::abs(i - startIndex);
            
            // 2. Calculate the circular distance
            int circularDiff = n - diff;
            
            // 3. Find the smaller of the two
            int currentDistance = std::min(diff, circularDiff);
            
            // 4. Update the overall minimum distance
            if (minDistance == -1 || currentDistance < minDistance) {
                minDistance = currentDistance;
            }
        }
    }

    return minDistance;
    }


};