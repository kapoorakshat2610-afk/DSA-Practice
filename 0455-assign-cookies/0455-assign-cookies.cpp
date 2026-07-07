class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int child_ptr = 0;
    int cookie_ptr = 0;

    while (child_ptr < g.size() && cookie_ptr < s.size()) {
        if (s[cookie_ptr] >= g[child_ptr]) {
            child_ptr++;
        }
        cookie_ptr++;
    }

    return child_ptr;
} 
};