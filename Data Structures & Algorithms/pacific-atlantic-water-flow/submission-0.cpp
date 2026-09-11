class Solution {
   public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& [r, c] : directions) {
            int nr = i + r;
            int nc = j + c;

            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() &&
                !visited[nr][nc] && heights[nr][nc] >= heights[i][j]) {
                dfs(heights, nr, nc, visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, pac);
            dfs(heights, m - 1, i, atl);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pac);
            dfs(heights, i, n - 1, atl);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
