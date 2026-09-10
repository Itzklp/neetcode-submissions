class Solution {
   public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int i, int target, int n, int sum, vector<int>& tmp) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }

        if (i == n || sum > target) {
            return;
        }

        tmp.push_back(nums[i]);
        solve(nums, i, target, n, sum + nums[i], tmp);

        tmp.pop_back();
        solve(nums, i + 1, target, n, sum, tmp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        solve(nums, 0, target, nums.size(), 0, tmp);

        return ans;
    }
};