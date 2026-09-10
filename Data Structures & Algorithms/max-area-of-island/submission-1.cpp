class Solution {
   public:
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<int>>& grid, int row, int col, int& size, int m, int n) {
        size++;
        grid[row][col] = 0;

        for (auto& [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                dfs(grid, nr, nc, size, m, n);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = 0;
                    dfs(grid, i, j, size, m, n);
                    maxArea = max(maxArea, size);
                }
            }
        }

        return maxArea;
    }
};
