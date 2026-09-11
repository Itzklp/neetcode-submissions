class Solution {
   public:
    int solve(vector<int>& nums, int i, int low, vector<int>& dp) {
        if (i < low) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(solve(nums, i - 1, low, dp), nums[i] + solve(nums, i - 2, low, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        return max(solve(nums, n - 1, 1, dp1), solve(nums, n - 2, 0, dp2));
    }
};
