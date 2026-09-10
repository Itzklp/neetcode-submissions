class Solution {
   public:
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
    void solve(string& s, int i, int n, vector<string>& tmp) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        for (int j = i; j < n; j++) {
            if (isPalindrome(s.substr(i, j - i + 1))) {
                tmp.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, n, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> tmp;

        solve(s, 0, n, tmp);

        return ans;
    }
};
