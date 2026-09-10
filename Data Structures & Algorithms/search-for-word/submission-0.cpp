class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int i,
             vector<vector<bool>>& visited) {
        if (i == word.length()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] != word[i] || visited[row][col]) {
            return false;
        }

        visited[row][col] = true;
        bool possible = dfs(board, word, row + 1, col, i + 1, visited) ||
                        dfs(board, word, row, col + 1, i + 1, visited) ||
                        dfs(board, word, row - 1, col, i + 1, visited) ||
                        dfs(board, word, row, col - 1, i + 1, visited);
        visited[row][col] = false;

        return possible;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
