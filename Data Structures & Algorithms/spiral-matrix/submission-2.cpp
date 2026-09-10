class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if (matrix.empty() || matrix[0].empty())
            return ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = m - 1;

        while (left <= right && up <= down) {

            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[up][col]);
            }
            up++;

            for (int row = up; row <= down; row++) {
                ans.push_back(matrix[row][right]);
            }
            right--;

            if (up <= down) {
                for (int col = right; col >= left; col--) {
                    ans.push_back(matrix[down][col]);
                }
                down--;
            }

            if (left <= right) {
                for (int row = down; row >= up; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return ans;
    }
};