class Solution {
   public:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if (n >= cost.size()) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = cost[n] + min(solve(cost, n + 1, dp), solve(cost, n + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, -1);

        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};
