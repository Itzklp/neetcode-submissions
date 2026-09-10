class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, int n, vector<int> tmp) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        solve(nums, i + 1, n, tmp);
        tmp.pop_back();
        solve(nums, i + 1, n, tmp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;

        solve(nums, 0, n, tmp);
        return ans;
    }
};
