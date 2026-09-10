class Solution {
   public:
    vector<string> digitsToChar = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void solve(string& digits, int i, string tmp) {
        if (i == digits.size()) {
            ans.push_back(tmp);
            return;
        }

        string& st = digitsToChar[digits[i] - '0'];
        for (char c : st) {
            solve(digits, i + 1, tmp + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        solve(digits, 0, "");

        return ans;
    }
};
