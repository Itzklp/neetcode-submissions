class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, int n, vector<int>& tmp) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        solve(nums, i + 1, n, tmp);
        tmp.pop_back();

        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(nums, i + 1, n, tmp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp;

        solve(nums, 0, n, tmp);

        return ans;
    }
};
