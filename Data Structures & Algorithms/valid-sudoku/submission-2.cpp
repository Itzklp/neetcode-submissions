class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, char c) {
        for (int ind = 0; ind < 9; ind++) {
            if (ind != j && board[i][ind] == c) {
                return false;
            }

            if (ind != i && board[ind][j] == c) {
                return false;
            }

            int row = 3 * (i / 3) + ind / 3;
            int col = 3 * (j / 3) + ind % 3;
            if ((row != i || col != j) && board[row][col] == c) {
                return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isSafe(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
