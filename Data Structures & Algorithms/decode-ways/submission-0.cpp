class Solution {
   public:
    int solve(string& s, int i, vector<int>& dp) {
        if (i == s.length()) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int one = 0, two = 0;

        if (s[i] != '0') {
            one = solve(s, i + 1, dp);
        }

        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26) {
                two = solve(s, i + 2, dp);
            }
        }

        return dp[i] = one + two;
    }
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n + 1, -1);

        return solve(s, 0, dp);
    }
};
