class Solution {
   public:
    bool checkAns(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> freq1(26, 0), freq2(26, 0);

        if (n > m) {
            return false;
        }

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < n; j++) {
            freq2[s2[j] - 'a']++;
        }

        if (checkAns(freq1, freq2)) {
            return true;
        }

        for (int j = n; j < m; j++) {
            freq2[s2[i] - 'a']--;
            i++;
            freq2[s2[j] - 'a']++;

            if (checkAns(freq1, freq2)) {
                return true;
            }
        }

        return false;
    }
};
