class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 0;

        for (int i : nums) {
            if (!st.count(i - 1)) {
                int current = i;
                int count = 1;

                while (st.count(current + 1)) {
                    current++;
                    count++;
                }

                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};
