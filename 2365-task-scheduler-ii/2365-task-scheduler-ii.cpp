class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n = tasks.size();
    // Optimization: Reserve memory to prevent multiple rehashes
    unordered_map<int, long long> lastDone;
    lastDone.reserve(n); 

    long long currentTime = 0;

    for (int i = 0; i < n; ++i) {
        currentTime++; // Standard increment for the current task
        
        int taskID = tasks[i];
        if (lastDone.find(taskID) != lastDone.end()) {
            long long lastTime = lastDone[taskID];
            // If the required gap hasn't passed, jump currentTime forward
            if (currentTime - lastTime <= space) {
                currentTime = lastTime + space + 1;
            }
        }
        
        // Update the last completion time for this task
        lastDone[taskID] = currentTime;
    }

    return currentTime;
}
};