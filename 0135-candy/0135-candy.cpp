class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
    vector<int> cleft(n, 1);
    vector<int> cright(n, 1);
    
    
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) {
            cleft[i] = cleft[i-1] + 1;
        }
    }
    
    
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            cright[i] = cright[i+1] + 1;
        }
    }
    
    
    long total = 0; 
    for (int i = 0; i < n; i++) {
        total += max(cleft[i], cright[i]);
    }
    
    return total;
    }
};