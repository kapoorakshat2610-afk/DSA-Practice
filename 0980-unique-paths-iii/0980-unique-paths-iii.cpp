class Solution {
public:
    void helper(vector<vector<int>>& mat, int r, int c,
                int path, int total, int& ans) {

        int n = mat.size();
        int m = mat[0].size();

        // Out of bounds or obstacle/already visited
        if(r < 0 || c < 0 || r >= n || c >= m || mat[r][c] == -1)
            return;

        // Reached ending point
        if(mat[r][c] == 2) {
            if(path == total)
                ans++;

            return;
        }

        // Mark current cell visited
        mat[r][c] = -1;

        helper(mat, r + 1, c, path + 1, total, ans);
        helper(mat, r - 1, c, path + 1, total, ans);
        helper(mat, r, c + 1, path + 1, total, ans);
        helper(mat, r, c - 1, path + 1, total, ans);

        // Backtrack
        mat[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int sr = 0, sc = 0;
        int total = 0;

        // Find starting point and count all non-obstacle cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] != -1)
                    total++;

                if(grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }

        int ans = 0;

        // Start with path = 1 because starting cell is already visited
        helper(grid, sr, sc, 1, total, ans);

        return ans;
    }
};