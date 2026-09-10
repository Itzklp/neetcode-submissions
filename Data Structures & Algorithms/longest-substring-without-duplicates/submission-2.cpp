class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);

        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};