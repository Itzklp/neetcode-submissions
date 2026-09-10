class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxLen = 0;
        int maxFreq = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            mp[s[j]]++;

            maxFreq = max(maxFreq, mp[s[j]]);

            if ((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, (j - i + 1));
        }

        return maxLen;
    }
};
