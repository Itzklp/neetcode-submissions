class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < n; j++) {
            while (st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            maxLen = max(maxLen, (j - i + 1));
        }

        return maxLen;
    }
};
