class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, vector<bool>& pick, vector<int>& tmp) {
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;
        }

        for (int k = 0; k < n; k++) {
            if (!pick[k]) {
                tmp.push_back(nums[k]);
                pick[k] = true;
                solve(nums, n, pick, tmp);
                tmp.pop_back();
                pick[k] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pick(n, false);
        vector<int> tmp;
        solve(nums, n, pick, tmp);

        return ans;
    }
};
