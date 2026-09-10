class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int i, int n, int sum, int target, vector<int>& tmp) {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }

        if (i == n || sum > target) {
            return;
        }

        tmp.push_back(candidates[i]);
        solve(candidates, i + 1, n, sum + candidates[i], target, tmp);
        tmp.pop_back();

        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            i++;
        }
        solve(candidates, i + 1, n, sum, target, tmp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;

        solve(candidates, 0, n, 0, target, tmp);
        return ans;
    }
};
