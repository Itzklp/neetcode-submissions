class Solution {
   public:
    bool isSafe(vector<string>& sol, int c, int r, int n) {
        int row = r;
        int col = c;

        while (row >= 0 && col >= 0) {
            if (sol[row][col] == 'Q') {
                return false;
            }

            row--;
            col--;
        }

        row = r;
        col = c;

        while (row < n && col >= 0) {
            if (sol[row][col] == 'Q') {
                return false;
            }

            row++;
            col--;
        }

        row = r;
        col = c;

        while (col >= 0) {
            if (sol[row][col] == 'Q') {
                return false;
            }

            col--;
        }

        return true;
    }
    void queens(vector<vector<string>>& ans, int col, vector<string>& sol, int n) {
        if (col == n) {
            ans.push_back(sol);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(sol, col, i, n)) {
                sol[i][col] = 'Q';
                queens(ans, col + 1, sol, n);
                sol[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sol(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            sol[i] = s;
        }
        queens(ans, 0, sol, n);
        return ans;
    }
};
