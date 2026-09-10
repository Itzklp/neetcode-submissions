class Solution {
   public:
    vector<string> ans;
    void solve(int n, int open, int close, string& s) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s += '(';
            solve(n, open + 1, close, s);
            s.pop_back();
        }

        if (close < open) {
            s += ')';
            solve(n, open, close + 1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n, 0, 0, s);

        return ans;
    }
};
