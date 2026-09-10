class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto& [r, c] : directions) {
                int nr = row + r;
                int nc = col + c;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = 1 + grid[row][col];
                q.push({nr, nc});
            }
        }
    }
};
