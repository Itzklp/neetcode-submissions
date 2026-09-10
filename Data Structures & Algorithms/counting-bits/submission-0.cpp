class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int tmp = i;
            while (tmp) {
                ans[i]++;
                tmp &= (tmp - 1);
            }
        }

        return ans;
    }
};
